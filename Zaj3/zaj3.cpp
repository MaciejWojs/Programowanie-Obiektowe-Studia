#include <iostream>
#include <limits>
#include <cmath>
using string = std::string;

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
// void zad2();
// void zad3();
// void zad4();
// void zad5();
// void zad6();

int main() {
    zad1();
    // zad2();
    // zad3();
    // zad4();
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
    z przedziału, wtedy kończy metodę klawiatura. W funkcji main wywołaj metody klawiatura oraz
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