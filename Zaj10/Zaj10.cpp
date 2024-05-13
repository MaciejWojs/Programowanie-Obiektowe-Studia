#include <iostream>
using string = std::string;

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();

int main() {
  /*
    zad1();
    zad2();
    zad3();
    zad4();
    zad5();
    */
  zad6();
}

class bazowa {
private:
  int prywatna;
protected:
  int chroniona;
public:
  int publiczna;
};

class pochodna : public bazowa {
public:
  void funkcja(void) {
    // prywatna = 5;
    // chroniona = 6;
    publiczna = 7;
  }
};

void zad1() {
  pochodna a;
  a.funkcja();
}

class liczba {
private:
  int liczba1;
public:
  liczba(void) : liczba(0) {};
  liczba(int z) : liczba1(z) {};
  ~liczba(void) {};

  void wczytaj(int z) {
    std::cout << "Podaj liczbe: ";
    std::cin >> liczba1;
  }

  int wypisz(void) {
    return liczba1;
  }
};

class operacja {
private:
  liczba* a;
  liczba* b;
public:
  operacja() {
    a = NULL;
    b = NULL;
  }
  operacja(liczba* x, liczba* y) : a(x), b(y) {};
  ~operacja(void) {
    if (a != NULL) delete a;
    if (b != NULL) delete b;
  }

  void ustaw1(int z) {
    *a = z;
  }

  void ustaw2(int z) {
    *b = z;
  }

  int druk1(void) {
    return a->wypisz();
  }

  int druk2(void) {
    return b->wypisz();
  }

  int dodaj(void) {
    if (a->wypisz() > 0 && b->wypisz() > 0)
      return a->wypisz() + b->wypisz();
    else
      return -1;
  }
};

void zad2() {
  operacja B(new liczba, new liczba(5));
  B.ustaw1(-4);
  std::cout << "liczba 1: " << B.druk1() << std::endl;
  std::cout << "liczba 2: " << B.druk2() << std::endl;

  std::cout << "suma liczb " << B.dodaj() << std::endl;
}

class pozycja {
private:
  string autor;
  string tytul;
  int rok;  //rok wydania 

public:
  pozycja(string a, string b, int c) : autor(a), tytul(b), rok(c) {};
  ~pozycja() {};

  string wypisz_autor(void) {
    return autor;
  }

  string wypisz_tytul(void) {
    return tytul;
  }

  int wypisz_rok(void) {
    return rok;
  }
};

class wielopozycja : public pozycja {
private:
  string kategoria;
  string ilosc_czesci;
public:
  wielopozycja(string a, string b, int c, string d, string e) : pozycja(a, b, c), kategoria(d), ilosc_czesci(e) {};
  ~wielopozycja() {};

  string wypisz_kategoria(void) {
    return kategoria;
  }

  string wypisz_ilosc_czesci() {
    return ilosc_czesci;
  }
};

void zad3() {
  //tworzymy ulubioną książkę 
  pozycja powiesc("Sienkiewicz", "Krzyzacy", 2001);
  std::cout << "Moja ulubiona ksiazka" << std::endl;
  std::cout << "Tytul: " << powiesc.wypisz_tytul() << std::endl;
  std::cout << "Rok wydania: " << powiesc.wypisz_rok() << std::endl;
  std::cout << std::endl;

  //tworzymy ulubioną książkę naukową 
  wielopozycja naukowa("Grebosz", "Opus magnum C++", 2018, "programowanie", "trzy");
  std::cout << "Moja ulubiona ksiazka naukowa" << std::endl;
  std::cout << "Tytul: " << naukowa.wypisz_tytul() << std::endl;
  std::cout << "Autor: " << naukowa.wypisz_autor() << std::endl;
  std::cout << "Rok wydania: " << naukowa.wypisz_rok() << std::endl;
  std::cout << "Kategoria: " << naukowa.wypisz_kategoria() << std::endl;
  std::cout << "Ilosc czesci: " << naukowa.wypisz_ilosc_czesci() << std::endl;
  std::cout << std::endl;
}

class wielopozycja2 : private pozycja {
private:
  string kategoria;
  string ilosc_czesci;
public:
  wielopozycja2(string a, string b, int c, string d, string e) : pozycja(a, b, c), kategoria(d), ilosc_czesci(e) {};
  ~wielopozycja2() {};

  string wypisz_kategoria(void) {
    return kategoria;
  }

  string wypisz_ilosc_czesci() {
    return ilosc_czesci;
  }
};


//Zakomentowane aby sie kompilowalo 
// To zadanie nie dziala - celowa trudnosc?

