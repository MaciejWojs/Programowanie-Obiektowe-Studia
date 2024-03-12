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
    zad4();
    /*
    zad1();
    zad2();
    zad3();
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

void zad3() {
    /*
    Program ma za zadanie wyliczenie kosztu zużycia paliwa.W metodzie „wylicz” należy użyć
    takiego wzoru : „(zuzycie / 100)* cena”.Poniżej jest podana klasa koszt.Uzupełnij jej metody aby
    program działał.W tej klasie widzimy dwa konstruktory.Pierwszy jest domyślny a drugi jest
    parametrowy.Gdy popatrzymy na pierwszy konstruktor widzimy po dwukropku wywołanie
    konstruktora parametrowego z dwoma parametrami(w tym wypadku 0 i 0).Taki zapis nazwany jest
    „delegowaniem konstruktora”.Gdy w funkcji main użyjemy konstruktora bez parametrowego
    program wywoła konstruktor parametrowy z wpisanymi wartościami(w tym wypadku 0 i 0).
    Kod klasy „koszt” :

    class koszt {
        private:
        double zuzycie;
        double cena;

        public:
        //konstruktor 1 domyslny
        koszt() : koszt(0.0, 0.0) {}
        //konstruktor 2 parametrowy
        koszt(double x, double y) : zuzycie(x), cena(y) {}
        ~koszt(void) {}
        void set_zuzycie(double x);
        void set_cena(double x);
        double get_zuzycie(void);
        double get_cena(void);
        double wylicz(void);
    };

    Uzupełnij metody o ciało

    Funkcja main :
    int main(int argc, char** argv) {
        double z;
        double c;
        cout << "Policzmy koszt jednego kilometra dla Opel: " << endl;
        cout << "Podaj zuzycie paliwa: ";
        cin >> z;
        cout << "Podaj cene paliwa: ";
        cin >> c;
        koszt opel; //konstruktor domyslny
        cout << "Koszt: " << opel.wylicz() << " zl. za km" << endl; //(1)
        opel.set_zuzycie(z);
        opel.set_cena(c);
        cout << "jeszcze raz koszt: " << opel.wylicz() << " zl. za km" << endl << endl; //(2)
        cout << "Policzmy koszt jednego kilometra dla VW: " << endl;
        cout << "Podaj zuzycie paliwa: ";
        cin >> z;
        cout << "Podaj cene paliwa: ";
        cin >> c;
        koszt vw(z, c); //konstruktor parametrowy
        cout << "Koszt: " << vw.wylicz() << " zl. za km" << endl;
    }

    Utworzyliśmy dwa obiekty. Pierwszy to opel a drugi to vw. Zobacz że w linijce „koszt opel;” zostaje
    wywołany konstruktor bezparametrowy, a w deklaracji klasy tam mamy delegowanie konstruktora.
    Czyli wywołanie konstruktora parametrowego z zerami. W linijce która ma w komentarzu(1)
    wyświetli nam 0 (wartości domyślne).W linijce gdzie w komentarzu mamy(2) widzimy już wyliczony
    koszt. W obiekcie vw mamy od razu wpisane dane więc od razu jest koszt wyliczany.
    */

    class koszt {
        private:
        double zuzycie;
        double cena;

        public:
        //konstruktor 1 domyslny
        koszt() : koszt(0.0, 0.0) {
            std::cout << "konstruktor 1 domyslny\n\n";

        }
        //konstruktor 2 parametrowy
        koszt(double x, double y) : zuzycie(x), cena(y) {
            std::cout << "konstruktor 2 parametrowy\n\n";
        }

        ~koszt(void) {
            std::cout << "\n\nDekonstruktor";
        }

        void set_zuzycie(double x) {
            zuzycie = x;
        };

        void set_cena(double x) {
            cena = x;
        };

        double get_zuzycie(void) {
            return zuzycie;
        };

        double get_cena(void) {
            return cena;
        };

        double wylicz(void) {
            return (zuzycie / 100) * cena;
        };
    };

    double z;
    double c;
    std::cout << "Policzmy koszt jednego kilometra dla Opel: " << std::endl;
    std::cout << "Podaj zuzycie paliwa: ";
    std::cin >> z;
    std::cout << "Podaj cene paliwa: ";
    std::cin >> c;
    koszt opel; //konstruktor domyslny
    std::cout << "Koszt: " << opel.wylicz() << " zl. za km" << std::endl; //(1)
    opel.set_zuzycie(z);
    opel.set_cena(c);
    std::cout << "jeszcze raz koszt: " << opel.wylicz() << " zl. za km" << std::endl << std::endl; //(2)

    std::cout << "Policzmy koszt jednego kilometra dla VW: " << std::endl;
    std::cout << "Podaj zuzycie paliwa: ";
    std::cin >> z;
    std::cout << "Podaj cene paliwa: ";
    std::cin >> c;

    koszt vw(z, c); //konstruktor parametrowy
    std::cout << "Koszt: " << vw.wylicz() << " zl. za km" << std::endl;
}

