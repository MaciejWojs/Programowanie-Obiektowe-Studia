// TODO NA KOLOKWIUM nauczyc się UML

#include <iostream>
void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();

int main() {
  std::cout << "cokolwiek";
  zad1();
  /*
  zad2();
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

void zad2();
void zad3();
void zad4();
void zad5();
void zad6();
