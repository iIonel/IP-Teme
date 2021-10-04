#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector <int> transformare(vector<int> a,unsigned int x)
{
    while(x)
    {
        a.push_back(x&1);
        x>>=1;
    }
    reverse(a.begin(),a.end());
    return a;
}
int main()
{
    unsigned int x;
    cin >> x;
    vector<int> transformat;
    transformat = transformare(transformat,x);
    for (int i = 0; i < transformat.size();++i)
        cout << transformat[i];
}
