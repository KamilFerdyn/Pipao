// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
#include <iostream>



class Klasa {
private:
    char pole1;
    int pole2;

public:
    Klasa(char p1 = ' ', int p2 = 0) : pole1(p1), pole2(p2) {}

    int metoda1(char x) {

    }

    void metoda2(char x, int& y) {


    }
};

void main()
{
    Klasa kl('A', 20);
}



*/










/********************************************************/
/* Zwiazki posiadania i dziedziczenia klas w jezyku C++ */
/********************************************************/
/*
#include <iostream>
#include <cstring>
#define _CRT_SECURE_
using namespace std;

// Klasa do manipulowania datami wskazywanymi przez zegar
class Data {
    int dzien, miesiac, rok;
public:
    Data() : dzien(0), miesiac(0), rok(0)
    {}

    Data(int d, int m, int r) : dzien(d), miesiac(m), rok(r)
    {}

    void pobierz();
    void wyswietl(const char* odstep = "") const;
};

void Data::pobierz()
{
    do {
        cout << "podaj dzien: ";
        cin >> dzien;
    } while (dzien < 0 || dzien>31);
    do {
        cout << "podaj miesiac: ";
        cin >> miesiac;
    } while (miesiac < 0 || miesiac>12);
    do {
        cout << "podaj rok: ";
        cin >> rok;
    } while (rok < 0);
}

void Data::wyswietl(const char* odstep) const
{
    cout << odstep << "data: " << rok << '-' << miesiac << '-' << dzien << endl;
}

// Klasa reprezentujaca zegar z podstawowym wskazaniem czasu
class Zegar {
    int sekunda, minuta, godzina;
public:
    Zegar() : sekunda(0), minuta(0), godzina(0)
    {}

    Zegar(int s, int m, int g) : sekunda(s), minuta(m), godzina(g)
    {}

    void pobierz();
    void wyswietl(const char* odstep = "") const;
};

void Zegar::pobierz()
{
    do {
        cout << "podaj sekunda= ";
        cin >> sekunda;
    } while (sekunda < 0 || sekunda>60);
    do {
        cout << "podaj minuta= ";
        cin >> minuta;
    } while (minuta < 0 || minuta>60);
    do {
        cout << "podaj godzina= ";
        cin >> godzina;
    } while (godzina < 0 || godzina>24);
}

void Zegar::wyswietl(const char* odstep) const
{
    cout << odstep << "czas= " << godzina << ':' << minuta << ':' << sekunda << endl;
}

// Klasa pochodna reprezentujaca zegar z dodatkowym wskazaniem daty
class ZegarZData : public Zegar { // dziedziczenie danych z klasy 'Zegar' poprzez podobiekt podstawowy (bez nazwy)
public:
    Data datownik; // posiadanie danych z klasy 'Data' poprzez obiekt skladowy 'datownik'

    ZegarZData()
    {}

    ZegarZData(int s, int mn, int g, int d, int ms, int r) :
        Zegar(s, mn, g), // konstruktor podobiektu podstawowego
        datownik(d, ms, r) // konstruktor obiektu skladowego
    {}

    void pobierz();
    void wyswietl(const char* odstep = "") const;
};

void ZegarZData::pobierz()
{
    Zegar::pobierz(); // wywolanie metody odziedziczonej z klasy podstawowej
    datownik.pobierz(); // wywolanie metody z klasy posiadanej
}

void ZegarZData::wyswietl(const char* odstep) const
{
    static char wystep[1024];
    strcpy(wystep, odstep);
    strcat(wystep, "             ");
    cout << odstep << "Pelne wskazanie zegara>" << endl;
    Zegar::wyswietl(wystep);
    datownik.wyswietl(wystep);
}

void main()
{
    Data d(5, 11, 2004);
    d.wyswietl();
    d.pobierz();
    d.wyswietl();
    cout << "========================" << endl;

    Zegar z(12, 45, 14);
    z.wyswietl();
    z.pobierz();
    z.wyswietl();
    cout << "========================" << endl;

    ZegarZData zd(12, 45, 14, 5, 11, 2004);
    zd.wyswietl();
    zd.pobierz();
    zd.wyswietl("   ");
    cout << "========================" << endl;

    cin.ignore(2);
}


*/

//Zad3:



#include <iostream>
#include <cstring>


using namespace std;

class Podzespol {
private:
    char nazwa_[50] = {};
    char producent_[50] = {};
    double cena_;
public:
    Podzespol(const char* n, const char* p, double c) {
        strcpy(nazwa_, n);
        strcpy(producent_, p);
        cena_ = c;
    }
    const char* nazwa()  {
        return nazwa_;
    }
    const char* producent()  {
        return producent_;
    }
    double cena() {
        return cena_;
    }
    void wyswietl() {
        cout << "Nazwa: " << nazwa_ << ", producent: " << producent_ << ", cena: " << cena;
    }
};
class Komputer {
private:
    char nazwa_[50] = {};
    int lpodzespolow_;
    Podzespol** podzespoly;
    double cena;

public:
    Komputer(const char* n, int N) {
        strcpy(nazwa_, n);
        lpodzespolow_ = N;
    
    };

    Komputer& Dodaj(int ID, Podzespol* X) {

    }

    Komputer& Koniec() {}

    ~Komputer();

    const char* nazwa() {
        return nazwa_;
    }


    double cena() {
        return cena;
    }


};

void main()
{
}