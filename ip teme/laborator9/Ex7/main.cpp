#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct persoana{
    char nume[25];
    unsigned int varsta;
    char sex;
}a[101];

void crearePersoana(persoana& p, char nume[25],int varsta,char sex)
{
    strcpy(p.nume,nume);
    p.varsta = varsta;
    p.sex = sex;
}

int main()
{
    FILE *fl;
    fl = fopen("fisier.txt","w");
    int persoane;
    cin >> persoane;
    for(int i = 0; i < persoane; ++i)
    {
        char nume[25];
        unsigned int varsta;
        char sex;
        cin >> nume >> varsta >> sex;
        crearePersoana(a[i],nume,varsta,sex);
        fprintf(fl,"%s \n",&a[i].nume);
    }
    for(int i = 0; i < persoane - 1; ++i)
        for(int j = i + 1; j < persoane; ++j)
        {
            if(strcmp(a[i].nume,a[j].nume)==1)
            {
                persoana b = a[i];
                a[i] = a[j];
                a[j] = b;
            }
        }
    for(int i = 0; i < persoane; ++i)
    {
        fprintf(fl,"%s \n",&a[i].nume);
    }
}
