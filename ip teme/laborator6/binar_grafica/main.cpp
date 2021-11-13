#include <iostream>
#include <graphics.h>
using namespace std;

struct nod{
    int data;
    nod *stanga;
    nod *dreapta;
};

void creare(nod*&n,int x)
{
    if(x!=0)
    {
        n = new nod;
        n->data = x;
        n->stanga = n->dreapta = NULL;
        int val;
        cout << "stanga lui " << x << " este: ";
        cin >> val;
        cout << '\n';
        creare(n->stanga,val);
        cout << "dreapta lui " << x << " este: ";
        cin >> val;
        cout << '\n';
        creare(n->dreapta,val);
    }
}

void desen_linie(int x1,int y1,int x2,int y2)
{
    setcolor(LIGHTGREEN);
    line(x1,y1,x2,y2);
    setcolor(WHITE);
}

void desen_nod(int element,int x,int y)
{
    bgiout << element;
    outstreamxy(x,y);
    circle(x,y,25);
}

void afisare(nod *n,bool existastanga, bool existadreapta, int x,int y)
{
    if(n != NULL)
    {
        cout << n->data << ' ';
        desen_nod(n->data,x,y);
        if(n->dreapta != NULL)
            existadreapta = true;
        if(n->stanga != NULL)
            existastanga = true;
        desen_nod(n->data,x,y);
        if(existastanga)
        {
            desen_linie(x-20,y+20,x-30,y+30);
            x -= 50;
            y += 50;
            afisare(n->stanga,false,false,x,y);
            x += 50;
            y -= 50;
        }
        if(existadreapta)
        {
            desen_linie(x+20,y+20,x+30,y+30);
            x += 50;
            y += 50;
            afisare(n->dreapta,false,false,x,y);
            x -= 50;
            y -= 50;
        }
    }
}

int main()
{
    initwindow(1000,1000,"grafica arbore binar");
    nod *radacina = NULL;
    cout << "Radacina arborelui este: ";
    int x;
    cin >> x;
    cout << '\n';
    creare(radacina,x);
    afisare(radacina,false,false,500,50);
    getch();
}
