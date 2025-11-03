#include <iostream> // wlaczenie plikow biblioteki standardowej
#include "algfun.h" // wlaczenie pliku z algebra funktorow

using namespace std; // dekaracje uzycia elementow z przestrzeni nazw
using namespace Algebra;

// Prosta procedura operaujaca na podanym funktorze
//
real Calka(Funktor F, real a=0.0, real b=1.0, real dx=0.001) 
{
 real wynik=0.0;
 real dx2 = 0.5*dx;
 for (real x=a; x<b; x+=dx) {
  real y=F(x+dx2);
  wynik+=y*dx;
 }
 return wynik;
}
void testDzialaniePlus() {
    Funktor x = Funktor::_x_;
    Funktor f1 = 2 * x + 3; // Funkcja f1 = 2 * x + 3
    Funktor f2 = x + 5; // Funkcja f2 = x + 5

    // Dodanie funkcji: f1 + f2 = (2 * x + 3) + (x + 5)
    Funktor f3 = f1 + f2;

    cout << "Funkcja f3(1) = " << f3(1.0) << endl;  // Obliczanie wartoœci f3 dla x = 1
    cout << "Funkcja f3(2) = " << f3(2.0) << endl;  // Obliczanie wartoœci f3 dla x = 2
}



void testDzialanieRazy() {
    Funktor x = Funktor::_x_;
    Funktor f1 = 2 * x + 3;  // Funkcja f1 = 2 * x + 3
    Funktor f2 = x + 5;      // Funkcja f2 = x + 5

    // Mno¿enie funkcji: f1 * f2 = (2 * x + 3) * (x + 5)
    Funktor f3 = f1 * f2;

    cout << "Funkcja f3(1) = " << f3(1.0) << endl;  // Obliczanie wartoœci f3 dla x = 1
    cout << "Funkcja f3(2) = " << f3(2.0) << endl;  // Obliczanie wartoœci f3 dla x = 2
}




void testDzialanieDziel() {
    Funktor x = Funktor::_x_;
    Funktor f1 = 2 * x + 3;  // Funkcja f1 = 2 * x + 3
    Funktor f2 = x + 5;      // Funkcja f2 = x + 5

    // Dzielenie funkcji: f1 / f2 = (2 * x + 3) / (x + 5)
    Funktor f3 = f1 / f2;

    cout << "Funkcja f3(1) = " << f3(1.0) << endl;  // Obliczanie wartoœci f3 dla x = 1
    cout << "Funkcja f3(2) = " << f3(2.0) << endl;  // Obliczanie wartoœci f3 dla x = 2
}




// Program z przykladam tworzenia i uzycia funktorow
//
int main()
{
 {
  Funktor pi = Funktor::_pi_;
  Funktor x = Funktor::_x_;
  
  Funktor F = sqr( 11.5*sin(6*pi*x) ); // utworzenie funktora o podanym wzorze algebraicznym w postaci wyrazenia obiektowego
 
  cout << "F(1) = " << F(1.0) << endl; // obliczenie wartosci p/w funktora dla podanej wartosci zmiennej 'x'
  cout << "F(2) = " << F(2.0) << endl;
 }
 {
  real I1 = Calka( sqrt(2*Funktor::_x_) ); // utworzenie tymczasowego funktora o podanym wzorze i przekazanie go do procedury obliczania calki z funktora
  real I2 = Calka( exp(Funktor::_x_+1) );

  cout << "calka1 = " << I1 << endl;
  cout << "calka2 = " << I2 << endl;
  testDzialaniePlus();
  cout << endl;
  testDzialanieRazy();
  cout << endl;
  testDzialanieDziel();
  cout << endl;
 }



 return 0;
}
