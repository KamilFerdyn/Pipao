/********************
 *
 * Plik naglowkowy z deklaracjami klas
 * przeznaczonymi do realizacji algebry 
 * dowolnych funktorow rzeczywistych
 *
 */
#ifndef ALGFUN_H_
#define ALGFUN_H_

// dodatkowa konfiguracja dla kompilatora MSVC
//
#pragma warning(disable:4244)
#pragma warning(disable:4996 4005)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#ifndef __cplusplus
# error C++ compiler required
#endif

///////////////////////////////////////////////
//
// Przestrzen nazw zawierajaca elementy 
// do definiowania wzorow dowolnych funktorow 
// na podstawie wyrazen algebraicznych
// podanych w kodzie zrodlowym programu
//
namespace Algebra {

// Pomocnicze definicje typow.
//
typedef int integer;
typedef double real;

// Klasa bazowa dla wyrazen definiujacych
// wzory funkcji. Wszystkie klasy pochodne
// okreslajace rozne rodzaje wyrazen zostaly
// zdefiniowane w pliku algfun.cpp.
//
class Wyrazenie {
  int licznik_; // licznik dowiazan do obiektu wyrazenia umozliwiajacy bezpieczne wspoldzielenie tego obiektu
 private: // kopiowanie obiektu wyrazenia jest niezdefiniowane
  Wyrazenie(Wyrazenie &);
  void operator=(Wyrazenie &);
 public:
  Wyrazenie(): licznik_(0) // tworzy nowy obiekt wyrazenia, na poczatku bez wlasciciela
  {}
  
  virtual ~Wyrazenie() // wirtualny destruktor umozliwia poprawne usuwanie obiektow wyrazenia
  {}
  
  Wyrazenie *przylacz() // umozliwia polaczenie wspoldzielonego obiektu wyrazenia z obiektem wlasciciela
  {
   ++licznik_;
   return this;
  }
  
  void odlacz()// umozliwia odlaczenie wspoldzielonego obiektu wyrazenia od obiektu wlasciciela
  {
   --licznik_;
   if (licznik_<=0) delete this; // usuwa obiekt wyrazenia gdy obiekt ten nie ma zadnego wlasciciela
  }
  
  virtual real wartosciuj(real x) = 0; // glowna funkcja wykonawcza obiektu wyrazenia, zwraca wartosc wyrazenia dla podanej wartosci zmiennej 'x'
                                       // funkcja musi byc zdefiniowana w klasach pochodnych
};

// Pojedyncza klasa reprezentujaca dowolna funkcje
// ktorej wzor algebraiczny zadany jest poprzez zlozone
// wyrazenie obiektowe. Poniewaz obiekty tej klasy
// zachowuja sie jak funkcje matematyczne, wiec
// zostaly nazwane funktorami. 
// 
class Funktor {
  Wyrazenie *wzor_; // wskaznik do struktury (grafu) obiektow wyrazenia stanowiacego wzor funktora
  explicit Funktor(Wyrazenie *W); // prywatny konstruktor funktora dla podanego wzoru (explicit - musi byc wywolywany jawnie)
 public:
  static const Funktor _pi_; // pomocnicze funktory stalych matematycznych
  static const Funktor _x_; // funktor w postaci nazwy zmiennej 'x'
  
  Funktor(); // konstruktor domyslny, tworzy funktor zmiennej 'x'
  Funktor(integer c); // konstruktor tworzy funktor stalej calkowitej 'c'
  Funktor(real c); // konstruktor tworzy funktor stalej rzeczywistej 'c'

  ~Funktor(); // destruktor, usuwa strukture wzoru funktora

  Funktor(const Funktor &F); // kopiowanie funktorow, prowadzi do wspoldzielnia strukury wzoru
  Funktor &operator=(const Funktor &F);

  real operator()(real x) const // operator funkcji zwracajacy wartosc funktora dla podanej wartosci zmiennej 'x' na podstawie wzoru funktora
  { 
   return wzor_->wartosciuj(x);
  }  
  
  friend Funktor abs(const Funktor &F); // zestaw operacji tworzacych nowy funktor o postaci funkcji analitycznej
  friend Funktor log(const Funktor &F);
  friend Funktor sqr(const Funktor &F);
  friend Funktor sqrt(const Funktor &F);
  friend Funktor exp(const Funktor &F);
  friend Funktor sin(const Funktor &F);
  friend Funktor cos(const Funktor &F);
  friend Funktor operator-(const Funktor &F); // zmiana znaku na przeciwny (neg) 
  friend Funktor operator^(const Funktor &F, integer n); // potegowanie o wykladniku calkowitym (npow)

  friend Funktor operator+(const Funktor &F1, const Funktor &F2); // zestaw operacji tworzacych nowy funktor o postaci dzialania arytmetycznego
  friend Funktor operator-(const Funktor &F1, const Funktor &F2);
  friend Funktor operator*(const Funktor &F1, const Funktor &F2);
  friend Funktor operator/(const Funktor &F1, const Funktor &F2);
};

} // koniec przestrzeni nazw 'Algebra'

#endif /* koniec pliku naglowkowego 'algfun' */
