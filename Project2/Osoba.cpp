 #include "Osoba.h"
 #include <iostream>

 Osoba::Osoba(string nazwisko, string imie, string adres) : nazwisko(nazwisko), imie(imie), adres(adres){}


 void Osoba::odczytaj() {
  cout<<"Podaj nazwikso: ";
  getline(cin,nazwisko);
  cout<< "Podaj imie";
  getline(cin, imie);
  cout<<"podaj adres";
  getline(cin,adres);
 }


 void Osoba::wyswietl() {
  cout <<"Nawisko: "<<nazwisko<<endl;
  cout << "imie: " << imie << endl;
  cout <<"Adres: "<<adres<<endl;
 }

















