#include <iostream>
#include <graphics.h>
#include<math.h>
using namespace std;

struct punct{
int x,y;
}m;

void triunghi(punct a, punct b, punct c)
{
    setcolor(rand()%15 + 1);
    line(a.x, a.y, b.x, b.y);
    line(a.x, a.y, c.x, c.y);
    line(b.x, b.y, c.x, c.y);
}

void figura(punct a, punct b, punct c, int numar)
{

    if(numar)
    {
        punct d,e,f;
        triunghi(a,b,c);
        d.x = (a.x + b.x)/2;
        d.y = (a.y + b.y)/2;
        e.x = (a.x + c.x)/2;
        e.y = (a.y + c.y)/2;
        f.x = (b.x + c.x)/2;
        f.y = (b.y + c.y)/2;
        figura(a,d,e,numar-1);
        figura(b,d,f,numar-1);
        figura(c,e,f,numar-1);
    }
}

int main()
{
    initwindow(1000,1000);
    punct a,b,c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    int numar;
    cin >> numar;
    figura(a,b,c,numar);
    getch();
}
