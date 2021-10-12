#include <iostream>
using namespace std;

bool prim(int n)
{
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i+=2)
        if(n % i == 0) return false;
    return true;
}

int oglindit(int n)
{
    int m  = 0;
    while(n)
    {
        m = m * 10 + n % 10;
        n /= 10;
    }
    return m;
}

int main()
{
    for(int i = 1000; i <= 9999; ++i)
    {
        if(prim(i) && prim(oglindit(i)))
            cout << i << " ";
    }
}
