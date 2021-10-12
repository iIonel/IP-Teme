#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin >> n;
    int numar = n;
    while(numar)
    {
        m = m * 10 + numar % 10;
        numar = numar / 10;
    }
    if(m == n) cout << "da";
    else cout << "nu";

}

