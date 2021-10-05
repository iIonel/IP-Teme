#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int PrimaParte = 1;
    int numar = 1;
    int spatiere = (n-1)*2;
    while(PrimaParte <= n)
    {
        for(int i = 1; i <= spatiere; ++i)
            cout << " ";
        for(int i = numar; i >= 1; --i)
        {
            cout << i;
            if(i == 1)
                break;
            cout << "   ";
        }
        for(int i = 1; i <= spatiere; ++i)
            cout << " ";
        spatiere-=2;
        cout << "\n";
        PrimaParte++;
        numar++;
    }
    spatiere = 2;
    PrimaParte = n-1;
    while(PrimaParte >= 1)
    {
        for(int i = 1; i <= spatiere; ++i)
            cout << " ";
        for(int i = PrimaParte; i >= 1; --i)
        {
            cout << i;
            if(i == 1)
                break;
            cout << "   ";
        }
        for(int i = 1;i <= spatiere; ++i)
            cout << " ";
        spatiere+=2;
        cout << "\n";
        PrimaParte--;
    }

}
