#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int rezultat = 0;
    while(n)
    {
        n/=2;
        if(n>=1)
            rezultat++;
    }
    cout << rezultat;
}
