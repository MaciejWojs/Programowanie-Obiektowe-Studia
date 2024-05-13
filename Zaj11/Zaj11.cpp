#include <iostream>
#include <string>
using string = std::string;

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();

int main() {
  zad2();
  /*
  zad1();
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
  virtual void klawiatura(void) {
    std::cout << "Podaj elementy na figure \nbok 1: ";
    std::cin >> a;
    std::cout << "bok 2: ";
    std::cin >> b;
  }
  virtual void wyswietl(void) {
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

void zad2() {
  figura f;
  figura* ws_f;
  ws_f = &f;
  ws_f->klawiatura();
  ws_f->wyswietl();
  std::cout << std::endl << std::endl;

  kwadrat k;
  kwadrat* ws_k;
  ws_k = &k;
  ws_k->klawiatura();
  ws_k->wyswietl();
  std::cout << std::endl << std::endl;

  //Zmieniono metody na virtualne w klasie figura
  ws_f = &k;
  ws_f->klawiatura();
  ws_f->wyswietl();
  std::cout << std::endl << std::endl;
}

