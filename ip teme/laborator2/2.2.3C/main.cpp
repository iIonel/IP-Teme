#include <iostream>
using namespace std;

#define limita 101
#define ll long long
ll matrice[limita][limita];
bool acoperit[limita][limita];
int n;

void Citire()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> matrice[i][j];
}

bool valid(int x,int y)
{
    if(x >= 1 && x <= n && y >= 1 && y <= n && !acoperit[x][y]) return true;
    return false;
}

void Afisare()
{
    int i = 1, j = 1;
    int poz = 0;
    cout << matrice[i][j] << " ";
    cout << matrice[i][++j] << " ";
    acoperit[i][j] = 1;
    acoperit[i][j - 1] = 1;
    while(i != n ||j != n)
    {   //am luat toate cazurile aferente posibile
        if(i == 1 && j != n)
            if(valid(i + 1, j - 1))
                while(j > 1) cout << matrice[++i][--j] << " " ,acoperit[i][j] = 1;
            else cout << matrice[i][++j] << " ",acoperit[i][j] = 1;
        else if(i == 1 && j == n)
            if(valid(i + 1,j - 1))
                while(j > 1) cout << matrice[++i][--j] << " ",acoperit[i][j] = 1;
            else cout << matrice[++i][j] << " ",acoperit[i][j] = 1;
        else if(j == 1 && i != n)
            if(valid(i - 1,j + 1))
                while(i > 1) cout << matrice[--i][++j] << " ",acoperit[i][j] = 1;
            else cout << matrice[++i][j] << " ",acoperit[i][j] = 1;
        else if(j == 1 && i == n)
            if(valid(i - 1,j + 1))
                while(i > 1) cout << matrice[--i][++j] << " ",acoperit[i][j] = 1;
             else cout << matrice[i][++j] << " ",acoperit[i][j] = 1;
        else if(i == n && j != 1)
            if(valid(i - 1,j + 1))
                while(j < n) cout << matrice[--i][++j] << " ", acoperit[i][j] = 1;
            else cout << matrice[i][++j] << " ",acoperit[i][j] = 1;
        else if(j == n && i != 1)
            if(valid(i + 1,j - 1))
                while(i < n) cout << matrice[++i][--j] << " ", acoperit[i][j] = 1;
            else cout << matrice[++i][j] << " ",acoperit[i][j] = 1;
    }


}

int main()
{
   Citire(),Afisare();
}

