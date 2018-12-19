/* code- Rotate array left by no_rotn*/

#include<stdio.h>
#include<stdlib.h>

void print_arr( int * ptr,int size);

void l_rotate(int *ptr,int size)
{
  int temp=0,i;
    temp=ptr[0];
    for(i=0;i<size-1;i++)
    {
      ptr[i]=ptr[i+1];
    }
    ptr[i]=temp;
    no_rotn--;


}
void rotate_arr(int size,int no_rotn)
{
  int *ptr, i,temp=0;
  ptr=(int *)malloc(sizeof(int)*size);

  for(i=0;i<size;i++)
  {
    puts("enter element\n");
    scanf("%d",&ptr[i]);
  }

  if(no_rotn>size)
    no_rotn=no_rotn-size;
  while(no_rotn)
  {
    l_rotate(ptr,size);
  }

  puts("after rotation\n");

  print_arr(ptr,size);
  free(ptr);
}

void print_arr( int * ptr,int size)
{
  int i;
  for(i=0;i<size;i++)
  {
    printf("%d\n",ptr[i]);
  }

}

int main()
{
  int size,no_rotn;
  puts("Enter size of array\n");
  scanf("%d",&size);
  puts("Enter no odf rotations\n");
  scanf("%d",&no_rotn);
  if(no_rotn<0)
  {
    printf(" enter posive no.");
  exit(0);
  }
    rotate_arr(size,no_rotn);
}
