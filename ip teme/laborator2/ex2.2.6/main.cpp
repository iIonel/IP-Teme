#include<iostream>
using namespace std;
int acker(int n,int m)
{
    if(m == 0) return n + 1;
    if(n == 0 && m > 0) return acker(m -1,1);
    return acker(m -1,acker(m,n-1));
}

int main()
{
    int n,m;
    cin >> n >> m;
    cout << acker(n,m);
}
