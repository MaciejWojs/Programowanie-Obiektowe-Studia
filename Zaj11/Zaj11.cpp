#include <iostream>
#include <string>
using string = std::string;

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();

int main() {
  zad1();
  /*
    zad2();
    zad3();
    zad4();
    zad5();
   */
}

class figura {
protected:
  int a;
  int b;
public:
  figura() : figura(0, 0) {};
  figura(int x, int y) : a(x), b(y) {};
  void klawiatura(void) {
    std::cout << "Podaj elementy na figure \nbok 1: ";
    std::cin >> a;
    std::cout << "bok 2: ";
    std::cin >> b;
  }
  void wyswietl(void) {
    std::cout << "FIGURA\no bokach " << a << "x" << b;
  }
};

class kwadrat :public figura {
public:
  kwadrat(void) : figura(0, 0) {};
  ~kwadrat(void) {}
  void klawiatura(void) {
    std::cout << "Podaj elementy do zbudowania kwadratu \nbok 1: ";
    std::cin >> a;
    b = a;
  }

  void wyswietl(void) {
    std::cout << "KWADRAT\no bokach " << a << "x" << b;
  }
};

void zad1() {
  figura f;
  f.klawiatura();
  f.wyswietl();
  std::cout << std::endl;

  kwadrat k;
  k.klawiatura();
  k.wyswietl();
  std::cout << std::endl;
  k.figura::wyswietl();
}
