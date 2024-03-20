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
  std::cout << "cokolwiek";
  zad2();
  /*
  zad1();
  zad3();
  zad4();
  zad5();
  zad6();
  */
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

void zad3();
void zad4();
void zad5();
void zad6();
