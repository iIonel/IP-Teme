#include <stdio.h>

int NumarBiti(long x)
{
    int biti;
    for(biti = 0;x;x=x>>1)
        if(x&1) return biti;
        else biti++;
}
int main()
{
    long x;
    scanf("%ld",&x);
    printf("%ld",NumarBiti(x));
}
