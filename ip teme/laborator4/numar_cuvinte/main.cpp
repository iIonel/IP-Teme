#include <bits/stdc++.h>
using namespace std;


bool verificareIntreg(string a, int lungime)
{
    for(int i = 0; i < lungime; ++i)
            if(a[i] == ',' || a[i] == '.')
                return false;
    return true;
}

bool verificarePerioada(string a, int lungime)
{
    for(int i = 0; i < lungime; ++i)
        if(a[i] == '(')
           return true;
    return false;
}

string formatareZerouri(string a, int lungime)
{
    string format = "";
    for(int i = 0; i < a.size(); ++i)
    {
        if(a[i] != '0') break;
        else format += a[i];
    }
    return format;
}

string formatareNumarIntreg(string a, int lungime)
{
    if(verificareIntreg(a,lungime)) return a;
    string format = "";
    for(int i = 0; i < lungime; ++i)
        if(a[i] == '.' || a[i] == ',') return format;
        else format += a[i];
}

string formatareDupaVirgula(string a, int lungime)
{
    string formatAuxiliar = formatareNumarIntreg(a,lungime);
    int numarIntregLungime = formatAuxiliar.size();
    string format = "";
    for(int i = numarIntregLungime + 1; i < lungime; ++i)
        if(a[i] == '(') return format;
        else format += a[i];
    return format;
}

string formatarePerioada(string a, int lungime)
{
    int poz = lungime;
    string format = "";
    for(int i = 0; i < lungime; ++i)
        if(a[i] == '(')
        {
            poz = i + 1;
            break;
        }
    for(int i = poz; i < lungime - 1; ++i)
        format += a[i];
    return format;
}

int numarCifre(string a, int Start, int Final)
{
    return Final-Start;
}

void afisareSpeciala(string a, int Start, int Final)
{
    switch(a[Start])
    {
        case '0':
            cout << "";
            break;
        case '1':
            cout << " o";
            break;
        case '2':
            cout << " doua";
            break;
        case '6':
            cout << " sai";
    }

}

void afisareCifra(string a, int Start, int Final)
{
    switch(a[Final])
    {
        case '0':
            cout << " zero";
            break;
        case '1':
            cout << " unu";
            break;
        case '2':
            cout << " doi";
            break;
        case '3':
            cout << " trei";
            break;
        case '4':
            cout << " patru";
            break;
        case '5':
            cout << " cinci";
            break;
        case '6':
            cout << " sase";
            break;
        case '7':
            cout << " sapte";
            break;
        case '8':
            cout << " opt";
            break;
        case '9':
            cout << " noua";
            break;
    }
}


void afisareSpeciala2(string a, int Start, int Final)
{
    switch(a[Start])
    {
        case '0':
            cout << "";
            break;
        default:
            cout <<" si";
            afisareCifra(a,Start,Start);
            break;
    }
}


void afisareZecilor(string a, int Start, int Final)
{
    if(a[Start] == '1')
    {
        switch(a[Final])
        {
            case '0':
                cout << " zece";
                break;
            case '1':
                cout << " unsprezece";
                break;
            case '2':
                cout << " doisprezece";
                break;
            case '3':
                cout << " treisprezece";
                break;
            case '4':
                cout << " paisprezece";
                break;
            case '5':
                cout << " cincisprezece";
                break;
            case '6':
                cout << " saisprezece";
                break;
            case '7':
                cout << " saptesprezece";
                break;
            case '8':
                cout << " optsprezece";
                break;
            case '9':
                cout << " nouasprezece";
                break;
        }
    }
    else
    {
        switch(a[Start])
        {
            case '2':
                afisareSpeciala(a,Start,Start);
                cout << "zeci";
                afisareSpeciala2(a,Final,Final);
                break;
            case '3':
                afisareCifra(a,Start,Start);
                cout << "zeci";
                afisareSpeciala2(a,Final,Final);
                break;
            case '4':
                afisareCifra(a,Start,Start);
                cout << "zeci";
                afisareSpeciala2(a,Final,Final);
                break;
            case '5':
                afisareCifra(a,Start,Start);
                cout << "zeci";
                afisareSpeciala2(a,Final,Final);
                break;
            case '6':
                afisareSpeciala(a,Start,Start);
                cout << "zeci";
                afisareSpeciala2(a,Final,Final);
                break;
            case '7':
                afisareCifra(a,Start,Start);
                cout << "zeci";
                afisareSpeciala2(a,Final,Final);
                break;
            case '8':
                afisareCifra(a,Start,Start);
                cout << "zeci";
                afisareSpeciala2(a,Final,Final);
                break;
            case '9':
                afisareCifra(a,Start,Start);
                cout << "zeci";
                afisareSpeciala2(a,Final,Final);
                break;
        }
    }
}


