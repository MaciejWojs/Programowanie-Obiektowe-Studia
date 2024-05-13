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
  zad4();
   */
  zad5();
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

class osoba2 {
private:
  string kolor;
  int poz_x;
  int poz_y;
protected:
  int punkty;
public:
  osoba2(void);
  osoba2(string a, int b, int c);
  ~osoba2(void) {};

  void przod(void);
  void tyl(void);
  void lewo(void);
  void prawo(void);

  void set_kolor(string a) {
    kolor = a;
  }

  string get_kolor(void) {
    return kolor;
  }

  void set_x(int a) {
    poz_x = a;
  }

  int get_x(void) {
    return poz_x;
  }

  void set_y(int a) {
    poz_y = a;
  }

  int get_y(void) {
    return poz_y;
  }

  virtual void opis_postaci(void);
};


osoba2::osoba2(void) {
  punkty = 0;
  kolor = "";
  poz_x = 0;
  poz_y = 0;
}

osoba2::osoba2(string a, int b, int c) {
  punkty = 0;
  kolor = a;
  poz_x = b;
  poz_y = c;
}

void osoba2::przod(void) {
  poz_x += 1;
}

void osoba2::tyl(void) {
  poz_x -= 1;
}

void osoba2::lewo(void) {
  poz_y -= 1;
}

void osoba2::prawo(void) {
  poz_y += 1;
}

void osoba2::opis_postaci(void) {
  std::cout << "BLAD - ZA MALO DANYCH" << std::endl;
}

class gracz :public osoba2 {
private:
  string imie;
public:
  gracz(void) : osoba2(), imie("") {};
  gracz(string a, int b, int c, string d) : osoba2(a, b, c), imie(d) {};
  ~gracz(void) {};

  void ustaw_imie(string a) {
    imie = a;
  }
  string get_imie(void) {
    return imie;
  }

  void opis_postaci(void);
};

void gracz::opis_postaci(void) {
  std::cout << std::endl;
  std::cout << "GRACZ" << std::endl;
  std::cout << "imie: " << imie << std::endl;
  std::cout << "Kolor: " << get_kolor() << std::endl;
  std::cout << "Pozycja na planszy: " << get_x() << " x " << get_y() << std::endl;
  std::cout << "Ilosc punktow: " << punkty << std::endl;
  std::cout << "===============================" << std::endl;
}

class przeciwnik :public osoba2 {
private:
  string poziom;
public:
  przeciwnik(void) : osoba2(), poziom("") {};
  przeciwnik(string a, int b, int c, string d) : osoba2(a, b, c), poziom(d) {};
  ~przeciwnik(void) {};

  void set_poziom(string a) {
    poziom = a;
  };

  string get_poziom(void) {
    return poziom;
  }

  void opis_postaci(void);
};

void przeciwnik::opis_postaci(void) {
  std::cout << std::endl;
  std::cout << "PRZECIWNIK" << std::endl;
  std::cout << "Kolor: " << get_kolor() << std::endl;
  std::cout << "Pozycja na planszy: " << get_x() << " x " << get_y() << std::endl;
  std::cout << "Ilosc punktow: " << punkty << std::endl;
  std::cout << "Poziom: " << poziom << std::endl;
  std::cout << "===============================" << std::endl;
}

void zad5() {
  gracz ja("czerwony", 10, 10, "Jan");   //tworzymy gracza 
  przeciwnik komputer("czarny", 0, 0, "podstawowy"); //tworzymy przeciwnika 

  for (int i = 0; i < 10; i++)  //przestawiamy gracza o 10 pozycji do przodu  
    ja.przod();

  for (int i = 0; i < 4; i++)  //przestawiamy przeciwnika o 4 pozycje w lewo  
    komputer.lewo();

  //zobaczmy opis 
  ja.opis_postaci();
  komputer.opis_postaci();

  //dalsza mechanika gry 
}
