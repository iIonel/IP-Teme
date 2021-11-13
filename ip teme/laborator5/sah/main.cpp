#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

struct piesa_tip{
    string nume;
    string culoare;
    char coloana;
    int linie;
    string culoare_tabla;
    bool runda_folosite;
    bool pierdute;
};

struct chenar{
    int x1,y1,x2,y2;
};
vector<piesa_tip>piese;
bool culori[10][10] = {false};

chenar coordonate_sah(char a, int b)
{
    chenar coordonate;
    int x,y,z,w;
    x = 100*(a-'a');
    y = 100*(8-b);
    z = 100*(a-'a') + 100;
    w =100*(8-b) + 100;
    coordonate.x1 = x;
    coordonate.y1 = y;
    coordonate.x2 = z;
    coordonate.y2 = w;
    return coordonate;
}

void tabla_colorare(){
    int coloane = 1;
    bool alb = true;
    int x1 = 0;
    int y1 = 0;
    int x2 = 100;
    int y2 = 100;
    while(coloane <= 8)
    {
        for(int i = 1; i <= 8; ++i)
        {
            if(alb == true)
                readimagefile("res/inchis.jpg",x1,y1,x2,y2),
                alb = false,
                culori[i][coloane] = true;
            else
                readimagefile("res/deschis.jpg",x1,y1,x2,y2),
                alb = true;
            y1 += 100;
            y2 += 100;
        }
        x1 += 100;
        y1 = 0;
        x2 += 100;
        y2 = 100;
        coloane++;
        alb = !alb;
    }
}

piesa_tip piesa_initializare(string n, string cul, char col, int l, string cult)
{
    piesa_tip piesa;
    piesa.nume = n;
    piesa.culoare = cul;
    piesa.coloana = col;
    piesa.linie = l;
    piesa.culoare_tabla = cult;
    return piesa;
}

