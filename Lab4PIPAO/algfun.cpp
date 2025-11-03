#include "algfun.h" // wlaczenie pliku z deklaracjami klas do algebry funktorow
#include <cmath> // wlaczenie plikow biblioteki standardowej

/////////////////////////////////
//
// Implementacja algebry funktorow 
// 
namespace Algebra {

// Definicja klasy wyrazenia
// przyjmujacego postac stalej
// liczby rzeczywistej
//
class Stala : public Wyrazenie {
  real wartosc_;
 public:
  Stala(real c): wartosc_(c)
  {}
  
  real wartosciuj(real)
  {
   return wartosc_;
  }
};

// Definicja klasy wyrazenia
// przyjmujacego postac zmiennej
// czyli glownego argumentu 
// funktorow
//
class Zmienna : public Wyrazenie {
 public:
  real wartosciuj(real x)
  {
   return x;
  }
};

// Definicja klasy wyrazenia
// przyjmujacego postac funkcji
// analitycznej
//
class Funkcja : public Wyrazenie {
 protected:
  Wyrazenie *argument_;
 public:
  Funkcja(Wyrazenie *W): argument_(W->przylacz())
  {}

  ~Funkcja()
  {
   argument_->odlacz();
  }
};

// Definicja klas wyrazenia
// dla konkretnych funkcji

class FunkcjaAbs : public Funkcja {
 public:
  FunkcjaAbs(Wyrazenie *W): Funkcja(W)
  {}

  real wartosciuj(real x)
  {
   real a = argument_->wartosciuj(x);
   real y = std::abs(a);
   return y;
  }
};

class FunkcjaLog : public Funkcja {
 public:
  FunkcjaLog(Wyrazenie *W): Funkcja(W)
  {}

  real wartosciuj(real x)
  {
   real a = argument_->wartosciuj(x);
   real y = std::log(a);
   return y;
  }
};

class FunkcjaSqr : public Funkcja {
 public:
  FunkcjaSqr(Wyrazenie *W): Funkcja(W)
  {}

  real wartosciuj(real x)
  {
   real a = argument_->wartosciuj(x);
   real y = a*a;
   return y;
  }
};

class FunkcjaSqrt : public Funkcja {
 public:
  FunkcjaSqrt(Wyrazenie *W): Funkcja(W)
  {}

  real wartosciuj(real x)
  {
   real a = argument_->wartosciuj(x);
   real y = std::sqrt(a);
   return y;
  }
};

class FunkcjaExp : public Funkcja {
 public:
  FunkcjaExp(Wyrazenie *W): Funkcja(W)
  {}

  real wartosciuj(real x)
  {
   real a = argument_->wartosciuj(x);
   real y = std::exp(a);
   return y;
  }
};

class FunkcjaSin : public Funkcja {
 public:
  FunkcjaSin(Wyrazenie *W): Funkcja(W)
  {}

  real wartosciuj(real x)
  {
   real a = argument_->wartosciuj(x);
   real y = std::sin(a);
   return y;
  }
};

class FunkcjaCos : public Funkcja {
 public:
  FunkcjaCos(Wyrazenie *W): Funkcja(W)
  {}

  real wartosciuj(real x)
  {
   real a = argument_->wartosciuj(x);
   real y = std::cos(a);
   return y;
  }
};

class FunkcjaNeg : public Funkcja {
 public:
  FunkcjaNeg(Wyrazenie *W): Funkcja(W)
  {}

  real wartosciuj(real x)
  {
   real a = argument_->wartosciuj(x);
   real y = -a;
   return y;
  }
};

class FunkcjaNPow : public Funkcja {
  int wykladnik_;
 public:
  FunkcjaNPow(Wyrazenie *W,integer n): Funkcja(W), wykladnik_(n)
  {}

  real wartosciuj(real x)
  {
   real a = argument_->wartosciuj(x);
   real y = 1.0;
   for (int i=0; i<wykladnik_; i++) y*=a;
   return y;
  }
};

// Definicja klasy wyrazenia
// przyjmujacego postac dzialania
// arytmetycznego
//
class Dzialanie : public Wyrazenie {
 protected:
  Wyrazenie *argument1_, *argument2_;
 public:
  Dzialanie(Wyrazenie *W1, Wyrazenie *W2): argument1_(W1->przylacz()), argument2_(W2->przylacz())
  {}

  ~Dzialanie()
  {
   argument1_->odlacz();
   argument2_->odlacz();
  }
};

// Definicja klas wyrazenia
// dla konkretnych dzialan

class DzialaniePlus : public Dzialanie {
 public:
  DzialaniePlus(Wyrazenie *W1, Wyrazenie *W2): Dzialanie(W1,W2)
  {}