// void zad4() {
//   //tworzymy ulubioną książkę 
//   pozycja powiesc("Sienkiewicz", "Krzyzacy", 2001);
//   std::cout << "Moja ulubiona ksiazka" << std::endl;
//   std::cout << "Tytul: " << powiesc.wypisz_tytul() << std::endl;
//   std::cout << "Rok wydania: " << powiesc.wypisz_rok() << std::endl;
//   std::cout << std::endl;

//   //tworzymy ulubioną książkę naukową 
//   wielopozycja2 naukowa("Grebosz", "Opus magnum C++", 2018, "programowanie", "trzy");
//   std::cout << "Moja ulubiona ksiazka naukowa" << std::endl;
//   std::cout << "Tytul: " << naukowa.wypisz_tytul() << std::endl;
//   std::cout << "Autor: " << naukowa.wypisz_autor() << std::endl;
//   std::cout << "Rok wydania: " << naukowa.wypisz_rok() << std::endl;
//   std::cout << "Kategoria: " << naukowa.wypisz_kategoria() << std::endl;
//   std::cout << "Ilosc czesci: " << naukowa.wypisz_ilosc_czesci() << std::endl;
//   std::cout << std::endl;
// }

class kalkulator {
private:
  int liczba1;
  int liczba2;

protected:
  kalkulator(void) {};
  ~kalkulator(void) {};
  void set1(int a) {
    liczba1 = a;
  }
  void set2(int a) {
    liczba2 = a;
  }
  int get1(void) {
    return liczba1;
  }
  int get2(void) {
    return liczba2;
  }
  int dodawanie(void) {
    return liczba1 + liczba2;
  }
  int odejmowanie(void) {
    return liczba1 - liczba2;
  }
};

class interfejs : private kalkulator {
public:
  interfejs(void) : kalkulator() {};
  ~interfejs(void) {};
  int wczytaj(int a, int b) {
    kalkulator::set1(a);
    kalkulator::set2(b);
    bool sukces = false;
    if (kalkulator::get1() == a && kalkulator::get2() == b) {
      sukces = true;
    }
    return sukces;
  }

  int suma(void) {
    return kalkulator::get1() + kalkulator::get2();
  }

  int roznica(void) {
    return kalkulator::get1() - kalkulator::get2();
  }
};

int podaj(int a) {
  std::cout << "Podaj";
  switch (a) {
  case 1: std::cout << " pierwsza"; break;
  case 2: std::cout << " druga"; break;
  case 3: std::cout << " trzecia"; break;
  case 4: std::cout << " czwarta"; break;
  default: std::cout << "";
  }
  std::cout << " cyfre wieksza do zera ";
  int temp;
  std::cin >> temp;
  return temp;
}

void zad5() {
  interfejs kal;
  std::cout << "Program kalkulator, dziala tylko na dodatnich cyfrach" << std::endl;
  int x, y;
  x = podaj(1);
  y = podaj(2);
  if (!kal.wczytaj(x, y))
    std::cout << "Bledne dane, uruchom program jeszcze raz z poprawnymi danymi" << std::endl;
  else {
    std::cout << "suma liczb to: " << kal.suma() << std::endl;
    std::cout << "roznica liczb to: " << kal.roznica();
  }
}

class _2D {
private:
  int bok_a;
  int bok_b;
public:
  _2D(void) : bok_a(0), bok_b(0) {};
  _2D(int a, int b) : bok_a(a), bok_b(b) {};
  ~_2D(void) {};

  void wczytaj(int a, int b) {
    bok_a = a;
    bok_b = b;
  }

  int wypisz_a(void) {
    return bok_a;
  }
  int wypisz_b(void) {
    return bok_b;
  }
};

class _3D {
private:
  int wys;
public:
  _3D(void) : wys(0) {};
  _3D(int a) : wys(a) {};
  ~_3D(void) {};

  void wczytaj(int a) {
    wys = a;
  }

  int wypisz(void) {
    return wys;
  }
};

class szescian : public _2D, public _3D {
public:
  szescian(void) : _2D(), _3D() {};
  szescian(int a, int b, int c) : _2D(a, b), _3D(c) {};
  ~szescian(void) {};
  int objetosc(void) {
    return _2D::wypisz_a() * _2D::wypisz_b() * _3D::wypisz();
  }
};

void zad6() {
  szescian x;
  x._2D::wczytaj(2, 2);
  x._3D::wczytaj(2);
  std::cout << "szescian o wymiarach 2x2x2" << std::endl;
  std::cout << "objetosc szescianu to: " << x.objetosc() << std::endl;

  szescian y(3, 3, 3);
  std::cout << "szescian o wymiarach 3x3x3" << std::endl;
  std::cout << "objetosc szescianu to: " << y.objetosc();
}
