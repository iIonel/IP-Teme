#include <stdio.h>

int bitzero(long x)
{
    int biti;
    for(biti = 0, x, x = x >> 1)
        if(x & 1) return biti;
        else biti++;
}
int bitone(long x)
{
    int biti;
    for(biti = 0 ,x, x = x >> 1)
        if(x & 1) biti++;
    return biti;
}

int main()
{
    long x;
    scanf("%ld", &x);
    if(bitzero(x) == bitone(x))
        printf("este");
    else
        printf("nu este");

}
