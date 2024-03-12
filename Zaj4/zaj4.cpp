#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <cstring>
using string = std::string;

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
    return 0;
}

void zad1() {
    /*
    Napisz program który liczy cenę brutto. Podana jest klasa „koszt” którą należy uzupełnić
    o brakujące elementy. Klasa ma mieć tylko jeden konstruktor z dwoma argumentami (zmienne cena
    i podatek), przy czym zmienna podatek ma mieć domyślny argument 23. Następnie musimy mieć
    destruktor który w tym wypadku jest pusty oraz metodę „brutto” która nic nie pobiera a zwraca typ double.

    Klasa: koszt
    class koszt
    {
    private:
    double cena;
    int podatek;
    public:
    //uzupelnic
    };

    Gdy już mamy uzupełnioną klasę spróbujmy sprawdzić działanie jej w funkcji main:

    int main(int argc, char** argv) {
    double cen;
    int pod;

    //wywołanie konstruktora
    cout<<"Podaj cene towaru: ";
    cin>>cen;
    cout<<"Podaj stawke podatku: ";
    cin>>pod;
    koszt towar(cen, pod);
    cout<<"Cena brutto: "<<towar.brutto()<<endl;

    //wywołanie konstruktora z domyslnym argumentem
    cout<<"Podaj cene towaru: ";
    cin>>cen;
    koszt ksiazka(cen);
    cout<<"Cena brutto: "<<ksiazka.brutto()<<endl;
    return 0;
    }

    Przetestuj program czy poprawnie działa.
    */
    class koszt {
        private:
        double cena;
        int podatek;

        public:
        koszt() : cena(0), podatek(0) {};
        koszt(double c, int p = 23) : cena(c), podatek(p) {};

        ~koszt() {
            std::cout << "\n\nDestruktor";
        }

        double brutto() {
            return ((cena * podatek) / 100) + cena;
        }
    };

    double cen;
    int pod;

    std::cout << "Podaj cene towaru: ";
    std::cin >> cen;
    std::cout << "Podaj stawke podatku: ";
    std::cin >> pod;
    koszt towar(cen, pod);
    std::cout << "Cena brutto: " << towar.brutto() << std::endl << '\n';

    std::cout << "Podaj cene towaru: ";
    std::cin >> cen;
    koszt ksiazka(cen);
    std::cout << "Cena brutto: " << ksiazka.brutto() << std::endl;
}