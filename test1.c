#include<stdio.h>

typedef union
{
  struct{
  int a;
  int b;
  }s;

}t;


main()
{

  t arr[4];
  arr[0].s.a=50;
  arr[0].s.b=100;
  t *ptr;
  ptr=arr;

  printf(" a=%d",ptr[0].s.b);

ptr[0].s.a=89;
  printf(" a=%d",ptr[0].s.a);

}
