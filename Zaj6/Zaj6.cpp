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
  zad3();
  /*
  zad1();
  zad2();
  zad4();
  zad5();
  zad6();
   */
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
