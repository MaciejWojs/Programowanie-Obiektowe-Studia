#include <iostream>
#include <string>
using string = std::string;

void zad1();
void zad2();
void zad3();
void zad4();

int main() {
  /*
    zad1();
   zad2();
    zad4();
  */
  zad3();
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

class silnik {
private:
  double pojemnosc;
  int ilosc_cylindrow;

public:
  silnik(void) :pojemnosc(0.0), ilosc_cylindrow(0) {}
  silnik(int p, int i) : pojemnosc(p), ilosc_cylindrow(i) {}
  ~silnik() {}

  void set_pojemnosc(double p) {
    pojemnosc = p;
  }

  void set_ilosc_cylindrow(int i) {
    ilosc_cylindrow = i;
  }

  double get_pojemnosc(void) {
    return pojemnosc;
  }

  int get_ilosc_cylindrow(void) {
    return ilosc_cylindrow;
  }
};

class skrzynia {
private:
  string rodzaj;
  int ilosc_biegow;

public:
  skrzynia(void) :skrzynia("brak", 0) {};
  skrzynia(string r, int i) :rodzaj(r), ilosc_biegow(i) {}
  ~skrzynia(void) {}

  void set_rodzaj(string r) {
    rodzaj = r;
  }

  void set_ilosc_biegow(int i) {
    ilosc_biegow = i;
  }

  string get_rodzaj(void) {
    return rodzaj;
  }

  int get_ilosc_biegow(void) {
    return ilosc_biegow;
  }
};

class samochod {
private:
  string kolor;
  string marka;
  silnik Silnik;
  skrzynia Skrzynia;
public:
  samochod(void) : kolor(""), marka("") {}
  samochod(string k, string m, double p, int c, string r, int i) : kolor(k), marka(m), Silnik(p, c), Skrzynia(r, i) {};
  ~samochod(void) {}

  void wypisz(void) {
    std::cout << "Marka: " << marka << std::endl;;
    std::cout << "Kolor: " << kolor << std::endl;;
    std::cout << "Pojemnosc silnika: " << Silnik.get_pojemnosc() << std::endl;
    std::cout << "Ilosc cylindrow: " << Silnik.get_ilosc_cylindrow() << std::endl;
    std::cout << "Skrzynia biekow rodzaj: " << Skrzynia.get_rodzaj() << std::endl;
    std::cout << "Ilosc biegow: " << Skrzynia.get_ilosc_biegow() << std::endl;
  }
};

void zad2() {
  samochod moj;
  moj.wypisz();
  std::cout << std::endl;

  samochod taty("czarny", "BMW", 2.1, 6, "automat", 6);
  taty.wypisz();
  std::cout << std::endl;

  samochod mamy("czerwony", "Skoda", 1.7, 5, "reczna", 5);
  mamy.wypisz();
  std::cout << std::endl;
}


class liczba {
private:
  int a;

public:
  liczba(void) : liczba(0) {}
  liczba(int x) :a(x) {}
  ~liczba(void) {}

  void setLiczba(int l) {
    a = l;
  }

  int getLiczba(void) {
    return a;
  }
};

class sejf {
private:
  liczba z;

public:
  sejf(liczba& x) : z(x) {};
  ~sejf() {};

  liczba& odczytaj(void) {
    return z;
  }

  void zapisz(liczba& x) {
    z = x;
  }
};

void zad3() {
  liczba A(23);
  sejf S(A);
  std::cout << "liczba: " << S.odczytaj().getLiczba() << std::endl;

  liczba B;
  B.setLiczba(66);
  S.zapisz(B);
  std::cout << "liczba: " << S.odczytaj().getLiczba() << std::endl;
}

