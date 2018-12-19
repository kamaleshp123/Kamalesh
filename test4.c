#include<stdio.h>
inline void fun( int a);
 inline void fun( int a)
{
  printf("%d",a);
}

int main()
{
  int n=50;
  fun(n);
}
