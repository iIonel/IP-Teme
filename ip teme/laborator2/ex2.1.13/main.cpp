#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int suma = 0;
    for (int i = 1; i * i <= n; ++i)
    {
        if(n % i == 0)
            if(i*i == 0) suma += i;
            else suma += (i + n/i);
    }
    cout << suma;
}