  real wartosciuj(real x)
  {
   /* ...wstawic kod metody w oparciu o diagram sekwencji... */
	  real a = argument1_->wartosciuj(x);
	  real b = argument2_->wartosciuj(x); 
	  return a + b;
   
  }
};

class DzialanieMinus : public Dzialanie {
 public:
  DzialanieMinus(Wyrazenie *W1, Wyrazenie *W2): Dzialanie(W1,W2)
  {}

  real wartosciuj(real x)
  {
   /* ...wstawic kod metody w oparciu o diagram sekwencji... */
	  real a = argument1_->wartosciuj(x);
	  real b = argument2_->wartosciuj(x);
	  return a - b;
   
  }
};

class DzialanieRazy : public Dzialanie {
 public:
  DzialanieRazy(Wyrazenie *W1, Wyrazenie *W2): Dzialanie(W1,W2)
  {}

  real wartosciuj(real x)
  {
   /* ...wstawic kod metody w oparciu o diagram sekwencji... */
	  real a = argument1_->wartosciuj(x);
	  real b = argument2_->wartosciuj(x);
	  return a * b;
   
  }
};

class DzialanieDziel : public Dzialanie {
 public:
  DzialanieDziel(Wyrazenie *W1, Wyrazenie *W2): Dzialanie(W1,W2)
  {}

  real wartosciuj(real x)
  {
   /* ...wstawic kod metody w oparciu o diagram sekwencji... */
   // uwaga: sprawdzic czy wartosc mianownika jest niezerowa
	  real a = argument1_->wartosciuj(x);
	  real b = argument2_->wartosciuj(x);
	  return a / b;
   
  }
};

// Definicja skladowych 
// klasy Funktor

const Funktor Funktor::_pi_(3.14);
const Funktor Funktor::_x_;
  
Funktor::Funktor()
{
 Wyrazenie *W = new Zmienna; 
 wzor_ = W->przylacz();
}
 
Funktor::Funktor(integer c)
{
 Wyrazenie *W = new Stala(c); 
 wzor_ = W->przylacz();
} 

Funktor::Funktor(real c)
{
 Wyrazenie *W = new Stala(c); 
 wzor_ = W->przylacz();
}

Funktor::Funktor(Wyrazenie *W): wzor_(W->przylacz())
{} 

Funktor::~Funktor()
{
 wzor_->odlacz();
}

Funktor::Funktor(const Funktor &F): wzor_(F.wzor_->przylacz())
{}

Funktor &Funktor::operator=(const Funktor &F)
{
 wzor_->odlacz();
 wzor_ = F.wzor_->przylacz();
 return *this;
}

Funktor abs(const Funktor &F)
{
 return Funktor(new FunkcjaAbs(F.wzor_));
}

Funktor log(const Funktor &F)
{
 return Funktor(new FunkcjaLog(F.wzor_));
}

Funktor sqr(const Funktor &F)
{
 return Funktor(new FunkcjaSqr(F.wzor_));
}

Funktor sqrt(const Funktor &F)
{
 return Funktor(new FunkcjaSqrt(F.wzor_));
}

Funktor exp(const Funktor &F)
{
 return Funktor(new FunkcjaExp(F.wzor_));
}

Funktor sin(const Funktor &F)
{
 return Funktor(new FunkcjaSin(F.wzor_));
}

Funktor cos(const Funktor &F)
{
 return Funktor(new FunkcjaCos(F.wzor_));
}

Funktor operator-(const Funktor &F)
{
 return Funktor(new FunkcjaNeg(F.wzor_));
}

Funktor operator^(const Funktor &F, integer n)
{
 return Funktor(new FunkcjaNPow(F.wzor_,n));
}

Funktor operator+(const Funktor &F1, const Funktor &F2)
{
 return Funktor(new DzialaniePlus(F1.wzor_,F2.wzor_));
}

Funktor operator-(const Funktor &F1, const Funktor &F2)
{
 return Funktor(new DzialanieMinus(F1.wzor_,F2.wzor_));
}

Funktor operator*(const Funktor &F1, const Funktor &F2)
{
 return Funktor(new DzialanieRazy(F1.wzor_,F2.wzor_));
}

Funktor operator/(const Funktor &F1, const Funktor &F2)
{
 return Funktor(new DzialanieDziel(F1.wzor_,F2.wzor_));
}

} // koniec przestrzeni nazw 'Algebra'
