#include <stdio.h>

int bitcount(long x)
{
    int biti;
    for (biti = 0;x;x=x>>1)
        if(x&1)biti++;
    return biti;
}


int main()
{
    long x;
    scanf("%ld",&x);
    printf("%ld",bitcount(x));
}
