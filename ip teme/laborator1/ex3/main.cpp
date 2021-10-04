#include <stdio.h>

int main()
{
    long x;
    scanf("%ld",&x);
    if(x&1) printf("este impar");
    else printf("este par");
}
