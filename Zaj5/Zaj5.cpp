// TODO NA KOLOKWIUM nauczyc się UML

#include <iostream>
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
  zad5();
  zad6();
  */
  zad4();
}

class samochod {
private:
  static int ilosc;  //zmienna statyczna
public:
  samochod(void) { ilosc++; }
  ~samochod(void) {
    std::cout << "\n\nDekonstruktor";
  }

  int get_ilosc(void) {
    return ilosc;
  };
};
int samochod::ilosc = 0;  //wyzerowanie
void zad1();

void zad1() {
  /* Napisz program który będzie liczył i podawał ilość samochodów w rodzinie. Na początku
  tworzymy klasę samochod. W klasie tworzymy statyczną zmienną „ilosc” która będzie przetrzymywać
  ilość samochodów w rodzinie. Zmienna „liosc” musi być wyzerowana na początku programu. Aby coś
  wpisać do zmiennej należy zrobić to po za ciałem klasy (pod klasą). Przepisz klasę oraz uzupełnij
  metodę „get_ilosc”:
  class samochod
  {
  private:
   static int ilosc;  //zmienna statyczna
  public:
   samochod(void) {ilosc++;}
   ~samochod(void) {}
   int get_ilosc(void);
  };
  int samochod::ilosc=0;  //wyzerowanie

  Teraz sprawdźmy ilość samochodów. Przepisz funkcję main, a następnie dopisz samochód babci i
  dziadka oraz siostry:
  int main(int argc, char** argv) {

   //samochod dla taty
   samochod dla_taty;
   std::cout<<"Samochod taty "<<std::endl;
   std::cout<<"ilosc samochodow w rodzinie: "<<dla_taty.get_ilosc()<<std::endl;

   //samochod dla mamy
   samochod dla_mamy;
   std::cout<<"Samochod mamy "<<std::endl;
   std::cout<<"ilosc samochodow w rodzinie: "<<dla_taty.get_ilosc()<<std::endl;

   //w koncu samochod dla mnie
   samochod moj;
   std::cout<<"Samochod moj "<<std::endl;
   std::cout<<"ilosc samochodow w rodzinie: "<<moj.get_ilosc()<<std::endl;

   //policzmy jeszcze raz ilosc samochodow w rodzinie, kazdy liczy
   std::cout<<std::endl;
   Napisz program który będzie liczył i podawał ilość samochodów w rodzinie. Na początku
  tworzymy klasę samochod. W klasie tworzymy statyczną zmienną „ilosc” która będzie przetrzymywać
  ilość samochodów w rodzinie. Zmienna „liosc” musi być wyzerowana na początku programu. Aby coś
  wpisać do zmiennej należy zrobić to po za ciałem klasy (pod klasą). Przepisz klasę oraz uzupełnij
  metodę „get_ilosc”:
  class samochod
  {
  private:
   static int ilosc;  //zmienna statyczna
  public:
   samochod(void) {ilosc++;}
   ~samochod(void) {}
   int get_ilosc(void);
  };
  int samochod::ilosc=0;  //wyzerowanie

  Teraz sprawdźmy ilość samochodów. Przepisz funkcję main, a następnie dopisz samochód babci i
  dziadka oraz siostry:
  int main(int argc, char** argv) {

   //samochod dla taty
   samochod dla_taty;
   std::cout<<"Samochod taty "<<std::endl;
   std::cout<<"ilosc samochodow w rodzinie: "<<dla_taty.get_ilosc()<<std::endl;

   //samochod dla mamy
   samochod dla_mamy;
   std::cout<<"Samochod mamy "<<std::endl;
   std::cout<<"ilosc samochodow w rodzinie: "<<dla_taty.get_ilosc()<<std::endl;

   //w koncu samochod dla mnie
   samochod moj;
   std::cout<<"Samochod moj "<<std::endl;
   std::cout<<"ilosc samochodow w rodzinie: "<<moj.get_ilosc()<<std::endl;

   //policzmy jeszcze raz ilosc samochodow w rodzinie, kazdy liczy
   std::cout<<std::endl;
  std::cout<<"tata wyliczyl ilosc samochodow w rodzinie: "<<dla_taty.get_ilosc()<<std::endl; //1
   std::cout<<"mama wyliczyla ilosc samochodow w rodzinie:

  "<<dla_mamy.get_ilosc()<<std::endl; //2
   std::cout<<"ja policzylem ilosc samochodow w rodzinie: "<<moj.get_ilosc()<<std::endl; //3

  //dopisz samochod dziadka, babci, siostry
   */

  samochod dla_taty;
  std::cout << "Samochod taty " << std::endl;
  std::cout << "ilosc samochodow w rodzinie: " << dla_taty.get_ilosc() << std::endl;

  samochod dla_mamy;
  std::cout << "Samochod mamy " << std::endl;
  std::cout << "ilosc samochodow w rodzinie: " << dla_mamy.get_ilosc() << std::endl;

  samochod moj;
  std::cout << "Samochod moj " << std::endl;
  std::cout << "ilosc samochodow w rodzinie: " << moj.get_ilosc() << std::endl;
  std::cout << std::endl;

  std::cout << "tata wyliczyl ilosc samochodow w rodzinie: " << dla_taty.get_ilosc() << std::endl; //1
  std::cout << "mama wyliczyla ilosc samochodow w rodzinie:" << dla_mamy.get_ilosc() << std::endl; //2
  std::cout << "ja policzylem ilosc samochodow w rodzinie: " << moj.get_ilosc() << std::endl; //3
  std::cout << std::endl;

  samochod dla_babci;
  std::cout << "Samochod babci " << std::endl;
  std::cout << "ilosc samochodow w rodzinie: " << dla_babci.get_ilosc() << std::endl;

  samochod dla_dziadka;
  std::cout << "Samochod dziadka " << std::endl;
  std::cout << "ilosc samochodow w rodzinie: " << dla_dziadka.get_ilosc() << std::endl;

  samochod dla_siostry;
  std::cout << "Samochod siostry " << std::endl;
  std::cout << "ilosc samochodow w rodzinie: " << dla_siostry.get_ilosc() << std::endl;

  std::cout << "babcia wyliczyla ilosc samochodow w rodzinie: " << dla_babci.get_ilosc() << std::endl; //1
  std::cout << "dziadek wyliczyl ilosc samochodow w rodzinie:" << dla_dziadka.get_ilosc() << std::endl; //2
  std::cout << "siostra wyliczyla ilosc samochodow w rodzinie: " << dla_siostry.get_ilosc() << std::endl; //3
}

