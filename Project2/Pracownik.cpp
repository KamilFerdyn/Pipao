#include "Pracownik.h"
#include <iostream>

Pracownik::Pracownik(): Osoba(), indeks(0), pensja(0.0){}


Pracownik:: Pracownik(string nazwisko, string imie, string adres, int indeks, double pensja) : Osoba (nazwisko, imie, adres), indeks(indeks), pensja(pensja){}


void Pracownik :: odczytaj() {
 Osoba::odczytaj();
 cout<<"Podaj indeks: ";
 cin>>indeks;
 cout<<"Podaj pensje: ";
 cin>>pensja;


}



void Pracownik::wyswietl() const {
 Osoba::wyswietl();
 cout<<"indeks: "<<indeks<<endl;
 cout << "pensja: " << pensja << endl;



}



double Pracownik::dochod()const {
 return pensja;
}













