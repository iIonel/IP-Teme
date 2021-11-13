#include <iostream>
#include <queue>
using namespace std;

struct nod{
    int data;
    nod*stanga;
    nod*dreapta;
};

int s;

void creare(nod*&n,int x)
{
    if(x)
    {
       n = new nod;
       n->data = x;
       n->stanga = n->dreapta = NULL;
       int val;
       cout << "stanga lui " << x << " este: ";
       cin >> val;
       creare(n->stanga,val);
       cout << "dreapta lui " << x << " este: ";
       cin >> val;
       creare(n->dreapta,val);
    }
}

bool areCaleSuma(nod*&n,int suma)
{
    if(n != NULL)
    {
      s += n->data;
      if(s == suma && n->stanga==NULL && n->dreapta==NULL) return true;
      areCaleSuma(n->stanga,suma);
      areCaleSuma(n->dreapta,suma);
      s -= n->data;
    }
}

int main()
{
    nod*radacina = NULL;
    int x;
    cout << "radacina: ";
    cin >> x;
    creare(radacina,x);
    int suma;
    cin >> suma;
    if(areCaleSuma(radacina,suma)) cout << "EXISTA FRATE";
    else cout << "NU EXISTA FRATE";
}
