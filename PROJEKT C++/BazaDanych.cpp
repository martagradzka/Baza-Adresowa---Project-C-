#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct baza
{
    string imie;
    string nazwisko;
    string miasto;
    string ulica;
    string kod_pocztowy;
    string nr_budynku;
    string nr_lokalu;
};

baza p[1000];

void zapiszOsobe(int &n)
{
    ofstream plik("bazza.txt", ios::out);
    plik <<n<<endl;;
    cout<<n<<endl;
    for (int i = 0; i<n; i++)
    {
        plik <<p[i].imie<<endl;
        plik <<p[i].nazwisko<<endl;
        plik <<p[i].miasto<<endl;
        plik <<p[i].kod_pocztowy<<endl;
        plik <<p[i].ulica<<endl;
        plik <<p[i].nr_budynku<<endl;
        plik <<p[i].nr_lokalu<<endl;
    }
    cout<<endl;
    cout <<"Dane zostaly zapisane!, Wcisnij ENTER!";

getchar();
}

void wyswietlOsoby(int &n)
{
    if ( n!= 0)
    {
        for (int i = 0; i<n; i++)
        {
            cout<<"Imie:        "<<p[i].imie<<endl;
            cout<<"Nazwisko:    "<<p[i].nazwisko<<endl;
            cout<<"Miasto:      "<<p[i].miasto<<endl;
            cout<<"Kod pocztowy:"<<p[i].kod_pocztowy<<endl;
            cout<<"Ulica:       "<<p[i].ulica<<endl;
            cout<<"Nr budynku:  "<<p[i].nr_budynku<<endl;
            cout<<"Nr lokalu:   "<<p[i].nr_lokalu<<endl;
        }
    }
    else
        {
            cout <<"Brak listy osob"<<endl;
        }

    cout<<"Wcisnij ENTER!";

getchar();
}

void wczytajOsoby(int &n)
{
    ifstream plik("bazza.txt", ios::in);
    plik >>n;
    string tekst;
    getline(plik,tekst);
    int i=0;

    do
    {
        getline(plik, p[i].imie);
        getline(plik, p[i].nazwisko);
        getline(plik, p[i].miasto);
        getline(plik, p[i].ulica);
        getline(plik, p[i].kod_pocztowy);
        getline(plik, p[i].nr_budynku);
        getline(plik, p[i].nr_lokalu);
        i++;
    }

    while( !plik.eof() );
    cout <<"Wczytano liste osob."<<endl;

getchar();
}

void dodajOsobe(int &n)
{
    cin.ignore();
    string tekst;
    string imie;
    cout <<"Podaj Imie: ";
    getline(cin,imie);
    p[n].imie=imie;

    string nazwisko;
    cout <<"Nazwisko: ";
    getline(cin,nazwisko);
    p[n].nazwisko=nazwisko;

    string miasto;
    cout <<"Miasto: ";
    getline(cin,miasto);
    p[n].miasto=miasto;

    cout <<"Kod pocztowy: ";
    cin >>p[n].kod_pocztowy;
    cin.ignore();

    string ulica;
    cout <<"Ulica: ";
    getline(cin,ulica);
    p[n].ulica=ulica;

    cout <<"Numer budynku: ";
    string nr_budynku;
    getline(cin,nr_budynku);
    p[n].nr_budynku=nr_budynku;

    cout <<"Nr lokalu: ";
    string nr_lokalu;
    getline(cin,nr_lokalu);
    p[n].nr_lokalu=nr_lokalu;
    cin.ignore();

    n++;

    cout <<endl;
    zapiszOsobe(n);
    cout<<endl;
}


void usunOsobe (int &n)
{
    int k;
    cout<<"*--- Ktorego uzytkownika usunac: ";
    cin>>k;
    if (n>=k&&k>0)
        {
            for(int i=k;i<n;i++)
            p[k-1]=p[k];
            n--;
        }
    else
        cout<<"Takiego elementu nie mozna usunac"<<endl;

    wyswietlOsoby(n);
return ;
}


