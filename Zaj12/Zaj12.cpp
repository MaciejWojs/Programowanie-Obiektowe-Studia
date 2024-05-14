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

class osoba {
private:
  string imie;
  string nazwisko;
public:
  osoba(void) :imie(""), nazwisko("") {}
  osoba(string a, string b) :imie(a), nazwisko(b) {}

  virtual ~osoba(void) {}
  void setImie(string a) {
    imie = a;
  }

  void setNazwisko(string a) {
    nazwisko = a;
  }

  string getImie(void) {
    return imie;
  }

  string getNazwisko(void) {
    return nazwisko;
  }

  virtual void wyswietl(void) = 0;
};

class student : public osoba {
private:
  int album;
  string kierunek;
public:
  student(void) :osoba(), album(0), kierunek("") {}
  student(string a, string b, int c, string d) : osoba(a, b), album(c), kierunek(d) {}
  ~student(void) {}

  void setAlbum(int a) {
    album = a;
  }

  void setKierunek(string a) {
    kierunek = a;
  }

  int getAlbum(void) {
    return album;
  }

  string getKierunek(void) {
    return kierunek;
  }

  virtual void wyswietl(void) {
    std::cout << "Jestem studentem\nnazywam sie " << getImie() << ' ' << getNazwisko() << "\nmoj nr albumu to " << album << ", kierunek to " << kierunek << '\n';
  };
};

class pracownik : public osoba {
private:
  string stopien;
  int wyplata;

public:
  pracownik(void) : osoba(), stopien(""), wyplata(0) {};
  pracownik(string a, string b, string c, int d) : osoba(a, b), stopien(c), wyplata(d) {};
  ~pracownik(void) {};

  void setStopien(string a) {
    stopien = a;
  }

  void setWyplata(int a) {
    wyplata = a;
  }

  string getStopien(void) {
    return stopien;
  }

  int getWyplata(void) {
    return wyplata;
  }

  virtual void wyswietl() {
    std::cout << "Jestem pracownikiem\nnazywam sie " << getImie() << ' ' << getNazwisko() << "\nmoj stopien naukowy to " << stopien << ", zarabiam " << wyplata << "zl\n";
  }
};

void zad2() {
  osoba* osoby[5] = {
    new pracownik("Jan","Kowalski","dr.",2000),
    new student("Oskar","Kwiatkowski",10012,"informatyka"),
    new student("Mieczyslaw","Sroka",10014,"informatyka"),
    new student("Pawel","Baran",10015,"informatyka"),
    new student("Patrycja","Biel",10018,"informatyka")
  };

  for (int i = 0;i < 5;i++) {
    osoby[i]->wyswietl();
    std::cout << std::endl;
  }

  for (int i = 4;i >= 0;i--) {
    delete osoby[i];
  }
}

class figura2 {
private:
  int a;
public:
  figura2(int x) : a(x) {};
  ~figura2(void) {};

  void setBokA(int x) {
    a = x;;
  }

  int getBokA(void) {
    return a;
  }

  virtual void rysuj(void) = 0;
};

class kwadrat2 : public figura2 {
public:
  kwadrat2(int x) : figura2(x) {};
  ~kwadrat2(void) {};

  virtual void rysuj(void) {
    for (int i = 0; i < getBokA(); i++) {
      for (int j = 0; j < getBokA(); j++) {
        if (j == 0 || j == getBokA() - 1 || i == 0 || i == getBokA() - 1) {
          std::cout << '*';
        } else {
          std::cout << ' ';
        }
      }
      std::cout << std::endl;
    }

  }
};

class prostokat2 : public figura2 {
private:
  int b;
public:
  prostokat2(int x, int y) : figura2(x), b(y) {};
  ~prostokat2(void) {};

  void setBokB(int x) {
    b = x;
  };

  int  getBokB(void) {
    return b;
  }

