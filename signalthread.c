#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <errno.h>

#define mySig 41
#define THREADS 25

struct thread_data  //// structure for thread and semaphore

{
    int thread_id;
    int sem_id;
};


/**************************************************************/



int sem_id;
int gloThreadId = 0; //global thred id


/* 
 * gotta put this in per semctl man page
 */


//#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
/* union semun is defined by including <sys/sem.h> */

//#else
/* according to X/OPEN we have to define it ourselves */

union semun {
  int val;                    /* value for SETVAL */
struct semid_ds *buf;       /* buffer for IPC_STAT, IPC_SET */
  unsigned short int *array;  /* array for GETALL, SETALL */
 struct seminfo *__buf;      /* buffer for IPC_INFO */
};
//ndif

void mySigHandle(int i)
{
    printf("Thread %d: Hi\n", gloThreadId);
}

void request_sem(int semid, int i)
{
    struct sembuf sbuf;
    
    sbuf.sem_num= 0;
    sbuf.sem_op = -1;
    sbuf.sem_flg = SEM_UNDO;
    printf("Thread %d requesting lock\n", i);
    semop(semid, &sbuf, 1);
}

void release_sem(int semid, int i)
{
    struct sembuf sbuf;
    
    sbuf.sem_num = 0;
    sbuf.sem_op = 1;
    sbuf.sem_flg = SEM_UNDO;
    printf("Thread %d releasing lock\n", i);
    semop(semid, &sbuf, 1);
}
    
/* function to be executed by the new thread */
void* do_loop(void* data)
{
    int i;                      /* counter, to print numbers */
    int j;                      /* counter, for delay        */
    int me = (*(struct thread_data*)data).thread_id;     /* thread identifying number */
    int semid = (*(struct thread_data*)data).sem_id;	/* semaphore id number */

    printf("Thread %d starting up!\n", me);

    request_sem(semid, me); 
    gloThreadId = me;     
    kill(getpid(), mySig);
    release_sem(semid, me);

    for (i=0; i<10; i++) 
    {
	sleep(1);
        printf("Thread me='%d'i = '%d'\n", me, i);
    }

    /* terminate the thread */
    pthread_exit(NULL);
}

struct pthread_stuff
{
    int thread_id;
    pthread_t p_thread;
} pthread_array[50];

/************************************************************************************/


int main(int argc, char* argv[])
{
    union semun sun;

    struct thread_data tdata;
    int i;

    /* create a semaphore */
    tdata.sem_id = semget(IPC_PRIVATE, 1, SHM_R | SHM_W);

    if(tdata.sem_id != 1)
    {

      /* set resource to 1 */
	sun.val = 1;

	if( semctl(tdata.sem_id, 0, SETVAL, sun) == -1 )
	{
	    printf("bailing out: semctl() failed [%s]\n", strerror(errno));
	    exit(2);
	}
    }
    else
    {
	printf("bailing out: semget() problems [%s]\n", strerror(errno));
    }
	
    signal(mySig, mySigHandle);

    for( i = 1; i <= THREADS; i++ )
    {
	printf("i = %d\n", i);
	/* fixup tdata for thread 1 */
	tdata.thread_id = i;
	/* create a new thread that will execute 'do_loop()' */
	pthread_array[i].thread_id = pthread_create(&pthread_array[i].p_thread, NULL, do_loop, (void*)&tdata);

	if( pthread_array[i].thread_id != 0 )
	{
	    printf("Thread not created! %d\n", i);
	}
    }

    /* fixup tdata for thread 2; could be done in a for loop for multiple threads*/
    tdata.thread_id = i++;
    /* run 'do_loop()' in the main thread as well */
    do_loop((void*)&tdata);
    
    /* clean up after ourselves */
    semctl(tdata.sem_id, 0, IPC_RMID, 0);
    return 0;
}