void afisareSutelor(string a, int Start, int Final)
{
    int nonZerouriPozitie = Final + 1;
    for(int i = Start + 1; i <= Final; ++i)
        if(a[i] != '0')
        {
            nonZerouriPozitie = i;
            break;
        }
    switch(a[Start])
    {
        case '1':
            afisareSpeciala(a,Start,Start);
            cout << " suta";
            break;
        case '2':
            afisareSpeciala(a,Start,Start);
            cout << " sute";
            break;
        case '3': afisareCifra(a,Start,Start);
            cout << " sute";
            break;
        case '4':
            afisareCifra(a,Start,Start);
            cout << " sute";
            break;
        case '5':
            afisareCifra(a,Start,Start);
            cout << " sute";
            break;
        case '6':
            afisareCifra(a,Start,Start);
            cout << " sute";
            break;
        case '7':
            afisareCifra(a,Start,Start);
            cout << " sute";
            break;
        case '8':
            afisareCifra(a,Start,Start);
            cout << " sute";
            break;
        case '9':
            afisareCifra(a,Start,Start);
            cout << " sute";
            break;
    }

    string nou = "";
    Start = nonZerouriPozitie;
    for (int i = Start; i <= Final; ++i)
        nou = nou + a[i];
    int lungime_nou = nou.size();

    switch(lungime_nou)
    {
        case 1:
            afisareCifra(nou,0,lungime_nou-1);
            break;
        case 2:
            afisareZecilor(nou,0,lungime_nou-1);
            break;
    }
}


void afisareMiilor(string a, int Start, int Final)
{
    int nonZerouriPozitie = Final + 1;
    for(int i = Start + (Final - 2); i <= Final; ++i)
        if(a[i] != '0')
        {
            nonZerouriPozitie = i;
            break;
        }
    switch (Final + 1)
    {
        case 4:
            switch(a[Start])
            {
                case '1':
                    afisareSpeciala(a,Start,Start);
                    cout << " mie";
                break;
                case '2':
                    afisareSpeciala(a,Start,Start);
                    cout << " mii";
                break;
                case '3':
                    afisareCifra(a,Start,Start);
                    cout << " mii";
                    break;
                case '4':
                    afisareCifra(a,Start,Start);
                    cout << " mii";
                    break;
                case '5':
                    afisareCifra(a,Start,Start);
                    cout << " mii";
                    break;
                case '6':
                    afisareCifra(a,Start,Start);
                    cout << " mii";
                    break;
                case '7':
                    afisareCifra(a,Start,Start);
                    cout << " mii";
                    break;
                case '8':
                    afisareCifra(a,Start,Start);
                    cout << " mii";
                    break;
                case '9':
                    afisareCifra(a,Start,Start);
                    cout << " mii";
                    break;
            }
            break;
        case 5:
            switch(a[Start])
            {
                case '1':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " mii";
                break;
                case '2':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de mii";
                break;
                case '3':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de mii";
                    break;
                case '4':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de mii";
                    break;
                case '5':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de mii";
                    break;
                case '6':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de mii";
                    break;
                case '7':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de mii";
                    break;
                case '8':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de mii";
                    break;
                case '9':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de mii";
                    break;
            }
            break;
        case 6:
            switch(a[Start])
            {
                case '1':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " mii";
                    else
                        cout << " de mii";
                break;
                case '2':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " mii";
                    else
                        cout << " de mii";
                break;
                case '3':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " mii";
                    else
                        cout << " de mii";
                    break;
                case '4':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " mii";
                    else
                        cout << " de mii";
                    break;
                case '5':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0'&& a[Start + 2] != '0'))
                        cout << " mii";
                    else
                        cout << " de mii";
                    break;
                case '6':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " mii";
                    else
                        cout << " de mii";
                    break;
                case '7':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " mii";
                    else
                        cout << " de mii";
                    break;
                case '8':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " mii";
                    else
                        cout << " de mii";
                    break;
                case '9':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " mii";
                    else
                        cout << " de mii";
                    break;
            }
            break;
    }
    string nou = "";
    Start = nonZerouriPozitie;
    for (int i = Start; i <= Final; ++i)
        nou = nou + a[i];
    int lungime_nou = nou.size();

    switch(lungime_nou)
    {
        case 1:
            afisareCifra(nou,0,lungime_nou-1);
            break;
        case 2:
            afisareZecilor(nou,0,lungime_nou-1);
            break;
        case 3:
            afisareSutelor(nou,0,lungime_nou-1);
            break;
    }
}


