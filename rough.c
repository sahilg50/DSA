#include <stdio.h>

int main(int argc, char const *argv[])
{
   int *ptr;
   int num = 0;
   ptr = &num;
   ptr++;
   num = (int)(long long)ptr;
   printf("%d\n", num);
   return 0;
}