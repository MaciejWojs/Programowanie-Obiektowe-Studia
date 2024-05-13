#include <iostream>

class baza {
protected:
  int a;
  int b;
public:
  baza(void) {
    a = 0;
    b = 0;
  }

  ~baza() {}

  virtual void klawiatura(void) {
    std::cout << "Podaj a: ";
    std::cin >> a;
    std::cout << "Podaj b: ";
    std::cin >> b;
  }

  virtual void wyswietl(void) {
    std::cout << "Figura o bokach " << a << ' ' << b << '\n';
  }
};


class pochodna : public baza {
public:
  pochodna(void) {}
  ~pochodna(void) {}

  void klawiatura(void) {
    std::cout << "Podaj bok";
    std::cin >> a;
    b = 0;
  }

  void  wyswietl(void) {
    std::cout << "kwadrat: " << a << " x " << b << '\n';
  }
};
int main() {
  /* baza b;
  b.klawiatura();
  b.wyswietl(); */

  // p.klawiatura();
  // p.wyswietl();
  // p.baza::klawiatura();

  // baza* ws;
  // pochodna p;
  // ws = &p;
  // ws->klawiatura();
  // ws->wyswietl();
  // ((pochodna*)ws)->wyswietl();
  // ws->baza::wyswietl();


  // pochodna* ws;
  // baza b;
  // ws = &b;
  // ws->klawiatura();

  baza *ws = new pochodna;
  ws->klawiatura();
  ws->wyswietl();
  
}
