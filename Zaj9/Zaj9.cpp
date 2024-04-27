#include <iostream>
#include <string>
using string = std::string;

void zad1();
void zad2();
void zad3();
void zad4();

int main() {
  zad1();
  /*
    zad2();
    zad3();
    zad4();
  */
}


class adres {
private:
  string ul;
  int nr;

public:
  adres(void) : ul(""), nr(0) {};
  adres(string a, int b) : ul(a), nr(b) {}

  void set_ul(string a) {
    ul = a;
  }

  void set_nr(int a) {
    nr = a;
  }

  void wypisz(void) {
    std::cout << "Ulica: " << ul << '\n';
    std::cout << "nr domu: " << nr << '\n';
  }
};


class osoba {
private:
  string imie;
  string nazwisko;

public:
  osoba(void) : imie(""), nazwisko("") {}
  osoba(string i, string n) : imie(i), nazwisko(n) {}

  ~osoba() {}
  void set_imie(string i) {
    imie = i;
  }

  void set_nazwisko(string n) {
    nazwisko = n;
  }

  void wypisz(void) {
    std::cout << "Imie: " << imie << '\n';
    std::cout << "Nazwisko: " << nazwisko << '\n';
  }
};

class szkola {
private:
  int numer;
  osoba Osoba;
  adres Adres;
public:
  szkola(void) {
    numer = 0;
    Osoba;
    Adres;
  }
  szkola(int a, string ul, int nr, string i, string n) : numer(a), Adres(ul, nr), Osoba(i, n) {};
  ~szkola() {}

  void opis(void) {
    std::cout << "Numer dziennika: " << numer << '\n';
    std::cout << "uczen\n";
    Osoba.wypisz();
    std::cout << "adres ucznia\n";
    Adres.wypisz();
  }
};

void zad1() {
  szkola uczen1(1, "Limanowskiego", 33, "Adam", "Kowalski");
  uczen1.opis();
  std::cout << std::endl;
  szkola uczen2(2, "Barska", 21, "Patrycja", "Adamowska");
  uczen2.opis();
  std::cout << std::endl;
}
