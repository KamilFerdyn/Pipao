#include "zlozal.h" // wlaczenie pliku z deklaracjami klas do badania zlozonosci algorytmow
#include <ctime> // wlaczenie pozostalych plikow biblioteki standardowej
#include <iostream>
#include <iomanip>
using namespace std;

//
// Definicja skladowych 
// klasy Algorytm
//

Algorytm::Algorytm(): n_(-1)
{}

Algorytm::~Algorytm()
{}

void Algorytm::Ustaw(int n)
{
 n_ = n;
}

//
// Definicja skladowych 
// klasy Maszyna
//

Maszyna::Maszyna(int n1,int n2,int dn,int m):
 n1_(n1), n2_(n2), dn_(dn), // ustawienie parametrow procedury badan
 iliter_(m)
{
 ilczas_ = (n2_-n1_)/dn_+1; // podzial dziedziny zlozonosci czasowej
 n2_ = n1_+(ilczas_-1)*dn_;
 czas_ = new double[ilczas_]; // utworzenie tablicy wynikow badan
}

Maszyna::~Maszyna()
{
 delete[] czas_; // zniszczenie tablicy wynikow badan
}

void Maszyna::Uruchom(Algorytm& Alg)
{
    alg_ = Alg.Nazwa(); 
    for (int i = 0; i < ilczas_; i++) {
        int n = n1_ + i * dn_; 
        Alg.Ustaw(n); 

        clock_t start = clock(); 
        for (int j = 0; j < iliter_; j++) {
            Alg.Wykonaj(); 
        }
        clock_t end = clock();

        double elapsed = double(end - start) / CLOCKS_PER_SEC;
        czas_[i] = elapsed / iliter_; 
    }
}

void Maszyna::Wyswietl() const
{
 cout << "Zlozonosc czasowa algorytmu " << alg_ << ":" << endl;
 cout << "    n    |  T [ms]" << endl;
 cout << "---------+----------" << endl;
 for (int i=0; i<ilczas_; i++) {
  int n = n1_+i*dn_; // rozmiar wejscia algorytmu do 100 mln
  double T = 1000*czas_[i]; // czas w milisekundach
  //cout << setw(8) << n  << endl;// << " | " << setw(7) << setprecision(6) << T << endl; 
  cout  << setw(7) << setprecision(6) << T << endl; 
 }
 cout << endl;
}
 

