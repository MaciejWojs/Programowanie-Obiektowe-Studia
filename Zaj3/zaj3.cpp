#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <cstring>
using string = std::string;

int pobierzInt(string wiadomosc) {
    int dane;
    do {
        std::cout << wiadomosc;
        std::cin >> dane;
        if (!std::cin.fail()) {
            break;
        }
        std::cout << "Podano niepoprawne dane!\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
    } while (true);
    return dane;
}

int pobierzInt_zad1(string wiadomosc) {
    int dane;
    do {
        std::cout << wiadomosc;
        std::cin >> dane;
        if (!std::cin.fail()) {
            if (dane > 0 && dane < 10)break;
            else {
                std::cout << "Podane liczby muszą zawierac sie w przedziale 1 - 9\n";
                continue;
            }
        }
        std::cout << "Podano niepoprawne dane!\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
    } while (true);
    return dane;
}

void zad1();
void zad2();
void zad3();
void zad4();
// void zad5();
// void zad6();

int main() {
    /*
    zad1();
    zad2();
    zad3();
     */
    zad4();
    // zad5();
    // zad6();

    return 0;
}

void zad1() {

    /* Napisz program suma, gdzie mamy taką klasę:
    class suma {
    private:
    int liczba1;
    int liczba2;
    public:
    suma(void);
    ~suma(void);
    int wynik(void);
    void klawiatura(void);
    };
    Mając klasę, uzupełnij metody, wraz z konstruktorem i destruktorem. Metoda klawiatura ma za
    zadanie pobrać z klawiatury dwie cyfry potrzebne do wykonania obliczeń. Metoda zabezpiecza nam
    program tak aby cyfry były tylko z przedziału <0, 9>. Czyli jak użytkownik poda ujemne cyfry to nie
    przyjmie i poprosi o kolejne wpisanie cyfry, jeśli cyfra będzie ponad 10 to też nie przyjmie i poprosi
    o kolejne podanie cyfry. Program będzie tak długo prosił o cyfry dopóki nie dostanie dwóch cyfr
    z przedziału, wtedy kończy metodę klawiatura.  funkcji main wywołaj metody klawiatura oraz
    wynik który jest sumą dwóch wprowadzonych cyfr
     */

    class suma {
        private:
        int liczba1;
        int liczba2;

        public:
        suma(void) : liczba1(0), liczba2(0) {
            std::cout << "Konstruktor\n\n";
        };

        ~suma(void) {
            std::cout << "\n\nDekonstruktor";
        };

        int wynik(void) {
            return liczba1 + liczba2;
        };

        void klawiatura(void) {
            liczba1 = pobierzInt_zad1("Podaj liczbe z zakresu <1 - 9>: ");
            liczba2 = pobierzInt_zad1("Podaj liczbe z zakresu <1 - 9>: ");
        };
    };

    suma s;
    s.klawiatura();
    std::cout << "Suma podanych liczb: " << s.wynik() << '\n';
}



void zad2() {

    /*
    Napisz program translator, gdzie mamy taką klasę:

    class translator {
        private:
            char t[3];
        public:
            translator(void);
            ~translator(void);
            void pobierz(char *cyfra);
            int zamien(void);
    };

    Mając klasę, uzupełnij metody, wraz z konstruktorem i destruktorem. Program translator ma za
    zadanie przekonwertować cyfrę podaną jako char na typ int. Metoda pobierz pobiera cyfrę dwu
    znakową typu char. Czyli przekazanie cyfry od 0 do 9 musi być poprzedzone 0 (np. jeśli chcę wpisać
    8 to wpisuję „08”). Dlatego, że to jest typ znakowy musimy cyfrę wpisywać w cudzysłowie. Jeśli
    byśmy chcieli wpisać liczbę od 10 do 99 to wpisujemy w cudzysłowie. Translator nie obsługuje liczb
    ujemnych oraz liczb powyżej 100. Metoda zamien zwraca nam liczbę już przekonwertowaną do int.
    Tu mamy funkcję pobierz. Wykorzystujemy tu funkcję kopiującą tablice. Do jej poprawnego działania
    musimy dodać bibliotekę „string.h”

    void translator::pobierz(char *cyfra){
        strcpy(t, cyfra); //#include <string.h>
    }

    Tak wygląda funkcja main. Jej zadaniem jest przekonwertowanie cyfry 89 z char na int.

    int main(int argc, char** argv) {
        translator tr;
        tr.pobierz("89");
        cout<<"zamieniona liczba: "<<tr.zamien();
        return 0;
    }
    */


    class translator {
        private:
        char t[3];

        public:
        translator(void) : t{} {};

        ~translator() {
            std::cout << "\n\nDestructor";
        }

        void pobierz(char* cyfra) {
            std::strcpy(t, cyfra);
        }

        int zamien(void) {
            return std::stoi(t);

        };
    };

    translator tr;
    tr.pobierz("89");
    std::cout << "zamieniona liczba: " << tr.zamien() << '\n';
    tr.pobierz("07");
    std::cout << "zamieniona liczba: " << tr.zamien() << '\n';
}

