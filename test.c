#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

void *function_count1();
void *function_count2();

int count = 1;

int main()
{
      pthread_t thread1, thread2;
          int ret;

              if( (ret=pthread_create( &thread1, NULL, &function_count1, "thread1")) )
                    {
                              printf("Thread 1 creation failed: %d\n", ret);
                                      exit (EXIT_FAILURE);
                                          }

                  if( (ret=pthread_create( &thread2, NULL, &function_count2, "thread2")) )
                        {
                                  printf("Thread 2 creation failed: %d\n", ret);
                                          exit (EXIT_FAILURE);
                                              }

                      pthread_join( thread1, NULL);
                          pthread_join( thread2, NULL);

                              exit(EXIT_SUCCESS);
}

void *function_count1(void *arg)
{
      while(count <= 10)
            {
                      pthread_mutex_lock( &count_mutex );
                              if (count % 2 != 0)
                                        {
                                                      pthread_cond_wait(&condition_var, &count_mutex);
                                                                  printf("%s : counter = %d\n", (char *)arg, count++);
                                                                          }
                                      else
                                                {
                                                              pthread_cond_signal(&condition_var);
                                                                      }
                                              pthread_mutex_unlock( &count_mutex );
                                                  }
}

void *function_count2(void *arg)
{
      while(count <= 10)
            {
                      pthread_mutex_lock( &count_mutex );

                              if (count % 2 == 0)
                                        {
                                                      pthread_cond_wait(&condition_var, &count_mutex);
                                                                  printf("%s : counter = %d\n", (char *)arg, count++);
                                                                          }
                                      else
                                                {
                                                              pthread_cond_signal(&condition_var);
                                                                      }
                                              pthread_mutex_unlock(&count_mutex);
                                                  }
}
