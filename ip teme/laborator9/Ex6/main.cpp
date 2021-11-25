#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define width 800
#define height 800

struct imagine{
    int latime,lungime;
    int linii,coloane;
    struct matrice{
        int x1,y1,x2,y2;
        int culoare;
    }m[11][11];
};
int imax,jmax;

void save(imagine&x)
{
    FILE *fl=fopen("fisier","wb");
    fwrite(&x,sizeof(x),1,fl);
    fclose(fl);
}

void read(imagine&x)
{
    FILE *fl=fopen("fisier","rb");
    fread(&x,sizeof(x),1,fl);
    fclose(fl);
}

void desenplansa(int lungimemax,int latimemaxx, int lungime, int latime)
{
    for(int i = 0; i <= latimemaxx; i += latime)
        imax++;
    for(int i = 0; i <= lungimemax; i += lungime)
        jmax++;
}

void creareMatrice(imagine&x)
{
    x.latime = 800/x.linii;
    x.lungime= 800/x.coloane;
    int coordi1 = 0;
    int coordi2 = x.lungime;
    int coordj1 = 0;
    int coordj2 = x.latime;
    desenplansa(800,800,x.lungime,x.latime);
    for(int i = 1; i <= imax; ++i)
    {
        coordi1 = 0;
        coordi2 = x.lungime;
        for(int j = 1; j <= jmax; ++j)
        {
            x.m[i][j] = {coordi1,coordj1,coordi2,coordj2,rand()%16};
            coordi1 += x.lungime;
            coordi2 += x.lungime;
        }
        coordj1 += x.latime;
        coordj2 += x.latime;
    }
}

void genereaza(imagine&x)
{
    srand(time(NULL));
    x.linii = rand()%10;
    x.coloane = rand()%10;
    creareMatrice(x);
}

void desen(imagine&x)
{
    for(int i = 1; i <= imax; ++i)
        for(int j = 1; j <= jmax; ++j)
        {
            line(x.m[i][j].x1,x.m[i][j].y1,x.m[i][j].x2,x.m[i][j].y1);
            line(x.m[i][j].x1,x.m[i][j].y1,x.m[i][j].x1,x.m[i][j].y2);
            line(x.m[i][j].x1,x.m[i][j].y2,x.m[i][j].x2,x.m[i][j].y2);
            line(x.m[i][j].x2,x.m[i][j].y1,x.m[i][j].x2,x.m[i][j].y2);
        }
    for(int i = 1; i <= imax; ++i)
        for(int j = 1; j <= jmax; ++j)
        {
            for(int i = x.m[i][j].x1; i <= x.m[i][j].x2 -1 ; ++i)
                for(int j = x.m[i][j].y1; j <= x.m[i][j].y2-1; ++j)
                {
                    putpixel(i,j,x.m[i][j].culoare);
                }
        }
}

int main()
{
    imagine img;
    genereaza(img);
    save(img),read(img);
    initwindow(800,800,"imagine");
    desen(img);
    getch();
}