void zad3() {

    /*
    Napisz program kalkulator energetyczny, gdzie mamy taką klasę :
    class energetyka {
        private:
            int i;
            int u;
        public:
            energetyka(void);
            ~energetyka(void);
            int moc(void);
            void klawiatura(void);
            int get_i(void);
            int get_u(void);
    };

    Mając klasę, uzupełnij metody, wraz z konstruktorem i destruktorem.Metoda klawiatura ma za
    zadanie pobrać z klawiatury dwie cyfry potrzebne do wykonania obliczeń. Metoda moc liczy ze wzoru
    P = i * u(czyli musimy pomnożyć „i” oraz „u”).W funkcji main wywołaj wszystkie metody
    */
    class energetyka {
        private:
        int i;
        int u;

        public:
        energetyka(void) : i(0), u(0) {
            std::cout << "Konstruktor\n\n";
        }

        ~energetyka(void) {
            std::cout << "\n\nDestruktor";
        }

        int moc(void) {
            return i * u;
        }

        void klawiatura(void) {
            i = pobierzInt("Podaj natezenie pradu: ");
            u = pobierzInt("Podaj napiecie pradu: ");
        }

        int get_i(void) {
            return i;
        }

        int get_u(void) {
            return u;
        }
    };

    energetyka e;
    e.klawiatura();
    std::cout << "Napiecie: " << e.get_u() << "\nNatezenie: " << e.get_i() << '\n';
    std::cout << "Moc wynosi: " << e.moc() << '\n';
}

void zad4() {
    /*
    Napisz kolejną wersję kalkulatora gdzie mamy oto taką klasę:

    class kalkulatorek
    {
    private:
        int *liczba1;
        int *liczba2;
    public:
        kalkulatorek(void);
        ~kalkulatorek(void);
        void wczytaj(void);
        int dodawanie(void);
        int odejmowanie(void);
    };

    W klasie kalkulatorek mamy sekcję prywatną gdzie są dwa wskaźniki. W sekcji publicznej mamy
    konstruktor gdzie tworzymy zmienne dynamiczne i przypisujemy je do wskaźników. W destruktorze
    musimy pamiętać o usunięciu zmiennych dynamicznych. Metoda wczytaj wypisuje na ekran „podaj
    pierwszą liczbę” a następnie pobieramy ją. Wypisujemy kolejną wiadomość „podaj drugą liczbę”
    i wczytujemy drugą liczbę. Metoda dodawanie dodaje dwie cyfry i zwraca wynik. Metoda
    odejmowanie odejmuje dwie cyfry i zwraca wynik. Funkcja main wygląda w ten sposób:

    int main(int argc, char** argv) {
        kalkulatorek kal;
        kal.wczytaj();
        cout<<"Suma liczb: "<<kal.dodawanie()<<endl;
        cout<<"Roznica liczb: "<<kal.odejmowanie()<<endl;
        return 0;
    }
    */

    class kalkulatorek {
        private:
        int* liczba1;
        int* liczba2;

        public:
        kalkulatorek(void) {
            liczba1 = new int;
            *liczba1 = 0;
            liczba2 = new int;
            *liczba2 = 0;
            std::cout << "Konstruktor\n\n";
        }

        ~kalkulatorek(void) {
            delete liczba1;
            delete liczba2;
            std::cout << "\n\nDestruktor";
        }

        void wczytaj(void) {
            *liczba1 = pobierzInt("Podaj pierwsza liczbe: ");
            *liczba2 = pobierzInt("Podaj druga liczbe: ");
        }

        int dodawanie(void) {
            return *liczba1 + *liczba2;
        }

        int odejmowanie(void) {
            return *liczba1 - *liczba2;
        }
    };

    kalkulatorek kal;
    kal.wczytaj();
    std::cout << "Suma liczb: " << kal.dodawanie() << std::endl;
    std::cout << "Roznica liczb: " << kal.odejmowanie() << std::endl;
}