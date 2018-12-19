#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* screenData( void *filename );

int main(int argc, char *argv[])
{
    pthread_t thread;
      char *filename = "some_directory/some_other/";
        /*your code was passing a pthread_t** instead of pthread_t* */
        if( pthread_create( &thread, NULL, screenData, (void*)filename)  != 0)
            {
                  return 0;
                    }

          pthread_join( thread, NULL);
            return 0;
}

void* screenData( void *filename )
{
    char* name;
      if(filename)
          {
                name = (char*)filename;
                    /*check your format specifier*/
                    printf("In SD=%s, %x\n", name, name );
                      }
        return 0;
}
