#include <stdio.h>
#include <string.h>

int main()
{
    char operatii[101];
    int numere[101];
    int raspuns = 0;
    int lungime;
    int n;
    scanf("%s",operatii);
    lungime = strlen(operatii);
    n = lungime + 1;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&numere[i]);
    }
    int indice = 0;
    for(int i = 0; i < lungime; ++i)
        if(operatii[i] == '/')
        {
            int numar1 = numere[i - indice];
            int numar2 = numere[i + 1 - indice];
            int rezultat =  numar1/numar2;
            numere[i - indice] = rezultat;
            int pozitie = i + 1 - indice;
            for(int j = pozitie; j < n - 1; ++j)
                numere[j] = numere[j + 1];
            n--;
            indice++;
        }
        else if(operatii[i] == '*')
        {
            int numar1 = numere[i - indice];
            int numar2 = numere[i + 1 - indice];
            int rezultat =  numar1*numar2;
            numere[i - indice] = rezultat;
            int pozitie = i + 1 - indice;
            for(int j = pozitie; j < n - 1; ++j)
                numere[j] = numere[j + 1];
            n--;
            indice++;
        }
        char eliminare[101];
        int poz = 0;
        for(int i = 0; i < lungime; ++i)
            if(operatii[i] == '+' || operatii[i] == '-')
            eliminare[poz++] = operatii[i];
        lungime = poz;
     for(int i = 0; i < lungime; ++i)
        if(eliminare[i] == '+')
        {
            int numar1 = numere[0];
            int numar2 = numere[1];
            int rezultat =  numar1+numar2;
            numere[0] = rezultat;
            int pozitie = 1;
            for(int j = pozitie; j < n - 1; ++j)
                numere[j] = numere[j + 1];
            n--;
        }
        else if(eliminare[i] == '-')
        {
            int numar1 = numere[0];
            int numar2 = numere[1];
            int rezultat =  numar1-numar2;
            numere[0] = rezultat;
            int pozitie = 1;
            for(int j = pozitie; j < n - 1; ++j)
                numere[j] = numere[j + 1];
            n--;
        }
        printf("%d",numere[0]);
}
