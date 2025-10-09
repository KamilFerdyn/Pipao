#pragma once


#include "Osoba.h"

class Klient : public Osoba {

private:
string pesel;
double naleznosc;

public:

Klient();

Klient(string nazwisko, string imie, string adres, string pesel, double naleznosc);

void odczytaj() override






};
