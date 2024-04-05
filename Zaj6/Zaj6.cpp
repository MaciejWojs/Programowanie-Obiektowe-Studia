#include <iostream>
#include <cstring>

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();

int main() {
  zad1();
  /*
  zad2();
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
