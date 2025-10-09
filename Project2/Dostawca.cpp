#include "Dostawca.h"
#include <iostream>

Dostawca::Dostawca() : Osoba(), hurtownia(""), wydatki(0.0){}

Dostawca:: Dostawca(string nazwisko, string imie, string adres, string hurtownia, double wydatki) : Osoba(nazwisko, imie, adres), hurtownia(hurtownia), wydatki(wydatki){}



void Dostawca:: odczytaj() {
 Osoba:: odczytaj(); 
 cout<<"Podaj nazwe hurtowni ";
 getline(cin, hurtownia);
 cout<<"podaj wydatki";
 cin>>wydatki;

 
}


void Dostawca::wyswietl()const {
 Osoba::wyswietl();
 cout<<"hurtownia: "<<hurtownia<<endl;
 cout << "wydatki: " << wydatki << endl;

}


void Dostawca::dochod()const {

}



















