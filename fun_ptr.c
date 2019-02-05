#include<stdio.h>
void f1(int a)
{
        printf("in f1..%d\n",a);
}
void f2(int a)
{
        printf("in f2..%d\n",a);
}
void f3(int a)
{
        printf("in f3..%d\n",a);
}


int main()
{
        void (*pf[])(int)={f1,f2,f3};
int i=0;
        while(i<3)
        {
                pf[i](i);
                i++;
        }
}
