#pragma once



#include "Osoba.h"

class Dostawca : public Osoba {
 private:
 string hurtownia;
 double wydatki;
              
 public:
 Dostawca();
 
 Dostawca(string nazwisko, string imie, string adres, string hurtownia, double wydatki);
 


 void odczytaj()override;
 void wyswietl() const override;

 double dochod() const override; 
 
 
 
 
 
 
 
 
 
 
 
 
 
 };