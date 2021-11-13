#include <iostream>
using namespace std;

struct nod{
    int data;
    nod *stanga;
    nod *dreapta;
};

void creare(nod *&n, int x)
{
    if(x != 0)
    {
        n = new nod;
        n ->data = x;
        n ->stanga = NULL;
        n ->dreapta = n ->stanga;
        int val;
        cout << "in stanga lui "<< x << " este:";
        cin >> val;
        creare(n->stanga,val);
        cout << "in dreapta lui " << x << " este:";
        cin >> val;
        creare(n->dreapta,val);
    }
}

void afisare(nod *n,bool existastanga,bool existadreapta)
{
    if(n != NULL)
    {
        if(n ->stanga != NULL)
            existastanga = true;
        if(n ->dreapta != NULL)
            existadreapta = true;
        cout << n->data;

        if(existastanga)
        {
            cout << "(";
            afisare(n->stanga,false,false);
            cout << ")";
        }

        if(existadreapta)
        {
            cout << "(";
            afisare(n->dreapta,false,false);
            cout << ")";
        }
    }
}



int main()
{
    nod *arbore = NULL;
    int x;
    cin >> x;
    creare(arbore,x);
    afisare(arbore,false,false);
}