class rodzina {
private:
  string imie;
  static int konto;
public:
  rodzina(string x) : imie(x) {}
  ~rodzina(void) {
    std::cout << "\nDekonstruktor";
  }
  string get_imie(void) {
    return imie;
  };
  void wyplata(int x) {
    konto += x;
  };
  void zakupy(int x) {
    konto -= x;
  };
  int stan_konta(void) {
    return konto;
  };
};

int rodzina::konto = 1000;

void zad2() {
  /*
  Napisz program który będzie sumował dochody oraz wydatki pieniędzy. Klasa nazywa się
  rodzina. Każdy nowy obiekt jest członkiem rodziny i ma swoje imię. Jednakże mamy zmienną
  statyczną „konto” która przetrzymuje stan konta całej rodziny. Na początku programu zainicjalizuj
  zmienną „konto” kwotą 1000zł. Dopisz ciała metod brakujących do klasy poniżej

  class rodzina
  {
  private:
   string imie;
   static int konto;
  public:
   rodzina(string x): imie(x) {}
   ~rodzina(void) {}
   string get_imie(void);
   void wyplata(int x);
   void zakupy(int x);
   int stan_konta(void);
  };

  Przetestujmy działanie programu:
  int main(int argc, char** argv) {
    rodzina tata("Adam");
    tata.wyplata(2000);
    std::cout<<"Tata ma na imie "<<tata.get_imie()<<std::endl;
    rodzina mama("Renata");
    std::cout<<"Mama ma na imie "<<mama.get_imie()<<std::endl;
    mama.wyplata(2000);
    rodzina dziecko("Robert");
    std::cout<<"Dziecko ma na imie "<<dziecko.get_imie()<<std::endl;

    std::cout<<"Mamy na wspolnym koncie bankowym "<<mama.stan_konta()<<"zl"<<std::endl;

    std::cout<<"Zakupy za 550zl"<<std::endl;
    mama.zakupy(550);
    std::cout<<"Mamy na wspolnym koncie bankowym "<<mama.stan_konta()<<"zl"<<std::endl;

    std::cout<<"Zakupy za 110zl"<<std::endl;
    mama.zakupy(110);
    std::cout<<"Mamy na wspolnym koncie bankowym "<<mama.stan_konta()<<"zl"<<std::endl;

    std::cout<<"Zakupy za 110"<<std::endl;
    tata.zakupy(110);
    std::cout<<"Mamy na wspolnym koncie bankowym "<<tata.stan_konta()<<"zl"<<std::endl;

    std::cout<<"Zakupy za 50"<<std::endl;
    dziecko.zakupy(110);
    std::cout<<"Mamy na wspolnym koncie bankowym "<<dziecko.stan_konta()<<"zl"<<std::endl;
  }
  */

  rodzina tata("Adam");
  tata.wyplata(2000);
  std::cout << "Tata ma na imie " << tata.get_imie() << std::endl;
  rodzina mama("Renata");
  std::cout << "Mama ma na imie " << mama.get_imie() << std::endl;
  mama.wyplata(2000);
  rodzina dziecko("Robert");
  std::cout << "Dziecko ma na imie " << dziecko.get_imie() << std::endl;

  std::cout << "Mamy na wspolnym koncie bankowym " << mama.stan_konta() << "zl" << std::endl;

  std::cout << "Zakupy za 550zl" << std::endl;
  mama.zakupy(550);
  std::cout << "Mamy na wspolnym koncie bankowym " << mama.stan_konta() << "zl" << std::endl;

  std::cout << "Zakupy za 110zl" << std::endl;
  mama.zakupy(110);
  std::cout << "Mamy na wspolnym koncie bankowym " << mama.stan_konta() << "zl" << std::endl;

  std::cout << "Zakupy za 110" << std::endl;
  tata.zakupy(110);
  std::cout << "Mamy na wspolnym koncie bankowym " << tata.stan_konta() << "zl" << std::endl;

  std::cout << "Zakupy za 50" << std::endl;
  dziecko.zakupy(110);
  std::cout << "Mamy na wspolnym koncie bankowym " << dziecko.stan_konta() << "zl" << std::endl;
};

