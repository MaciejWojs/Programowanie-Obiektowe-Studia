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
  zad2();
  /*
  zad1();
  zad3();
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
  for (int i = 0; i < 2; i++)
    klasa_I[i].wyswietl();

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
