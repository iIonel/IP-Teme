#include <iostream>
using namespace std;
#define MAX_MULTIME 100

struct multime{
    unsigned int nrElemente;
    int element[MAX_MULTIME];
};


bool esteMultime(multime M)
{
    for(int i = 0; i < M.nrElemente - 1; ++i)
        for(int j = i + 1; j < M.nrElemente; ++j)
            if(M.element[i] == M.element[j])
                return false;
    return true;
}


bool apartine(int E, multime M)
{
    for(int i = 0; i < M.nrElemente; ++i)
        if(E == M.element[i])
            return true;
    return false;
}


void reuniune(multime A, multime B, multime& C)
{
    int poz = 0;
    for (int i = 0; i < A.nrElemente; ++i)
        C.element[poz++] = A.element[i];
    for(int i = 0; i < B.nrElemente; ++i)
        if(!apartine(B.element[i],A))
            C.element[poz++] = B.element[i];
}


void intersectie(multime A, multime B, multime& C)
{
    int poz = 0;
    int multime_mica = min(A.nrElemente,B.nrElemente);
    if(multime_mica == A.nrElemente)
    {
        for(int i = 0; i < A.nrElemente; ++i)
        {
            if(apartine(A.element[i],B))
                C.element[poz++] = A.element[i];
        }
    }
    else
    {
        for(int i = 0; i < B.nrElemente; ++i)
        {
            if(apartine(B.element[i],A))
                C.element[poz++] = B.element[i];
        }
    }
}


void diferenta(multime A, multime B, multime& C)
{
    int poz = 0;
    for(int i = 0; i < A.nrElemente; ++i)
        if(!apartine(A.element[i],B))
            C.element[poz++] = A.element[i];
}


void diferentaSimetrica(multime A, multime B, multime& C)
{
    reuniune(diferenta(A,B,C),diferenta(B,A,C),C);
}