void afisareMilioanelor(string a, int Start, int Final)
{
    int nonZerouriPozitie = Final + 1;
    for(int i = Start + (Final - 5); i <= Final; ++i)
        if(a[i] != '0')
        {
            nonZerouriPozitie = i;
            break;
        }
    switch (Final + 1)
    {
        case 7:
            switch(a[Start])
            {
                case '1':
                    cout << " un milion";
                break;
                case '2':
                    afisareSpeciala(a,Start,Start);
                    cout << " milioane";
                break;
                case '3':
                    afisareCifra(a,Start,Start);
                    cout << " milioane";
                    break;
                case '4':
                    afisareCifra(a,Start,Start);
                    cout << " milioane";
                    break;
                case '5':
                    afisareCifra(a,Start,Start);
                    cout << " milioane";
                    break;
                case '6':
                    afisareCifra(a,Start,Start);
                    cout << " milioane";
                    break;
                case '7':
                    afisareCifra(a,Start,Start);
                    cout << " milioane";
                    break;
                case '8':
                    afisareCifra(a,Start,Start);
                    cout << " milioane";
                    break;
                case '9':
                    afisareCifra(a,Start,Start);
                    cout << " milioane";
                    break;
            }
            break;
        case 8:
            switch(a[Start])
            {
                case '1':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " milioane";
                break;
                case '2':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de milioane";
                break;
                case '3':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de milioane";
                    break;
                case '4':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de milioane";
                    break;
                case '5':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de milioane";
                    break;
                case '6':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de milioane";
                    break;
                case '7':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de milioane";
                    break;
                case '8':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de milioane";
                    break;
                case '9':
                    afisareZecilor(a,Start,Start + 1);
                    cout << " de milioane";
                    break;
            }
            break;
        case 9:
            switch(a[Start])
            {
                case '1':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " milioane";
                    else
                        cout << " de milioane";
                break;
                case '2':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " milioane";
                    else
                        cout << " de milioane";
                break;
                case '3':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " milioane";
                    else
                        cout << " de milioane";
                    break;
                case '4':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' ||(a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " milioane";
                    else
                        cout << " de milioane";
                    break;
                case '5':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' ||(a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " milioane";
                    else
                        cout << " de milioane";
                    break;
                case '6':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " milioane";
                    else
                        cout << " de milioane";
                    break;
                case '7':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " milioane";
                    else
                        cout << " de milioane";
                    break;
                case '8':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " milioane";
                    else
                        cout << " de milioane";
                    break;
                case '9':
                    afisareSutelor(a,Start,Start + 2);
                    if(a[Start + 1] == '1' || (a[Start + 1] == '0' && a[Start + 2] != '0'))
                        cout << " milioane";
                    else
                        cout << " de milioane";
                    break;
            }
            break;
    }
    string nou = "";
    Start = nonZerouriPozitie;
    for (int i = Start; i <= Final; ++i)
        nou = nou + a[i];
    int lungime_nou = nou.size();

    switch(lungime_nou)
    {
        case 1:
            afisareCifra(nou,0,lungime_nou-1);
            break;
        case 2:
            afisareZecilor(nou,0,lungime_nou-1);
            break;
        case 3:
            afisareSutelor(nou,0,lungime_nou-1);
            break;
        case 4:
            afisareMiilor(nou,0,lungime_nou-1);
            break;
        case 5:
            afisareMiilor(nou,0,lungime_nou-1);
            break;
        case 6:
            afisareMiilor(nou,0,lungime_nou-1);
            break;
    }
}


