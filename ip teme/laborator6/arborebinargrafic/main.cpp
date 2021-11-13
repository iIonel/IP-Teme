#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

struct nod{
    int data;
    nod *stanga;
    nod *dreapta;
    int coloana = 0;
    int linie;
    int centrux;
    int centruy;
};

struct matrice{
    int i1,j1,i2,j2;
}m[101][101];

int noduri;
int indicei=1,indicej=1;
int lungime,latime;
int imax,jmax;
int l = 0;
int col = 0;

int calculinaltime(nod*&n)
{
    if(n == NULL)
        return 0;
    return 1 + max(calculinaltime(n->stanga),calculinaltime(n->dreapta));
}

void numarnoduri(nod *&n)
{
    if(n != NULL)
    {
        noduri++;
        numarnoduri(n->stanga);
        numarnoduri(n->dreapta);
    }
}

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

void desen_sageataS(int x,int y)
{
    desen_linie(x,y,x+20,y);
    int lungime = 20;
    int z = sqrt(300);
    desen_linie(x,y,x-10,y-z);

}
void desen_sageataD(int x,int y)
{
    desen_linie(x,y,x-20,y);
    int lungime = 20;
    int z = sqrt(300);
    desen_linie(x,y,x+10,y-z);
}

void afisare(nod *n,bool existastanga, bool existadreapta)
{
    if(n != NULL)
    {
        cout << n->data << ' ' << n->linie << ' ' << n->coloana << endl;
        n->centrux = (m[n->linie][n->coloana].i1 + m[n->linie][n->coloana].i2)/2;
        n->centruy = (m[n->linie][n->coloana].j1 + m[n->linie][n->coloana].j2)/2;
        int x = n->centrux;
        int y = n->centruy;
        desen_nod(n->data,n->centrux,n->centruy);
        if(n->dreapta != NULL)
            existadreapta = true;
        if(n->stanga != NULL)
            existastanga = true;
        desen_nod(n->data,n->centrux,n->centruy);
        if(existastanga)
        {
            int distanta = n->coloana - n->stanga->coloana;
            int finalx = x-distanta * lungime - 7;
            int finaly = y+latime - 24;
            desen_linie(x-20,y+20,finalx,finaly);
            desen_sageataS(finalx,finaly);
            x -= lungime;
            y += latime;
            afisare(n->stanga,false,false);
            x += lungime;
            y -= latime;
        }
        if(existadreapta)
        {
            int distanta = n->dreapta->coloana - n->coloana;
            int finalx = x+distanta * lungime + 1;
            int finaly = y+latime - 25;
            desen_linie(x+20,y+20,finalx,finaly);
            desen_sageataD(finalx,finaly);
            x += lungime;
            y += latime;
            afisare(n->dreapta,false,false);
            x -= lungime;
            y -= latime;
        }
    }
}
void desenplansa(int lungimemax,int latimemaxx, int lungime, int latime)
{
    for(int i = 0; i <= latimemaxx; i += latime)
        imax++;
    for(int i = 0; i <= lungimemax; i += lungime)
        jmax++;
}
void coordonatematrice()
{
    int coordi1 = 0;
    int coordi2 = lungime;
    int coordj1 = 0;
    int coordj2 = latime;
    for(int i = 1; i <= imax; ++i)
    {
        coordi1 = 0;
        coordi2 = lungime;
        for(int j = 1; j <= jmax; ++j)
        {
            m[i][j] = {coordi1,coordj1,coordi2,coordj2};
            coordi1 += lungime;
            coordi2 += lungime;
        }
        coordj1 += latime;
        coordj2 += latime;
    }
    cout << endl;
    for(int i = 1; i <= imax; ++i)
    {
        for(int j = 1; j <= jmax; ++j)
            cout << m[i][j].i1 << " " << m[i][j].j1 << " " << m[i][j].i2 << " " << m[i][j].j2 << endl;
        cout << endl;
    }
}

void parcurgere_linii(nod*&n,int l)
{
    if(n != NULL)
    {
        n->linie = l;
        parcurgere_linii(n->stanga,l + 1);
        parcurgere_linii(n->dreapta,l + 1);
    }
}

void parcurgere_coloane(nod*&n)
{
    if(n != NULL)
    {
        parcurgere_coloane(n->stanga);
        n->coloana = ++col;
        parcurgere_coloane(n->dreapta);
    }
}

int main()
{
    initwindow(800,800,"grafica arbore binar");
    nod *radacina = NULL;
    cout << "Radacina arborelui este: ";
    int x;
    cin >> x;
    cout << '\n';
    creare(radacina,x);
    cout << endl << calculinaltime(radacina);
    numarnoduri(radacina);
    cout << endl << noduri;
    lungime = 800/noduri;
    int inaltime = calculinaltime(radacina);
    latime = 800/inaltime;
    desenplansa(800,800,lungime,latime);
    coordonatematrice();
    parcurgere_linii(radacina,1);
    parcurgere_coloane(radacina);
    afisare(radacina,false,false);
    getch();
}
