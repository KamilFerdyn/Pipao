  #include "klient.h"
  #include <iostream>

  Klient::Klient() : Osoba(), pesel(""),naleznosc(0.0){}

  Klient::Klient(string nazwisko, string imie, string adres, string pesel, double naleznosc )  : Osoba(nazwisko, imie, adres), pesel(pesel), naleznosc(naleznosc){}



  void Klient::odczytaj() {

  Osoba::odczytaj();
  cout<<"podaj pesel: ";
  getline(cin,pesel);
  cout<<"Podaj naleznosc: ";
  cin>> naleznosc;


 
  }



  void Klient::wyswietl()const {
   Osoba:wyswietl();
   cout<<"Pesel "<<pesel<<endl;
   cout << "naleznosc " << naleznosc << endl;

 }


  double Klient::dochod()const {
   return naleznosc;
 }