class sprzedaz {
private:
  static double utarg;
public:
  sprzedaz(void) {
    // std::cout << "Konstruktor\n\n";
  }

  ~sprzedaz(void) {
    std::cout << "\nDekonstruktor";

  }

  void wystawParagon(double x) {
    utarg += x;
  };

  static double raport(void) {
    return utarg;
  };
};

double sprzedaz::utarg = 100.12;

void zad3() {
  /*
  Napisz program który symuluje sprzedaż sklepiku osiedlowego. Na początku mamy klasę
  sprzedaż. Gdzie mamy pole statyczne „utarg”, statyczną metodę raport oraz zwykłą metodę
  wystawParagon. Pole utarg jest zainicjalizowany cyfrą 100.12 (tyle zostało pieniędzy w kasie z
  poprzedniego dnia). Następnie mamy metodę „wystawParagon” która kwotę podaną jako argument
  dodaje do utargu. Druga metoda jest statyczna i nazywa się utarg. Jest to metoda odpowiedzialna za
  zwracanie kwoty utargu (kwoty pieniędzy w kasie). Metody statyczne mogą działać tylko na
  zmiennych statycznych (nie ma dostępu do zmiennych niestatycznych), ale dzięki temu możemy je
  wywołać jeszcze przed utworzeniem pierwszego obiektu. Oczywiście też możemy wywoływać
  metodę na każdym obiekcie i zwróci nam to samo. Implementacja metody „raport” po za ciałem
  klasy już nie używa specyfikatora „static”. Uzupełnij brakujące ciała metod do klasy „sprzedaz” która
  wygląda w ten sposób:

  class sprzedaz
  {
  private:
   static double utarg;
  public:
   sprzedaz(void) {}
   ~sprzedaz(void) {}

   void wystawParagon(double x);
   static
    double raport(void);
  };

  Po uzupełnieniu klasy teraz możemy zasymulować działanie programu:
  int main(int argc, char** argv) {
   //nowy dzien, sprawdzmy czy mamy jakis utarg z wczoraj
   cout<<"Utarg na poczatku dnia "<<sprzedaz::raport()<<endl;  //(1)

   //sprzedajemy jablka
   sprzedaz jablka;
   jablka.wystawParagon(20.23);
   cout<<"Sprzedane jablka za kwote 20.23zl"<<endl;

   //sprzedajemy kiwi
   sprzedaz kiwi;
   kiwi.wystawParagon(48.69);
   cout<<"Sprzedane kiwi za kwote 48.69zl"<<endl;

   //zobaczmy ile mamy pieniedzy w kasie
   cout<<"Utarg w dniu "<<sprzedaz::raport()<<endl;   //(2)

   //sprzedajemy arbuza
   sprzedaz arbuz;
   arbuz.wystawParagon(8.94);
   cout<<"Sprzedane arbuzy za kwote 8.94zl"<<endl;

   //sprzedajemy winogrono
   sprzedaz winogrono;
   winogrono.wystawParagon(55.09);
   cout<<"Sprzedane kiwi za kwote 55.09zl"<<endl;

   //zobaczmy ile mamy pieniedzy w kasie
   cout<<"Utarg w dniu "<<kiwi.raport()<<endl;    //(3)
  }

  Linijka z komentarzem (1) ukazuje nam bardzo ważną cechę statycznych metod i pól. Zobaczmy że
  wywołaliśmy metodę „raport” a jeszcze nie mamy utworzonego żądnego obiektu. Oczywiście ta
  metoda działa na statycznym polu „utarg”. Zobacz że do wywołania metody statycznej trzeba napisać
  nazwę klasy i dwa dwukropki (operator zakresu widoczności) „sprzedaz::”. Mając już utworzony
  obiekt też można posłużyć się taka konstrukcją. Pokazuje to linijka z komentarzem (2). Oczywiście
  mając kilka utworzonych obiektów możemy wywołać metodę na obojętnie którym obiekcie (we
  wszystkich przypadkach dostaniemy ten sam wynik bo działamy na polu statycznym). Pokazuje to
  linijka z komentarzem (3). Poniżej mamy zdjęcie z działającego programu.
  */

  std::cout << "Utarg na poczatku dnia " << sprzedaz::raport() << std::endl;  //(1)

  //sprzedajemy jablka
  sprzedaz jablka;
  jablka.wystawParagon(20.23);
  std::cout << "Sprzedane jablka za kwote 20.23zl" << std::endl;

  //sprzedajemy kiwi
  sprzedaz kiwi;
  kiwi.wystawParagon(48.69);
  std::cout << "Sprzedane kiwi za kwote 48.69zl" << std::endl;

  //zobaczmy ile mamy pieniedzy w kasie
  std::cout << "Utarg w dniu " << sprzedaz::raport() << std::endl;   //(2)

  //sprzedajemy arbuza
  sprzedaz arbuz;
  arbuz.wystawParagon(8.94);
  std::cout << "Sprzedane arbuzy za kwote 8.94zl" << std::endl;

  //sprzedajemy winogrono
  sprzedaz winogrono;
  winogrono.wystawParagon(55.09);
  std::cout << "Sprzedane kiwi za kwote 55.09zl" << std::endl;

  //zobaczmy ile mamy pieniedzy w kasie
  std::cout << "Utarg w dniu " << kiwi.raport() << std::endl;    //(3)
}
class prostokat {
private:
  int bok1;
  int bok2;

public:
  prostokat(int x, int y) : bok1(x), bok2(y) {}