//zadanie 4
template<class T>
class kalkulator {
    private:
    T liczba1;
    T liczba2;

    public:
    kalkulator(void) : liczba1(0), liczba2(0) {}
    kalkulator(T a, T b) : liczba1(a), liczba2(b) {}
    ~kalkulator(void) {
        std::cout << "\n\nDekonstruktor";
    }

    void liczba1_set(T a) {
        liczba1 = a;
    };

    void liczba2_set(T b) {
        liczba2 = b;
    };

    T dodawanie(void) {
        return  liczba1 + liczba2;
    };

    T odejmowanie(void) {
        return liczba1 - liczba2;
    };

    void klawiatura(void) {
        std::cout << "Podaj pierwsza liczba: ";
        std::cin >> liczba1;
        std::cout << "Podaj druga liczba: ";
        std::cin >> liczba2;
    };
};
void zad4() {
    /*
    Zadanie to ma zaprezentować zbudowanie klasy z zastosowaniem szablonu.Klasa nazywa
    się „kalkulator” i w sumie dodaje dwie cyfry, odejmuje dwie cyfry.Oprócz tego ma dwa konstruktory
    oraz destruktor oraz dwie metody do wczytywania cyfr.Dzięki zastosowaniu szablonu wykonamy
    jedną klasę która jest uniwersalna dla różnych typów zmiennych.
    Klasa kalkulator :

    template<class T>
    class kalkulator {
        private:
        T liczba1;
        T liczba2;
        public:
        kalkulator(void) : liczba1(0), liczba2(0) {}
        kalkulator(T a, T b) : liczba1(a), liczba2(b) {}
        ~kalkulator(void) {}
        void liczba1_set(T a);
        void liczba2_set(T b);
        T dodawanie(void);
        T odejmowanie(void);
        void klawiatura(void);
    };

    Dla ułatwienia przedstawię ciało jednej metody

    template<class T>
    void kalkulator<T>::klawiatura(void) {
        cout << "Podaj pierwsza liczba: ";
        cin >> liczba1;
        cout << "Podaj druga liczba: ";
        cin >> liczba2;
    }

    Dopisz brakujące metody.Następnie w funkcji main sprawdź działanie klasy
    int main(int argc, char** argv) {
        kalkulator<int> kal(3, 4); //(1)
        cout << "suma " << kal.dodawanie() << endl;
        cout << "Podaj liczbe w double" << endl;
        kalkulator<double> moje; //(2)
        moje.klawiatura();
        cout << "roznica " << moje.odejmowanie() << endl;
        return 0;
    }

    W funkcji main mamy dwa obiekty typu kalkulator.Pierwszy obiekt nazywa się „kal” i został
    zbudowany za pomocą klasy kalkulator.Klasa w tym wypadku działa na zmiennych typu int(linia 1).
    Widzimy to w tym zapisie „<int>”.Lina 1 wywołuje konstruktor parametrowy.
    W linii 2 widzimy obiekt który nazywa się „moje”.Został zbudowany za pomocą klasy kalkulator gdzie
    w tym wypadku klasa będzie działać na zmiennych typu double.Linia 2 pokazuje wywołanie
    konstruktora bezargumentowego.
 */
    kalkulator<int> kal(3, 4); //(1)
    std::cout << "suma " << kal.dodawanie() << std::endl;
    std::cout << "Podaj liczbe w double" << std::endl;
    kalkulator<double> moje; //(2)
    moje.klawiatura();
    std::cout << "roznica " << moje.odejmowanie() << std::endl;
}