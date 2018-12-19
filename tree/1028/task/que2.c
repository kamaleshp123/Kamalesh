/*2: Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. Then print the respective minimum and maximum values as a single line of two space-separated long integers

For example, arr=[1,3,5,7,9]
.
Our minimum sum is 1+3+5+7=16
 and our maximum sum is 3+5+7+9=24
 .
 We would print 16 24

 function prototype should be:
     void funName(int arr_count,int * arr);*/



#include<stdio.h>

void sum_(int arr_count, int * arr)
{
   int i,j;
    int sum1=0,temp,sum2=0;
  for(i=0;i<arr_count-1;i++)
  {
    for(j=0;j<arr_count-1-i;j++)
    {
      if(arr[j]>arr[j+1]){
        temp=arr[j];
      arr[j]=arr[j+1];
      arr[j+1]=temp;
      }
  }
  }

  for(i=0;i<arr_count;i++)
  {
    printf("%d ",arr[i]);
  }

    for(i=1;i<arr_count;i++)
    {
      sum1=sum1+arr[i];
    }
printf("***%d\n",sum1);
    for(i=0;i<arr_count-1;i++)
    {
      sum2=sum2+arr[i];
    }
printf("**%d\n",sum2);
}

int main()
{
  int i;
 int arr[5]={2,3,4,1,7};
int cnt=sizeof(arr)/sizeof(int);
sum_(cnt,arr);
  for(i=0;i<cnt;i++)
  {
    printf("%d ",arr[i]);
  }
}