  ~prostokat(void) {
    std::cout << "\nDekonstruktor";
  }

  int get_bok1(void) {
    return bok1;
  };

  int get_bok2(void) {
    return bok2;

  }

  void wymiary(void) {
    std::cout << bok1 << "m x " << bok2 << "m" << std::endl;
  }
};

int obwod(prostokat& p) {
  return 2 * p.get_bok1() + 2 * p.get_bok2();
}

int pole(prostokat& p) {
  return p.get_bok1() * p.get_bok2();
}

void klawiatura(int& a, int& b) {
  std::cout << "Podaj pierwszy wymiar: ";
  std::cin >> a;
  std::cout << "Podaj drugi wymiar: ";
  std::cin >> b;
}

void zad4() {
  /*
  Napisz który liczy długość płotu oraz wielkość działki jaką mam.
  Na początku mamy taką klasę :

  class prostokat {
  private:
    int bok1;
    int bok2;
  public:
    prostokat(int x, int y) : bok1(x), bok2(y) {}
    ~prostokat(void) {}
    int get_bok1(void);
    int get_bok2(void);
    void wymiary(void);
  };

  Uzupełnij klasę o brakujące ciała metod.Metoda wymiary ma wyświetlić wymiary działki w ten
  sposób : „{ std::cout << bok1 << "m x " << bok2 << "m" << std::endl; }”
  Oprócz klasy mamy trzy funkcje takie jak :

  int obwod(prostokat& p)
  int pole(prostokat& p)
  void klawiatura(int& a, int& b)

  Uzupełnij funkcje o ciało. Dla podpowiedzi funkcja pole wygląda w ten sposób :
  {
    return p.get_bok1() * p.get_bok2();
  }

  Sprawdźmy czy funkcja main działa poprawnie :

  int main(int argc, char** argv) {
    int x, y;
    klawiatura(x, y);

    prostokat dzialka(x, y);
    std::cout << std::endl << "Masz dzialke o wymiarach: ";
    dzialka.wymiary();

    std::cout << "Dlugosc plotu to " << obwod(dzialka) << "m" << std::endl;
    std::cout << "Pole dzialki to " << pole(dzialka) << "m^2" << std::endl;
  }
  */

  int x, y;
  klawiatura(x, y);

  prostokat dzialka(x, y);
  std::cout << std::endl << "Masz dzialke o wymiarach: ";
  dzialka.wymiary();

  std::cout << "Dlugosc plotu to " << obwod(dzialka) << "m" << std::endl;
  std::cout << "Pole dzialki to " << pole(dzialka) << "m^2" << std::endl;
}

void zad5();
void zad6();
