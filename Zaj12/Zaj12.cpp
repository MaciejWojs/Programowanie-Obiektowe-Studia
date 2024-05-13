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
  new student("Patrycja","Biel",10018,"informatyka") };

  for (int i = 0;i < 5;i++) {
    osoby[i]->wyswietl();
    std::cout << std::endl;
  }

  for (int i = 4;i >= 0;i--) {
    delete osoby[i];
  }
}