void initializare()
{
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("tura","negru",'a',8,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("tura","negru",'h',8,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("cal","negru",'b',8,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("cal","negru",'g',8,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("nebun","negru",'c',8,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("nebun","negru",'f',8,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("rege","negru",'e',8,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("regina","negru",'d',8,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","negru",'a',7,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","negru",'b',7,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","negru",'c',7,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","negru",'d',7,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","negru",'e',7,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","negru",'f',7,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","negru",'g',7,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","negru",'h',7,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("tura","alb",'a',1,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("tura","alb",'h',1,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("cal","alb",'b',1,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("cal","alb",'g',1,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("nebun","alb",'c',1,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("nebun","alb",'f',1,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("regina","alb",'d',1,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("rege","alb",'e',1,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","alb",'a',2,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","alb",'b',2,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","alb",'c',2,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","alb",'d',2,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","alb",'e',2,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","alb",'f',2,"alb");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","alb",'g',2,"negru");
    piese.push_back(piesa_tip());
    piese.back() = piesa_initializare("pion","alb",'h',2,"alb");
    piese.push_back(piesa_tip());
    for(int i = 0; i < piese.size();++i)
    {
        piese[i].runda_folosite = false;
        piese[i].pierdute = false;
        char litera = piese[i].coloana;
        int numar = piese[i].linie;
        chenar pozitie;
        pozitie = coordonate_sah(litera,numar);
        if(piese[i].nume == "pion")
            if(piese[i].culoare == "negru")
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/pion_negru_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/pion_negru_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

            else
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/pion_alb_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/pion_alb_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
        else if(piese[i].nume == "tura")
            if(piese[i].culoare == "negru")
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/tura_negru_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/tura_negru_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

            else
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/tura_alb_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/tura_alb_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
        else if(piese[i].nume == "nebun")
            if(piese[i].culoare == "negru")
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/nebun_negru_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/nebun_negru_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

            else
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/nebun_alb_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/nebun_alb_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
        else if(piese[i].nume == "cal")
            if(piese[i].culoare == "negru")
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/cal_negru_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/cal_negru_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

            else
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/cal_alb_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/cal_alb_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
        else if(piese[i].nume == "rege")
            if(piese[i].culoare == "negru")
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/rege_negru_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/rege_negru_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

            else
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/rege_alb_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/rege_alb_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
        else if(piese[i].nume == "regina")
            if(piese[i].culoare == "negru")
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/regina_negru_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/regina_negru_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

            else
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/regina_alb_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/regina_alb_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

    }
}

string culoare_placuta(char a, int b)
{
    int coloana = int(a-'a') + 1;
    int linie = 9 - b;
    string cul;
    if(culori[linie][coloana] == 1)
        cul = "negru";
    else cul = "alb";
    return cul;
}

void desen_piesa(int i)
{
        char litera = piese[i].coloana;
        int numar = piese[i].linie;
        chenar pozitie;
        pozitie = coordonate_sah(litera,numar);
        if(piese[i].nume == "pion")
            if(piese[i].culoare == "negru")
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/pion_negru_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/pion_negru_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

            else
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/pion_alb_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/pion_alb_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
        else if(piese[i].nume == "tura")
            if(piese[i].culoare == "negru")
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/tura_negru_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/tura_negru_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

            else
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/tura_alb_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/tura_alb_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
        else if(piese[i].nume == "nebun")
            if(piese[i].culoare == "negru")
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/nebun_negru_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/nebun_negru_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

            else
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/nebun_alb_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/nebun_alb_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
        else if(piese[i].nume == "cal")
            if(piese[i].culoare == "negru")
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/cal_negru_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/cal_negru_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

            else
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/cal_alb_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/cal_alb_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
        else if(piese[i].nume == "rege")
            if(piese[i].culoare == "negru")
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/rege_negru_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/rege_negru_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

            else
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/rege_alb_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/rege_alb_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
        else if(piese[i].nume == "regina")
            if(piese[i].culoare == "negru")
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/regina_negru_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/regina_negru_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

            else
                if(piese[i].culoare_tabla == "negru")
                    readimagefile("res/regina_alb_negru.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);
                else
                    readimagefile("res/regina_alb_alb.jpg",pozitie.x1,pozitie.y1,pozitie.x2,pozitie.y2);

}

int determinare(char litera,int numar)
{
    int j = -1;
    for(int i = 0; i < piese.size(); ++i)
        if(piese[i].coloana == litera && piese[i].linie == numar)
            j = i;
    return j;
}

piesa_tip mutare(char initial_litera, char final_litera, int initial_numar, int final_numar, string culoare, string culoare_tabla_initiala, string culoare_tabla_finala, string nume)
{
    if(determinare(final_litera,final_numar) != -1)
        piese[determinare(final_litera,final_numar)].pierdute = true;
    chenar pozitie_veche = coordonate_sah(initial_litera,initial_numar);
    if(culoare_tabla_initiala == "negru")
        readimagefile("res/inchis.jpg",pozitie_veche.x1,pozitie_veche.y1,pozitie_veche.x2,pozitie_veche.y2);
    else
         readimagefile("res/deschis.jpg",pozitie_veche.x1,pozitie_veche.y1,pozitie_veche.x2,pozitie_veche.y2);
    piesa_tip piesa;
    piesa.culoare = culoare;
    piesa.nume = nume;;
    piesa.coloana = final_litera;
    piesa.linie = final_numar;
    piesa.culoare_tabla = culoare_placuta(piesa.coloana,piesa.linie);
    return piesa;
}

bool exista_piesa_diferita(char litera,int numar,string culoare)
{
    for(int i = 0; i < piese.size(); ++i)
        if(piese[i].coloana == litera && piese[i].linie == numar && culoare != piese[i].culoare)
            return true;
    return false;
}

bool este(char litera,int numar,int i)
{
    int coordonata = -1;
    for(int j = 0; j < piese.size(); ++j)
        if(piese[j].coloana == litera  && piese[j].linie == numar)
        {
            coordonata = j;
            break;
        }
    if(coordonata == -1)
        return true;
    if(piese[coordonata].culoare == piese[i].culoare)
        return false;
    if(litera < 'a' || litera > 'h')
        return false;
    if(numar < 1 || numar > 8)
        return false;
    return true;
}

bool pion(char initial_litera,char final_litera, int initial_numar, int final_numar,int i)
{
    if(!este(final_litera,final_numar,i))
        return false;

    if(determinare(final_litera,final_numar) != -1 && (final_numar==initial_numar || final_litera==initial_litera))
        return false;
    if(piese[i].culoare == "negru")
    {
        if(final_numar > initial_numar)
            return false;
        if(final_numar == initial_numar-2 && piese[i].runda_folosite == false && final_numar >= 4){
            piese[i].runda_folosite = true;
            return true;
        }
        if(final_numar == initial_numar-1 && initial_litera == final_litera)
            return true;
        if(final_numar == initial_numar-1 && (final_litera == initial_litera + 1 || final_litera == initial_litera - 1) && exista_piesa_diferita(final_litera,final_numar,piese[i].culoare))
            return true;
        else return false;
    }
    else
    {
        if(final_numar < initial_numar)
            return false;
        if(final_numar == initial_numar+2 && piese[i].runda_folosite == false && final_numar <= 4){
            piese[i].runda_folosite = true;
            return true;
        }
        if(final_numar == initial_numar+1 && initial_litera == final_litera)
            return true;
        if(final_numar == initial_numar+1 && (final_litera == initial_litera + 1 || final_litera == initial_litera - 1) && exista_piesa_diferita(final_litera,final_numar,piese[i].culoare))
            return true;
        else return false;
    }
}

bool tura(char initial_litera,char final_litera, int initial_numar, int final_numar,int i)
{
    if(!este(final_litera,final_numar,i))
        return false;
    if(initial_litera == final_litera)
    {
        int diferenta = initial_numar-final_numar;
        if(diferenta>0)
        {
            for(int j = 1; j < diferenta; j++){
                if(determinare(initial_litera,initial_numar-j) != -1)
                    return false;
            }
            if(piese[determinare(initial_litera,final_numar)].culoare == piese[i].culoare)
                return false;
        }
        else
        {
            for(int j = 1; j < diferenta; j++)
                if(determinare(initial_litera,initial_numar+j) != -1)
                    return false;
            if(piese[determinare(initial_litera,final_numar)].culoare == piese[i].culoare)
                return false;
        }
        return true;

    }
    if(initial_numar == final_numar)
    {
        int diferenta = initial_litera-final_litera;
        if(diferenta>0)
        {
            for(int j = 1; j < diferenta; j++)
                if(determinare(initial_litera-j,initial_numar) != -1)
                    return false;
            if(piese[determinare(initial_litera,final_numar)].culoare == piese[i].culoare)
                return false;
        }
        else
        {
            for(int j = 1; j < diferenta; j++)
                if(determinare(initial_litera+j,initial_numar) != -1)
                    return false;
            if(piese[determinare(initial_litera,final_numar)].culoare == piese[i].culoare)
                return false;
        }
        return true;
    }
    return false;
}

bool cal(char initial_litera,char final_litera, int initial_numar, int final_numar,int i)
{

}

bool nebun(char initial_litera,char final_litera, int initial_numar, int final_numar,int i)
{

}

bool regina(char initial_litera,char final_litera, int initial_numar, int final_numar,int i)
{

}

bool rege(char initial_litera,char final_litera, int initial_numar, int final_numar,int i)
{

}

bool este_runda(int i,bool rand)
{
    if(piese[i].culoare == "alb" && rand == true)
        return false;
    if(piese[i].culoare == "negru" && rand == false)
        return false;
    return true;
}


void joc(){
  //  while(!sahMat()){
        bool rand = true;
        while(1){
                bool alegere = true;
                if(rand) cout << "E RUNDA CELUI ALB!!!" << "\n",rand = false;
                else cout << "E RUNDA CELUI NEGRU!!!" << "\n",rand = true;
                cout << "Alegeti pozitia piesei pe care vreti sa o mutati:" << "\n";
                cout << "Linia(de la 1 pana la 8, de jos in sus): ";
                int linie;
                cin >> linie;
                cout << "\n" << "Coloana(de la a la h, de la stanga la dreapta): ";
                char coloana;
                cin >> coloana;
                cout << "\n";
                cout << "Acum alegeti pozitia unde vreti sa o mutati: ";
                int linie_noua;
                char coloana_noua;
                cout << "\n" << "Linia: ";
                cin >> linie_noua;
                cout << "\n" << "Coloana: ";
                cin >> coloana_noua;
                if(determinare(coloana,linie) == -1)
                    alegere = false;
                else if(!este_runda(determinare(coloana,linie),rand))
                    alegere = false;
                int folosit = false;
                if(alegere == true)
                for(int i = 0; i < piese.size(); ++i)
                    if(piese[i].coloana == coloana && piese[i].linie == linie)
                    {
                        folosit = true;
                        bool ok = true;
                        if(!este(coloana_noua,linie_noua,i))
                        {
                            rand = !rand;
                            break;
                        }
                        if(piese[i].nume == "pion")
                            if(!pion(coloana,coloana_noua,linie,linie_noua,i)) ok = false;
                        if(piese[i].nume == "tura")
                            if(!tura(coloana,coloana_noua,linie,linie_noua,i)) ok = false;
                        else if(piese[i].nume == "cal")
                            if(!cal(coloana,coloana_noua,linie,linie_noua,i)) ok = false;
                        else if(piese[i].nume == "nebun")
                            if(!nebun(coloana,coloana_noua,linie,linie_noua,i)) ok = false;
                        else if(piese[i].nume == "regina")
                            if(!regina(coloana,coloana_noua,linie,linie_noua,i)) ok = false;
                        else if(piese[i].nume == "rege")
                            if(!rege(coloana,coloana_noua,linie,linie_noua,i)) ok = false;
                        if(!ok){
                            folosit = false;
                            break;
                        }
                        piese[i] = mutare(piese[i].coloana,coloana_noua,piese[i].linie,linie_noua,piese[i].culoare,piese[i].culoare_tabla,piese[i].culoare_tabla,piese[i].nume);
                        desen_piesa(i);
                        if(piese[i].nume == "pion")
                        {
                            if(piese[i].culoare == "negru" && piese[i].linie == 1)
                            {
                                string piesa_noua;
                                cout << '\n' << "Scrieti ce piesa va doriti: ";
                                cin >> piesa_noua;
                                piese[i].nume = piesa_noua;
                            }
                            else if(piese[i].culoare == "alb" && piese[i].linie == 8)
                            {
                                string piesa_noua;
                                cout << '\n' << "Scrieti ce piesa va doriti: ";
                                cin >> piesa_noua;
                                piese[i].nume = piesa_noua;
                            }
                            desen_piesa(i);
                        }
                        break;

                    }
                if(folosit == false) rand = !rand;
        }
}

int main()
{
    initwindow(800,800,"sah");
    cleardevice();
    tabla_colorare();
    initializare();
    joc();
    getch();
}