void afisareNumar(string a, int lungime)
{
    switch (lungime)
    {
        case 1:
            afisareCifra(a,0,lungime-1);
            break;
        case 2:
            afisareZecilor(a,0,lungime-1);
            break;
        case 3:
            afisareSutelor(a,0,lungime-1);
            break;
        case 4:
            afisareMiilor(a,0,lungime-1);
            break;
        case 5:
            afisareMiilor(a,0,lungime-1);
            break;
        case 6:
            afisareMiilor(a,0,lungime-1);
            break;
        case 7:
            afisareMilioanelor(a,0,lungime-1);
            break;
        case 8:
            afisareMilioanelor(a,0,lungime-1);
            break;
        case 9:
            afisareMilioanelor(a,0,lungime-1);
            break;
    }

}


int main()
{
    string numar;
    cin >> numar;
    int cifre = 0;
    int lungime = numar.size();

    if(numar[0] == '-')
    {
        cout << " minus";
        numar.erase(0,1);
    }

    string numarIntreg = formatareNumarIntreg(numar,lungime);
    string numarDupaVirgula = formatareDupaVirgula(numar,lungime);
    string perioada = formatarePerioada(numar,lungime);
    afisareNumar(numarIntreg,numarIntreg.size());
    if(!verificareIntreg(numar,lungime))
    {
        cout << " virgula";
        int lungimeNumarDupaVirgula = numarDupaVirgula.size();
        while(lungimeNumarDupaVirgula)
        {
            string zerouri = formatareZerouri(numarDupaVirgula,numarDupaVirgula.size());
            int lungimeZerouri = zerouri.size();
            while(lungimeZerouri--)
                cout << " zero";
            numarDupaVirgula.erase(0,zerouri.size());
            lungimeNumarDupaVirgula = numarDupaVirgula.size();
            int lungimeNou = min(lungimeNumarDupaVirgula,9);
            string nou = "";
            for(int i = 0; i < lungimeNou; ++i)
                nou += numarDupaVirgula[i];
            afisareNumar(nou,nou.size());
            numarDupaVirgula.erase(0,nou.size());
            lungimeNumarDupaVirgula = numarDupaVirgula.size();
        }

        if(verificarePerioada(numar,lungime))
        {
            cout << " si";
            int lungimeNumarPerioada = perioada.size();
            while(lungimeNumarPerioada)
            {
                string zerouri = formatareZerouri(perioada,perioada.size());
                int lungimeZerouri = zerouri.size();
                while(lungimeZerouri--)
                    cout << " zero";
                perioada.erase(0,zerouri.size());
                lungimeNumarPerioada = perioada.size();
                int lungimeNou = min(lungimeNumarPerioada,9);
                string nou = "";
                for(int i = 0; i < lungimeNou; ++i)
                    nou += perioada[i];
                afisareNumar(nou,nou.size());
                perioada.erase(0,nou.size());
                lungimeNumarPerioada = perioada.size();
            }
            cout << " in perioada";
        }
    }
}
