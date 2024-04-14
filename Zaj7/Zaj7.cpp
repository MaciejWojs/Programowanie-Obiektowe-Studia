#include <iostream>
#include <ostream>
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
   */
}

class moj_typ {
private:
  double liczba;
public:
  moj_typ(void) :liczba(0.0) {}
  moj_typ(double x) :liczba(x) {}
  ~moj_typ(void) {}

  moj_typ& operator+(moj_typ& a); //zmienna+zmienna 
  moj_typ operator+(double a) {
    this->liczba += a;
    return *this;
  }  //zmienna+stała 

  moj_typ operator++() {
    return *this + 0.01;
  }   //++zmienna 
  moj_typ operator++(int) {
    return ++ * this;
  }  //zmienna++ 

  operator int();     //konwersja do typu int 

  friend moj_typ operator+(double a, moj_typ& b) {
    moj_typ temp(b.liczba);
    temp.liczba += a;
    return temp;
  }  //stała+zmienna 
  friend std::ostream& operator<<(std::ostream& o, moj_typ& m) {
    o << m.liczba;
    return o;
  }
};

moj_typ& moj_typ::operator+(moj_typ& a) {
  this->liczba += a.liczba;
  return *this;
}

// moj_typ operator+(double x, moj_typ& a) {

// }

moj_typ::operator int() {
  int x = this->liczba;
  return x;
}

void zad1() {
  //tworzymy zmienne z1, z2, z3  
  moj_typ z1(1.11);
  moj_typ z2;
  z2 = 2.22;
  moj_typ z3;

  //do z3 wpisujemy sumę z1 i z2 
  z3 = z1 + z2;
  std::cout << "z1+z2= " << z3 << std::endl;

  //sprawdzamy operator ++ 
  ++z3;
  std::cout << "++z3= " << z3 << std::endl;
  z3++;
  std::cout << "z3++= " << z3 << std::endl;

  //do z3 dodajemy 21.01  
  z3 = 21.01 + z3;
  std::cout << "21.01+z3= " << z3 << std::endl;

  //do z3 dodajemy 12.3 
  z3 = z3 + 12.3;
  std::cout << "z3+12.3= " << z3 << std::endl;

  //zapisujemy z moj_typ do int  
  int b;
  b = z3;
  std::cout << "(int)b=z3= " << b << std::endl;
}
