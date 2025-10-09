#pragma once

#include "Osoba.h"

class Pracownik : public Osoba {
 private:

 int indeks;
 double pensja;
 
 public:

 Pracownik();

 Pracownik(string nazwisko, string imie, string adres, int indeks, double pensja);


 void odczytaj() override;
 void wyswietl() override;
 double dochod() const override;

 
 
 };