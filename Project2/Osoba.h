using namespace std;
#include <iostream>
#include <string>
#ifndef OSOBA_H
#define OSOBA_H
class Osoba {

private:

string nazwisko;
string imie;
string adres;


public: 
Osoba() : nazwisko(""), imie(""), adres(""){}
Osoba(string nazwisko, string imie, string adres) : nazwisko(nazwisko), imie(imie),adres(adres) {}


virtual void odczytaj() {
cout<<"Podaj nazwisko: ";
getline(cin,nazwisko);
cout<<"Podaj imie: ";
getline(cin,imie);
cout<<("podaj adres: ");
getline(cin, adres);


}




virtual void wyswietl() {
 cout<<"Nazwisko: "<<nazwisko<<endl;
 cout << "Imie: " << imie << endl;
 cout << "Adres: " << adres << endl;

}


virtual double dochod() const =0;





};


#endif