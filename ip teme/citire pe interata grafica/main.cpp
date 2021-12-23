#include <iostream>
#include <graphics.h>
#include <winbgim.h>
using namespace std;

#define MAX_STR 256

void CitesteSir(int x, int y, char mesaj[MAX_STR], char S[MAX_STR] )
{
    char Enter = 13; char BackSpace = 8; char Escape = 27; char s2[2]; s2[1]='\0';
    char MultimeDeCaractereAcceptabile[MAX_STR]="0123456789abcdefghijklmnopqrstuvwxyz~!`@#$%+-^&*/\\()_=[],;.?<>:;{} ";
    char S_initial[MAX_STR]; char tasta; char S_[MAX_STR]; char mesaj_[MAX_STR];
    strcpy(mesaj_,mesaj);
    strcpy(S_initial,S); settextstyle(DEFAULT_FONT,HORIZ_DIR,2); setcolor(WHITE);
    settextjustify(0,0); outtextxy(x,y,mesaj_);
    x=x+textwidth(mesaj);strcpy(S,"");
    strcpy(S_,S); strcat(S_,"_");
    setcolor(BLACK); outtextxy(x,y,S_);
    s2[0]=tasta; strcat(S,s2); strcpy(S_,S); strcat(S_,"_");
    setcolor(WHITE); outtextxy(x,y,S_);

    do {
        tasta=getch();
        if (tasta==0) { tasta=getch(); Beep(1000,500); }
        else
            if (strchr(MultimeDeCaractereAcceptabile, tasta))
            {
                // stergem fostul sir
                strcpy(S_,S); strcat(S_,"_");
                setcolor(BLACK); outtextxy(x,y,S_);
                s2[0]=tasta; strcat(S,s2); strcpy(S_,S); strcat(S_,"_");
                setcolor(WHITE); outtextxy(x,y,S_);
            }
            if (tasta==BackSpace)
                    if (!(strcmp(S,""))) Beep(500,100);
                    else
                    {
                        setcolor(BLACK); outtextxy(x,y,S_); setcolor(WHITE);
                        S[strlen(S)-1]='\0'; strcpy(S_,S); strcat(S_,"_") ;
                        outtextxy(x,y,S_); Beep(200,20);
                    }
            else
                if (tasta!=Enter && tasta!=Escape) { Beep(200,20); }
    } while (tasta!=Enter && tasta!=Escape);
    if (tasta == Escape) strcpy(S,S_initial);
    setcolor(BLACK); outtextxy(x,y,S_);setcolor(WHITE); outtextxy(x,y,S);
}
int main()
{
    initwindow(800,600,"Citire sir de caractere in mod grafic",200,200);
    char numepersoana[MAX_STR]="";
    char mesaj[MAX_STR];
    strcpy(mesaj,"Dati numele persoanei:");
    CitesteSir(100,100,mesaj,numepersoana);
    outtextxy(100,150,"Ati introdus");
    outtextxy(100,200,numepersoana);
    getch();
    closegraph();
    return 0;
}
