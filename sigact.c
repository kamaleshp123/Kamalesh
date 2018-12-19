#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>


pthread_mutex_t mutex;

void handler(int id) {
  pthread_t self = pthread_self();
  pthread_mutex_lock(&mutex);
  printf("[handler] caught signal%d\n ",id);
printf(", my tid is %d", syscall(SYS_gettid));
  pthread_mutex_unlock(&mutex);
}

void assignHandler() {
  struct sigaction sa;
  sa.sa_handler = handler;
  sigfillset(&sa.sa_mask);
  sigaction(SIGINT, &sa, NULL);
  sigaction(SIGHUP, &sa, NULL);
  sigaction(SIGTERM, &sa, NULL);
}

void* printMessage(void* ptr) {
  assignHandler();

  while(1) {
    pthread_mutex_lock(&mutex);
  printf( "my tid is%d\n ", syscall(SYS_gettid));
 printf( ", my message is %s",ptr);
    pthread_mutex_unlock(&mutex);
    sleep(3);
  }
}

int main() {
printf( "main thread pid is%d\n ",getpid());
printf(" waiting for child threads end\n");

  pthread_t thread1, thread2;
  const char *message1 = "War";
  const char *message2 = "Piece";

  if (pthread_create(&thread1, NULL, printMessage, (void*)message1)) {
   perror( "Error on thread1 creation\n");
    exit(1);
  }

  if (pthread_create(&thread1, NULL, printMessage, (void*)message2)) {
    pthread_kill(thread1, SIGTERM);
   perror( "Error on thread1 creation\n");
    exit(1);
  }

  // waith threads to end
      pthread_join(thread1, NULL);
          pthread_join(thread2, NULL);
 
puts("xiting from main thread\n");
                  return 0;
                  }
