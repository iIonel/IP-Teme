#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int div = 2;
    int putere = 0;
    while(n % div == 0)
    {
        n /= div;
        putere++;
    }

    if(putere) cout << div << " la puterea " << putere << "\n";
    div = 3;
    while(n > 1)
    {
        putere = 0;
        while(n % div == 0)
        {
            n /= div;
            putere++;
        }
        if(putere) cout << div << " la puterea " << putere << "\n";
        div+=2;
    }
}
