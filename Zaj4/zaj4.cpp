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
    zad2();
    /*
        zad1();
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

void zad2() {
    /*
    Jest napisany program do wyliczania mocy.Mechanizm wyliczania jest zawarty w klasie
    „moc”.Mamy tam 4 konstruktory.Uzupełnij brakujące metody o ciało. Klasa wygląda w ten sposób :

    class moc {
        private:
        int volt;
        double amper;
        double wat;
        void wylicz(void) { wat = volt * amper; }
        public:
        moc() : volt(0), amper(0.0), wat(0.0) {} //konstruktor 1
        moc(int a) : volt(a), amper(0.0) { wylicz(); } //konstruktor 2
        moc(double a) : volt(230), amper(a) { wylicz(); } //konstruktor 3
        moc(int a, double b) : volt(a), amper(b) { wylicz(); } //konstruktor 4
        ~moc(void) {}
        void set_volt(int a) { volt = a; }
        void set_amper(int a);
        double get_wat(void);
    };

    Funkcja main działającego program wygląda w ten sposób :
    int main(int argc, char** argv) {
        int v;
        double a;
        cout << "Moc silnika" << endl;
        cout << "Podaj napiecie: ";
        cin >> v;
        cout << "Podaj prad: ";
        cin >> a;
        moc silnik(v, a);
        cout << "Moc silnika to: " << silnik.get_wat() << "W" << endl;
        cout << endl << "Moc zarowki" << endl;
        cout << "Podaj napiecie: ";
        cin >> v;
        cout << "Podaj prad: ";
        cin >> a;
        moc zarowka(a);
        cout << "Moc zarowki to: " << zarowka.get_wat() << "W" << endl;
        cout << endl << "Moc komputera" << endl;
        cout << "Podaj napiecie: ";
        cin >> v;
        cout << "Podaj prad: ";
        cin >> a;
        moc komp(v);
        cout << "Moc komputera to: " << komp.get_wat() << "W" << endl;
        cout << endl << "Moc TV" << endl;
        cout << "Podaj napiecie: ";
        cin >> v;
        cout << "Podaj prad: ";
        cin >> a;
        moc tv;
        cout << "Moc TV to: " << tv.get_wat() << "W" << endl;
    }

    Zastanów się i uzupełnij tabelkę który konstruktor jest wywoływany
    Obiekt:     Konstruktor:
    silnik      konstruktor 4
    zarowka     konstruktor 3
    komp        konstruktor 2
    tv          konstruktor 1
    */
    class moc {
        private:
        int volt;
        double amper;
        double wat;
        void wylicz(void) { wat = volt * amper; }

        public:
        moc() : volt(0), amper(0.0), wat(0.0) {}; //konstruktor 1

        moc(int a) : volt(a), amper(0.0) {
            wylicz();
            //konstruktor 2
        };

        moc(double a) : volt(230), amper(a) {
            wylicz();
            //konstruktor 3
        };

        moc(int a, double b) : volt(a), amper(b) {
            wylicz();
            //konstruktor 4
        };

        ~moc(void) {
            std::cout << "\n\nDestruktor";
        };

        void set_volt(int a) {
            volt = a;
        }

        void set_amper(int a) {
            amper = a;
        };

        double get_wat(void) {
            wylicz();
            return wat;
        };
    };
    int v;
    double a;
    std::cout << "Moc silnika" << std::endl;
    std::cout << "Podaj napiecie: ";
    std::cin >> v;
    std::cout << "Podaj prad: ";
    std::cin >> a;

    moc silnik(v, a);
    std::cout << "Moc silnika to: " << silnik.get_wat() << "W" << std::endl;
    std::cout << std::endl << "Moc zarowki" << std::endl;
    std::cout << "Podaj napiecie: ";
    std::cin >> v;
    std::cout << "Podaj prad: ";
    std::cin >> a;

    moc zarowka(a);
    std::cout << "Moc zarowki to: " << zarowka.get_wat() << "W" << std::endl;
    std::cout << std::endl << "Moc komputera" << std::endl;
    std::cout << "Podaj napiecie: ";
    std::cin >> v;
    std::cout << "Podaj prad: ";
    std::cin >> a;

    moc komp(v);
    std::cout << "Moc komputera to: " << komp.get_wat() << "W" << std::endl;
    std::cout << std::endl << "Moc TV" << std::endl;
    std::cout << "Podaj napiecie: ";
    std::cin >> v;
    std::cout << "Podaj prad: ";
    std::cin >> a;

    moc tv;
    std::cout << "Moc TV to: " << tv.get_wat() << "W" << std::endl;
}