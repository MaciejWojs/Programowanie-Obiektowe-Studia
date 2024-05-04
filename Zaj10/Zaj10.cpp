#include <iostream>

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();

int main() {
  zad1();
  /*
    zad2();
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

