#include "apue.h"
#include <pthread.h>
#include <sys/types.h>      /* some systems still require this */
#include <sys/stat.h>
#include <sys/termios.h>    /* for winsize */
#include <sys/ioctl.h>
#include <stdio.h>      /* for convenience */
#include <stdlib.h>     /* for convenience */
#include <stddef.h>     /* for offsetof */
#include <string.h>     /* for convenience */
#include <unistd.h>     /* for convenience */
#include <signal.h>     /* for convenience */


int         quitflag;   /* set nonzero by thread */
sigset_t    mask;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t wait = PTHREAD_COND_INITIALIZER;

  void *
thr_fn(void *arg)
{
  int err, signo;

  for (;;) {
    err = sigwait(&mask, &signo);
    if (err != 0)
  puts("sigwait failed");
    switch (signo) {
      case SIGINT:
        printf("\ninterrupt\n");
        break;

      case SIGQUIT:
        pthread_mutex_lock(&lock);
        quitflag = 1;
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&wait);
        return(0);

      default:
        printf("unexpected signal %d\n", signo);
        exit(1);
    }
  }
}
  int
main(void)
{
  int         err;
  sigset_t    oldmask;
  pthread_t   tid;

  sigemptyset(&mask);
  sigaddset(&mask, SIGINT);
  sigaddset(&mask, SIGQUIT);
  if ((err = pthread_sigmask(SIG_BLOCK, &mask, &oldmask)) != 0)
    puts("SIG_BLOCK error");

  err = pthread_create(&tid, NULL, thr_fn, 0);
  if (err != 0)
   puts("can't create thread");

  pthread_mutex_lock(&lock);
  while (quitflag == 0)
    pthread_cond_wait(&wait, &lock);
  pthread_mutex_unlock(&lock);

  /* SIGQUIT has been caught and is now blocked; do whatever */
  quitflag = 0;

  /* reset signal mask which unblocks SIGQUIT */
  if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
puts("SIG_SETMASK error");
  exit(0);
}
