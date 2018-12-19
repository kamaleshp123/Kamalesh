/*************************************************************/
//for make use make eg.1 TEST=test1
//                  eg.2 TEST=test2
//                  eg.3 TEST=test3

//for execute program ./test
/**************************************************************/
#include<stdio.h>
#include<stdlib.h>
int main()
{

#ifdef test1 
  printf("test1\n");
 #endif
#ifdef test2
 printf("test2\n");
#endif

#ifdef test3
    printf("test3");
#endif

}

