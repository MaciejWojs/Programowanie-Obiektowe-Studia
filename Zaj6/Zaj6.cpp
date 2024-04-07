#include <iostream>
#include <cstring>
using string = std::string;

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();

int main() {
  /*
  zad1();
  zad2();
  zad3();
  zad4();
  zad6();
   */
  zad5();
}

class osoba {
private:
  char* imie;
  char* nazwisko;
public:
  osoba(char* a, char* b);
  ~osoba(void);

  char* getImie(void);
  char* getNazwisko(void);
};
osoba::osoba(char* a, char* b) {
  imie = new char[strlen(a) + 1];
  nazwisko = new char[strlen(b) + 1];

  strcpy(imie, a);
  strcpy(nazwisko, b);
}

osoba::~osoba(void) {
  delete[] imie;
  delete[] nazwisko;
}

char* osoba::getImie(void) {
  return imie;
}

char* osoba::getNazwisko(void) {
  return nazwisko;
}

void zad1() {
  osoba o1("Adam", "Adamowski");
  osoba o2("Patrycja", "Kwiatkowska");

  std::cout << "osoba: " << o1.getImie() << ' ' << o1.getNazwisko() << '\n';
  std::cout << "osoba: " << o2.getImie() << ' ' << o2.getNazwisko() << '\n';
}

class student {
private:
  string imie;
  int ocena;
public:
  student(void) : imie("-*-"), ocena(0) {}   //konstruktor 1 
  student(string a) : imie(a), ocena(0) {}   //konstruktor 2 
  student(string a, int b) : imie(a), ocena(b) {}  //konstruktor 3 
  ~student(void) {}

  void set_imie(string a) {
    imie = a;
  }

  void set_ocena(int a) {
    ocena = a;
  }

  string get_imie(void) {
    return imie;
  }

  int get_ocena(void) {
    return ocena;
  }

  void wyswietl(void);
};

void student::wyswietl(void) {
  std::cout << "imie: " << imie << ", ocena: " << ocena << std::endl;
}

void zad2() {
  student klasa_I[2];
  for (int i = 0; i < 2; i++) {
    klasa_I[i].wyswietl();
  }

  std::cout << std::endl << std::endl;

  student klasa_II[4] = { student("Marek"), student("Jurek",4) };
  for (int i = 0; i < 4; i++) {
    klasa_II[i].wyswietl();
  }

  std::cout << std::endl << "poprawiamy ocene Markowi na 5" << std::endl;
  klasa_II[0].set_ocena(5);
  klasa_II[0].wyswietl();

  /*
  Tabela, pozycja konstruktor
  Tabela: klasa_I, pozycja: 0        konstruktor 1
  Tabela: klasa_I, pozycja: 1        konstruktor 1
  Tabela: klasa_II, pozycja: 0       konstruktor 2
  Tabela: klasa_II, pozycja: 1       konstruktor 3
  Tabela: klasa_II, pozycja: 2       konstruktor 1
  Tabela: klasa_II, pozycja: 3       konstruktor 1
  */
}

class konto {
private:
  double stan;
  double procent;
public:
  konto(void) : stan(0), procent(0) {};

  void wplata(double x) {
    stan += x;
  }

  int wyplata(double x);
  double sprawdz_srodki(void) {
    return stan;
  }

  void ustaw_procent(double p = 0.05) {
    procent = p;
  }

  double sprawdz_procent(void) {
    return procent;
  };

  void lokata_miesieczna(void);
};

int konto::wyplata(double x) {
  if (stan >= x) {
    stan -= x;
    return 1;
  } else
    return 0;
}

void konto::lokata_miesieczna(void) {
  stan = stan + ((stan * procent) / 100);
}

void PKO(konto& k) {
  double temp;
  std::cout << std::endl << "-------------------------------------------------\n";
  std::cout << "Bank PKO, jaki procent wprowadzic \n";
  std::cout << "  (jesli podasz 0, procent pozostaje bez zmian): ";
  std::cin >> temp;
  if (temp == 0) {
    k.lokata_miesieczna();
  } else {
    k.ustaw_procent(temp);
    k.lokata_miesieczna();
  }
  std::cout << "-------------------------------------------------\n\n";
}

