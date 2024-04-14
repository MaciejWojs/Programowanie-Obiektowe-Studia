#include <iostream>
#include <ostream>
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
  zad5();
   */
  zad4();
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

class kwadrat {
private:
  int bok;
public:
  kwadrat(void) : bok(0) {}
  kwadrat(int x) : bok(x) {}
  ~kwadrat(void) {}

  bool operator==(kwadrat& a);
  bool operator<(kwadrat& a) {
    if (this->bok < a.bok) {
      return true;
    } else {
      return false;
    }
  }

  kwadrat operator--(int) {
    this->bok -= 1;
    return *this;
  }

  kwadrat operator+=(int a) {
    this->bok += a;
    return *this;
  }

  operator double() {
    double x = (double)this->bok;
    return x;
  }

  friend std::ostream& operator<<(std::ostream& o, kwadrat& k) {
    o << k.bok << " x " << k.bok << '\n';
    return o;
  }
};

bool kwadrat::operator==(kwadrat& a) {
  if (this->bok == a.bok)
    return true;
  else
    return false;
}

void zad2() {
  kwadrat pierwszy(5);
  std::cout << "pierwszy kwadrat " << pierwszy << std::endl;

  kwadrat drugi(4);
  std::cout << "drugi kwadrat " << drugi << std::endl;

  if (pierwszy == drugi)
    std::cout << "kwadraty sa rowne" << std::endl;
  else
    std::cout << "kwadraty sa rozne" << std::endl;

  pierwszy--;
  if (pierwszy == drugi)
    std::cout << "kwadraty sa rowne" << std::endl;
  else
    std::cout << "kwadraty sa rozne" << std::endl;

  //dodajemy 5 do kwadratu 
  drugi += 5;
  std::cout << "drugi kwadrat " << drugi << std::endl;

  if (pierwszy < drugi)
    std::cout << "kwadrat drugi jest wiekszy" << std::endl;
  else
    std::cout << "kwadrat pierwszy jest wiekszy" << std::endl;

  //zapiszmy cyfre 3.45 do kwadratu pierwszego (konwertujemy double do int) 
  double liczba;
  liczba = 3.34;
  pierwszy = liczba;
  std::cout << "w zmiennej liczba jest cyfra " << liczba << std::endl;
  std::cout << "pierwszy kwadrat " << pierwszy << std::endl;
}

class zespolona {
private:
  int re;
  int im;

public:
  zespolona(void) : zespolona(0, 0) {};   //konsturktor domyślny - bezparametrowy

  zespolona(int _re, int _im) :re(_re), im(_im) {};  //konstruktor parametrowy 

  zespolona(zespolona& z) {
    this->re = z.re;
    this->im = z.im;
  };  //konstruktor kopiujący 

  zespolona(int a) :zespolona(a, 0) {};  //konstruktor konwertujący z int do zespolonej 

  ~zespolona(void) {};   //destruktor 

  zespolona& operator+(zespolona& z) {
    this->re += z.re;
    this->im += z.im;
    return *this;
  }   //do operacji typu: A+B 

  zespolona& operator+(int a) {
    this->re += a;
    return *this;
  }    //do operacji typu: A+2

  friend zespolona operator+(int a, zespolona& z) {
    zespolona x(a, 0);
    x.re += z.re;
    return x;
  } //do operacji typu: 3+A 

  operator int() {
    int w = this->re;
    return w;
  }     //konwertujemy zespoloną na int 

  friend std::ostream& operator<<(std::ostream& o, zespolona& z) {
    o << z.re << '+' << z.im << 'i';
    return o;
  } //wypisywanie 
};

void zad3() {
  zespolona A(2, 4), B, C;
  std::cout << "zespolona 1: " << A << std::endl;
  std::cout << "zespolona 2: " << B << std::endl;
  std::cout << "zespolona 3: " << C << std::endl << std::endl;

  //kopiujemy obiekt A do obiektu B 
  B = A;
  std::cout << "(kopiujemy) zespolona 2: " << B << std::endl;

  //konwertujemy cyfrę i dodajemy ją do obiektu B 
  B = 4;
  std::cout << "(konwertujemy z int) zespolona 2: " << B << std::endl;

  //dodawanie dwóch cyfr 
  C = A + B;
  std::cout << "(C=A+B), zespolona 3: " << C << std::endl;

  //dodanie do A cyfry 2 
  C = A + 2;
  std::cout << "(C=A+2), zespolona 3: " << C << std::endl;

  //dodanie cyfry 3 do A 
  C = 3 + A;
  std::cout << "(C=3+A), zespolona 3: " << C << std::endl;

  //konwetrujemy na typ int 
  std::cout << "(konwertujemy do int) zespolona 3: " << (int)C << std::endl;
}

class bilet {
private:
  int gotowka;
  int suma;
  int czas;
  float stawka;

public:
  bilet(void) : gotowka(0), suma(0), czas(0), stawka(0.0) {};
  bilet(int a) : gotowka(0), suma(0), czas(0), stawka(a) {};
  ~bilet(void) {};

  void ustaw_stawke(int a) {
    stawka = a;
  }
  int pobierz_stawke(void) {
    return stawka;
  };

  bilet& operator+(int a);

  friend std::ostream& operator<<(std::ostream& o, bilet& b);
};

bilet& bilet::operator+(int a) {
  gotowka = a;
  suma = suma + gotowka;
  czas = suma / stawka;
  return *this;
}

std::ostream& operator<<(std::ostream& o, bilet& b) {
  o << "----------------------------" << '\n';
  o << "wplaciles:       " << b.gotowka << '\n';
  o << "suma gotowki:    " << b.suma << '\n';
  o << "czas postoju: -> " << b.czas << '\n';
  o << "----------------------------" << '\n';
  return o;
}
void zad4() {
  bilet A(2);
  std::cout << "stawka godzinowa: " << A.pobierz_stawke() << std::endl;

  std::cout << A;  //wyświetlamy bilet 

  //wrzucamy 2zł, 3zł 
  A + 2 + 3;
  std::cout << A;

  //mamy trzy bilety w tabeli  
  bilet B[3];
  for (int i = 0; i < 3; i++)
    B[i].ustaw_stawke(i + 1);  //ustawiamy stawki godzinowe dla każdego  
  //biletu osobno 

//wyświetlamy trzy bilety 
  for (int i = 0; i < 3; i++)
    std::cout << B[i] << "Stawka: " << B[i].pobierz_stawke() << std::endl << std::endl;

  //wrzucamy monety   
  for (int i = 0; i < 3; i++)
    B[i] + (2 * i);   //wrzucamy monety 2*i 

  //wyświetlamy   
  std::cout << std::endl << std::endl;
  for (int i = 0; i < 3; i++)
    std::cout << B[i] << "Stawka: " << B[i].pobierz_stawke() << std::endl << std::endl;
};
