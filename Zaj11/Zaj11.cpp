#include <iostream>
#include <string>
using string = std::string;

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();

int main() {
  /*
  zad1();
  zad2();
  zad3();
  zad5();
   */
  zad4();
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

class pojazd {
private:
  double max_predkosc;
  int masa;
public:
  pojazd(double a, int b) :max_predkosc(a), masa(b) {}
  ~pojazd(void) {}
  void setpre(double a) { max_predkosc = a; }
  void setmasa(int a) { masa = a; }
  double getpre(void) { return max_predkosc; }
  int getmasa(void) { return masa; }

  virtual int getdrzwi(void) { return -1; };
  virtual double getdlugosc(void) { return -1; };
};

class samochod :public pojazd {
private:
  int ilosc_drzwi;
  double dlugosc;
public:
  samochod(double a, int b, int c, double d) : pojazd(a, b), ilosc_drzwi(c), dlugosc(d) {}
  ~samochod() {}
  void setdrzwi(int a) { ilosc_drzwi = a; }
  void setdlugosc(double a) { dlugosc = a; }
  int getdrzwi(void) { return ilosc_drzwi; }
  double getdlugosc(void) { return dlugosc; }
};

void wyswietl(pojazd* s) {
  std::cout << "maksymalna predkosc: " << s->getpre() << std::endl;
  std::cout << "masa: " << s->getmasa() << std::endl;
  std::cout << "ilosc drzwi: " << s->getdrzwi() << std::endl;
  std::cout << "dlugosc: " << s->getdlugosc() << std::endl;
}

void zad3() {
  samochod bmw(220.0, 1000, 5, 3.5);
  wyswietl(&bmw);
}

class osoba {
private:
  string imie;
  string nazwisko;
protected:
  string plec;
public:
  osoba(string a, string b, string c) : imie(a), nazwisko(b), plec(c) {};
  ~osoba(void) {};

  void set_imie(string a) {
    imie = a;
  }

  void set_nazwisko(string a) {
    nazwisko = a;
  }

  void set_plec(string a) {
    plec = a;
  }

  string get_imie(void) {
    return imie;
  }

  string get_nazwisko(void) {
    return nazwisko;
  }

  string get_plec(void) {
    return plec;
  }

  virtual int get_indeks(void) { return 0; }
  virtual string get_kierunek(void) { return "-"; }
};

class student :public osoba {
private:
  int indeks;
  string kierunek;
public:
  student(string a, string b, string c, int d, string e) : osoba(a, b, c), indeks(d), kierunek(e) {};
  ~student(void) {};

  void set_indeks(int a) {
    indeks = a;
  }

  void set_kierunek(string a) {
    kierunek = a;
  }

  int get_indeks(void) {
    return indeks;
  }

  string get_kierunek(void) {
    return kierunek;
  }
};

void wypisz(osoba* o) {
  std::cout << "imie " << o->get_imie() << std::endl;
  std::cout << "nazwisko " << o->get_nazwisko() << std::endl;
  std::cout << "plec " << o->get_plec() << std::endl;
  std::cout << "indeks " << o->get_indeks() << std::endl;
  std::cout << "kierunek " << o->get_kierunek() << std::endl;
}

void zad4() {
  student pierwszy("Jan", "Kwiatkowski", "M", 001, "informatyka");
  wypisz(&pierwszy);
}
