#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main()
{
    char c;
    FILE *f1, *f2;
    char f1_file[] = "f_initial.txt";
    char f2_file[] = "f_final.txt";
    f1 = fopen(f1_file,"r");
    f2 = fopen(f2_file,"w");
    while((c = fgetc(f1)) != EOF)
    {
        fputc(c,f2);
    }
    fclose(f1);
    fclose(f2);
}
