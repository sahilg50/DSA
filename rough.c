#include <stdio.h>
main()
{
    int i = 0;
    printf("hi\n");
    fork();
    printf("hello\n");
    fork();
    printf("amazon");
}