#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct st
{
        int data;
        int l;
}q;

int d2z(int n)
{
        int i,j=1,k;
        q *a=(q*)malloc(sizeof(q));
        a[0].data =n;
        a[0].l =0;
        if(n==1)
                return 1;
        for(i=0;a[i].data;i++)
        {
                a=(q*)realloc(a,(j+1)*sizeof(q));

                a[j].data=a[i].data-1;
                a[j].l=a[i].l+1;
                if(a[j].data==1)
                        return(a[j].l+1);
                j++;

                for(k=2;k<=sqrt(a[i].data);k++)
                {
                        if(a[i].data%k==0)
                        { 
                                a=(q*)realloc(a,(j+1)*sizeof(q));
                                a[j].data=a[i].data/k;
                                a[j].l=a[i].l+1;

                                if(a[j].data==1)
                                        return(a[j].l+1);
                                j++;

                        }
                }
        }
        return(a[j].l);
}




int main()
{
        int n,cnt;
        scanf("%d",&n);
        cnt=d2z(n);
        printf("level %d\n",cnt);
}