void zad3() {
  konto Adam;
  Adam.wplata(1000.01);
  Adam.ustaw_procent();
  std::cout << "Srodki Adama na koncie: " << Adam.sprawdz_srodki() << "zl." << std::endl;
  std::cout << "Lokata w wyskokosci: " << Adam.sprawdz_procent() << "%" << std::endl;
  Adam.wplata(1000.00); //Adam wpłaca 
  if (Adam.wyplata(130.00)) {
    std::cout << "Adam wybral pieniadze w bankomacie, stan konta: " << Adam.sprawdz_srodki() << std::endl;
  } else
    std::cout << "!!! Nie udalo sie wybrac pieniedzy" << std::endl;

  std::cout << "Po miesiacu " << std::endl;
  PKO(Adam);
  std::cout << "Srodki Adama na koncie: " << Adam.sprawdz_srodki() << "zl." << std::endl;
  std::cout << "Lokata w wyskokosci: " << Adam.sprawdz_procent() << "%" << std::endl;
}

class zakres;
class punkt {
private:
  int x;
public:
  punkt(void) :punkt(0) {}
  punkt(int z) : x(z) {}
  ~punkt(void) {}
  void podaj(void) {
    std::cout << "Podaj punkt: ";
    std::cin >> x;
  }

  friend void zbadaj(zakres& z, punkt& p);
};

class zakres {
private:
  int x;
  int y;
public:
  zakres(void) : zakres(0, 0) {}
  zakres(int a, int b) : x(a), y(b) {}
  ~zakres(void) {}
  void podaj(void) {
    std::cout << "Podaj poczatek zakresu: ";
    std::cin >> x;
    std::cout << "Podaj koniec zakresu: ";
    std::cin >> y;
  }
  friend void zbadaj(zakres& z, punkt& p);
};

void zbadaj(zakres& z, punkt& p) {
  if ((z.x <= p.x) && (z.y >= p.x))
    std::cout << "punkt miesci sie w zakresie " << std::endl;
  else
    std::cout << "punkt nie miesci sie w zakresie " << std::endl;
}

void zad4() {
  punkt p;
  zakres z;

  z.podaj();
  p.podaj();

  zbadaj(z, p);
}

class kwadrat {
  friend class interfejs;
private:
  int bok;
public:
  kwadrat(void) : bok(0) {}
  ~kwadrat(void) {}
  int pole(void) {
    return bok * bok;
  }
};



class interfejs {
public:
  interfejs(void) {}
  ~interfejs(void) {}
  void klawiatura(kwadrat& k);
  void ekran(kwadrat& k);

  int licz_pole(kwadrat& k) {
    return k.pole();
  }

  int licz_obwod(kwadrat& k) {
    return 4 * k.bok;
  }
};

void interfejs::klawiatura(kwadrat& k) {
  std::cout << "Podaj bok kwadratu: ";
  std::cin >> k.bok;  //mam dostep do prywatnego pola klasy kwadrat 
}

void interfejs::ekran(kwadrat& k) {
  std::cout << "Wpisana dlugosc boku to: " << k.bok << std::endl;
}

void zad5() {
  //tworzymy klase kwadrat  
  kwadrat kw;

  //tworzymy klase interfejs (klasa zaprzyjzniona z klasa kwadrat) 
  interfejs in;

  //korzystamy z zaprzyjaznionej klasy  
  in.klawiatura(kw);
  in.ekran(kw);

  //korzystamy z glownej klasy  
  std::cout << "Pole wynosi: " << kw.pole() << std::endl;

  std::cout << "Wyliczone pole wynosi: " << in.licz_pole(kw) << std::endl;
  std::cout << "Wyliczony obwod wynosi: " << in.licz_obwod(kw) << std::endl;
}