  virtual void rysuj(void) {
    for (int i = 0; i < getBokA(); i++) {
      for (int j = 0; j < getBokB(); j++) {
        if (j == 0 || j == getBokB() - 1 || i == 0 || i == getBokA() - 1) {
          std::cout << '*';
        } else {
          std::cout << ' ';
        }
      }
      std::cout << std::endl;
    }

  }
};

void zad3() {
  kwadrat2 kw(5);
  kw.rysuj();
  std::cout << std::endl << std::endl;

  prostokat2 pr(5, 7);
  pr.rysuj();
  std::cout << std::endl << std::endl;

  figura2* f;
  f = &kw;
  f->rysuj();
}

class figura3 {
public:
  virtual void out(std::ostream& o) = 0;
  friend std::ostream& operator<<(std::ostream& o, figura& f);
};

std::ostream& operator<<(std::ostream& o, figura3& f) {
  o << "-->>";
  f.out(o);
  o << "<<--";
  return o;
}

class kwadrat3 : public figura3 {
private:
  int x;
public:
  kwadrat3(int a) : figura3(), x(a) {}
  ~kwadrat3() {}

  int getx(void) {
    return x;
  }

  void out(std::ostream& o) {
    o << " kwadrat o wymiarach " << x << " x " << x << " ";
  }
};

class szescian : public kwadrat3 {
private:
  int h;
public:
  szescian(int a, int b) : kwadrat3(a), h(b) {};
  ~szescian() {};

  void out(std::ostream& o) {
    o << " szescian o wymiarach " << getx() << " x " << getx() << " x " << h << " ";
  }
};

class prostokat3 : public figura3 {
private:
  int a;
  int b;
public:
  prostokat3(int x, int y) : figura3(), a(x), b(y) {};
  ~prostokat3() {};

  void out(std::ostream& o) {
    o << " prostokat o wymiarach " << a << " x " << b << ' ';
  }
};

void zad4() {
  kwadrat3 kw(5);
  std::cout << kw;
  std::cout << std::endl;

  szescian sz(3, 4);
  std::cout << sz;
  std::cout << std::endl;

  prostokat3 pr(3, 6);
  std::cout << pr << std::endl;
}

class silnik {
private:
  double pojemnosc;
  int moc;
public:
  silnik(void) :pojemnosc(0), moc(0) {}
  silnik(double a, int b) :pojemnosc(a), moc(b) {}
  ~silnik() {}

  void setpojemnosc(double a) {
    pojemnosc = a;
  }

  void setmoc(int a) {
    moc = a;
  }

  double getpojemnosc(void) {
    return pojemnosc;
  }

  int getmoc(void) {
    return moc;
  }
};

class skrzynia_biegow {
private:
  int ilosc;
public:
  skrzynia_biegow(void) : ilosc(0) {}
  skrzynia_biegow(int a) : ilosc(a) {}
  ~skrzynia_biegow(void) {}

  void setilosc(int a) {
    ilosc = a;
  }

  int getilosc(void) {
    return ilosc;
  }
};

class samochod : public silnik, public skrzynia_biegow {
private:
  int rok_produkcji;
public:
  samochod(void) : samochod(0.0, 0, 0, 0) {}
  samochod(double poj, int moc_silnika, int ilosc_biegow, int rok) : silnik(poj, moc_silnika), skrzynia_biegow(ilosc_biegow), rok_produkcji(rok) {}
  ~samochod() {}

  void wypisz() {
    std::cout << "Samochod\nrok produkcji: " << rok_produkcji << "\nilosc biegow: " << getilosc() << "\npojemnosc silnika: " << getpojemnosc() << "\nmoc silnika: " << getmoc() << '\n';
  }
};

void zad5() {
  samochod* bmw = new samochod(1.9, 120, 6, 2022);
  bmw->wypisz();
  delete bmw;
  std::cout << std::endl;

  samochod audi(2.1, 150, 5, 2021);
  audi.wypisz();
}
