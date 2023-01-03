#include <stdio.h>

int main()
{
   int num[] = {1,4,8,12,16};
   int *a, *b;
   int i;
   a = num;
   b= num+2;
   i=*a+1;
   printf("%d, %d, %d",i,*a,*b);
}