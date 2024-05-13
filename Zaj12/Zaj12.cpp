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
private:
  int x;

public:
  figura(void) : x(0) {};
  figura(int a) : x(a) {};
  ~figura(void) {};

  void wczytaj(int a) {
    x = a;
  }

  int wypisz(void) {
    return x;
  }

  virtual int pole(void) = 0;
  virtual int obwod(void) = 0;
  virtual void wymiary(void) = 0;
};

class kwadrat : public figura {
public:
  kwadrat(int a) : figura(a) {};
  ~kwadrat(void) {};

  int pole(void) {
    return wypisz() * wypisz();
  }

  int obwod(void) {
    return 4 * wypisz();
  }

  void wymiary(void) {
    std::cout << "kwadrat o bokach " << wypisz() << " x " << wypisz() << std::endl;
  }
};

class prostokat :public figura {
private:
  int y;
public:
  prostokat(int a, int b) : figura(a), y(b) {};
  ~prostokat() {};

  int pole(void) {
    return wypisz() * y;
  }

  int obwod(void) {
    return (2 * wypisz()) + (2 * wypisz());
  }

  void wymiary(void) {
    std::cout << "prostokat o bokach " << wypisz() << " x " << y << std::endl;
  }
};

void zad1() {
  prostokat pr(2, 4);
  kwadrat kw(5);
  figura* wsk;

  wsk = &pr;
  wsk->wymiary();
  std::cout << "obwod prostokata " << wsk->obwod() << std::endl;
  std::cout << "pole prostokata " << wsk->pole() << std::endl << std::endl;

  wsk = &kw;
  wsk->wymiary();
  std::cout << "obwod kwadratu " << wsk->obwod() << std::endl;
  std::cout << "pole kwadratu " << wsk->pole() << std::endl << std::endl;
}
