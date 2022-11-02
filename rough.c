#include <stdio.h>

int main()
{
    char *s = "hackerearth";
    char *p = s+2;
    printf("%c\t%c",*p,s[1]);
    return 0;
}