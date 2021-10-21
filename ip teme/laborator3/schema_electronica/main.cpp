#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

struct piesa{
    int x,y;
    int orientare; // 1 sus -1 jos 2 stanga -2 dreapta 0 simplu
    vector<pair<int,int>> pini; // atat numarul Id cat si in ce parte a piesei se afla (1 sus -1 jos 2 stanga -2 dreapta)
    string tip,valoare;
    int marime;
    int lungime,latime;
};

struct fire{
    vector<int> directii; // 1 orizontal -1 vertical
    int pinIdStart,pinIdFinal;
};

struct schema{
    string autor,nume;
    vector<piesa> componente;
    vector<vector<pair<int,fire>>> muchii;
};


//nodurile sunt piese cu orientare 0 iar acesta se situeaza la intersectia de 2 muchii care duc la acelasi nod (fac vecinii unui nod si in ce pin se afla)
//vectoru directie ia toate directiile orizontale si verticale
//daca schimbam orientarea piesei atunci vom schimba si directia firelor (ca exemplu daca piesa este cu orientarea 1 si il schimbam in -1 ramane la fel dar daca este 2 atunci firele vor fii schimbate din vertiicale in orizontale si invers si numarul firelor vor fi cu una in minus)
//muchii arata toate conexiunile dintre noduri cu caracteristicile acestora date de structu fire

