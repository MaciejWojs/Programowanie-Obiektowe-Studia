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
    zad5();
    zad6();
    */
  zad4();
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

void zad4() {
  //tworzymy ulubioną książkę 
  pozycja powiesc("Sienkiewicz", "Krzyzacy", 2001);
  std::cout << "Moja ulubiona ksiazka" << std::endl;
  std::cout << "Tytul: " << powiesc.wypisz_tytul() << std::endl;
  std::cout << "Rok wydania: " << powiesc.wypisz_rok() << std::endl;
  std::cout << std::endl;

  //tworzymy ulubioną książkę naukową 
  wielopozycja2 naukowa("Grebosz", "Opus magnum C++", 2018, "programowanie", "trzy");
  std::cout << "Moja ulubiona ksiazka naukowa" << std::endl;
  std::cout << "Tytul: " << naukowa.wypisz_tytul() << std::endl;
  std::cout << "Autor: " << naukowa.wypisz_autor() << std::endl;
  std::cout << "Rok wydania: " << naukowa.wypisz_rok() << std::endl;
  std::cout << "Kategoria: " << naukowa.wypisz_kategoria() << std::endl;
  std::cout << "Ilosc czesci: " << naukowa.wypisz_ilosc_czesci() << std::endl;
  std::cout << std::endl;
}
