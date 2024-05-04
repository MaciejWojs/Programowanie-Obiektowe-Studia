#include <iostream>

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();

int main() {
  zad2();
  /*
    zad1();
    zad3();
    zad4();
    zad5();
    zad6();
    */
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
