#include <iostream>
#include <cstring>
using namespace std;

int main(){
  char lista[101][101];
  int poz = 0;
  int n;
  int litere_max = 0;
  cin >> n;
  while(n--)
  {
    char sir[101];
    cin.getline(sir,100);
    strcpy(lista[poz++],sir);
  }
  for(int i = 0; i < poz; ++i)
    if(litere_max < strlen(lista[i]))
      litere_max = strlen(lista[i]);
  for(int i = 0; i < poz; ++i)
  {
    int dif = litere_max - strlen(lista[i]);
    for(int j = 0; j < dif; ++j)
      cout << ' ';
    cout << lista[i] << '\n';
  }
}