void szukajOsobe (int &n)
{
     string wyszukiwarka;
     int nr_szukaj;

     cout<<"        ---------- WYSZUKIWARKA ----------"<<endl;
     cout<<"*--- Wybierz kryterium wyszukiwania ---*"<<endl;
     cout<<"       -----------------"<<endl;;
     cout<<"         |   1 Imie      |"<<endl;
     cout<<"         |   2 Nazwisko  |"<<endl;
     cout<<"         |   3 Miasto    |"<<endl;
     cout<<"         |   4 Ulica     |"<<endl;
     cout<<"       -------------------"<<endl;
     cout<<"   *--- Twoj wybor: ";
     cin>>nr_szukaj;

    switch(nr_szukaj)
    {
    case 1:
        cout<<"--- Twoj wybor: przez podanie imienia ---"<<endl ;
        cout<<"*---Podaj szukane imie: "<<endl;
        cin>>wyszukiwarka;
        cout<<"Wynik wyszukiwania: "<<endl;

        for(int i=0;i<n;i++)
        {
            if(wyszukiwarka==p[i].imie)
            {
                cout<<"--------------------------------------"<<endl;
                cout<<"   Imie:          "<<p[i].imie<<endl;
                cout<<"   Nazwisko:      "<<p[i].nazwisko<<endl;
                cout<<"   Miasto:        "<<p[i].miasto<<endl;
                cout<<"   Kod pocztowy:  "<<p[i].kod_pocztowy<<endl;
                cout<<"   Ulica:         "<<p[i].ulica<<endl;
                cout<<"   Numer budynku: "<<p[i].nr_budynku<<endl;
                cout<<"   Numer lokalu:  "<<p[i].nr_lokalu<<endl;
                cout<<" --------------------------------------";
            }
        }
        break;


    case 2:
        cout<<"--- Twoj wybor: przez podanie nazwiska ---"<<endl;
        cout<<"*---Podaj szukane Nazwisko: " ;
        cin>>wyszukiwarka;
        cout<<"Wynik wyszukiwania: ";

        for(int i=0;i<n;i++)
        {
            if(wyszukiwarka==p[i].nazwisko)
            {
                cout<<" --------------------------------------"<<endl;
                cout<<"   Imie:          "<<p[i].imie<<endl;
                cout<<"   Nazwisko:      "<<p[i].nazwisko<<endl;
                cout<<"   Miasto:        "<<p[i].miasto<<endl;
                cout<<"   Kod pocztowy:  "<<p[i].kod_pocztowy<<endl;
                cout<<"   Ulica:         "<<p[i].ulica<<endl;
                cout<<"   Numer budynku: "<<p[i].nr_budynku<<endl;
                cout<<"   Numer lokalu:  "<<p[i].nr_lokalu<<endl;
                cout<<" --------------------------------------"<<endl;
            }
        }
        break;


    case 3:
        cout<<"--- Twoj wybor: Mieszkancy danego miasta ---"<<endl;
        cout<<"*--- Podaj nazwe miasta: " ;
        cin>>wyszukiwarka;
        cout<<"Wynik wyszukiwania: ";

        for(int i=0;i<n;i++)
        {
            if(wyszukiwarka==p[i].miasto)
            {
                cout<<" --------------------------------------"<<endl;
                cout<<"   Imie:          "<<p[i].imie<<endl;
                cout<<"   Nazwisko:      "<<p[i].nazwisko<<endl;
                cout<<"   Miasto:        "<<p[i].miasto<<endl;
                cout<<"   Kod pocztowy:  "<<p[i].kod_pocztowy<<endl;
                cout<<"   Ulica:         "<<p[i].ulica<<endl;
                cout<<"   Numer budynku: "<<p[i].nr_budynku<<endl;
                cout<<"   Numer lokalu:  "<<p[i].nr_lokalu<<endl;
                cout<<" --------------------------------------"<<endl;
            }
        }
        break;


    case 4 :
        cout<<"--- Twoj wybor: Osoby mieszkajace przy ulicy ---"<<endl;
        cout<<"*--- Podaj nazwe ulicy: " ;
        cin>>wyszukiwarka;
        cout<<"Wynik wyszukiwania: "<<endl;

        for(int i=0; i<n; i++)
        {
            if(wyszukiwarka==p[i].ulica)
            {
                cout<<" --------------------------------------"<<endl;
                cout<<"   Imie:          "<<p[i].imie<<endl;
                cout<<"   Nazwisko:      "<<p[i].nazwisko<<endl;
                cout<<"   Miasto:        "<<p[i].miasto<<endl;
                cout<<"   Kod pocztowy:  "<<p[i].kod_pocztowy<<endl;
                cout<<"   Ulica:         "<<p[i].ulica<<endl;
                cout<<"   Numer budynku: "<<p[i].nr_budynku<<endl;
                cout<<"   Numer lokalu:  "<<p[i].nr_lokalu<<endl;
                cout<<" --------------------------------------"<<endl;
            }
        }
        break;

    default:cout<<"Podales zla wartosc."<<endl;
        }
}


int main()
{
    int n=0;
	int menu;
	cout<<"Program do zarzadzania baza adresow"<<endl;
	setlocale( LC_ALL, "pl_PL" );

    while (menu!=0)
    {
    cout<<"   *---------- MENU ----------*"<<endl;
        cout<<"        |              |"<<endl;
        cout<<"        |   1 Dodaj    |"<<endl;
        cout<<"        |   2 Pokaz    |"<<endl;
        cout<<"        |   3 Usun     |"<<endl;
        cout<<"        |   4 Szukaj   |"<<endl;
        cout<<"        |   5 Zapisz   |"<<endl;
        cout<<"        |   0 Koniec   |"<<endl;
        cout<<"*--------------------------*"<<endl;
        cout<<"*--- Twoj wybor: "  ;
        cin>>menu;


    switch (menu)
    {

            case 1:
                {   dodajOsobe(n);
                    cout<<endl;
                }
                break;


            case 2:
                {   wczytajOsoby(n);
                    wyswietlOsoby(n);
                    cout<<endl;
                }
                break;


            case 3:
                {   wczytajOsoby(n);
                    usunOsobe(n);
                    cout<<endl;
                }
                break;



            case 4:
                {   wczytajOsoby(n);
                    wyswietlOsoby(n);
                    szukajOsobe(n);
                }
                break;


            case 5:
                {    zapiszOsobe(n);
                    cout<<endl;
                }
                break;

    }

            cout<<endl;
}
    cout<<"Koniec programu!!"<<endl;

return 0;
}
