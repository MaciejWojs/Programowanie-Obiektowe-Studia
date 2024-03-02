﻿#include <iostream>
#include <limits>
#include <cmath>
using string = std::string;

int pobierzInt(string wiadomosc) {
	int dane;
	do {
		std::cout << wiadomosc;
		std::cin >> dane;
		if (!std::cin.fail())
			break;
		std::cout << "Podano bledne dane\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);
	return dane;
}

class kalkualtor {
	private:
	int liczba1, liczba2;

	public:
	kalkualtor() : liczba1(0), liczba2(0) {
		std::cout << "Konstruktor\n";
	};

	~kalkualtor() {
		std::cout << "Destruktor\n";
	}

	int dodawanie() {
		return liczba1 + liczba2;
	}

	int odejmowanie() {
		return liczba1 - liczba2;
	}

	int mnozenie() {
		return liczba1 * liczba2;
	}

	void klawiatura() {
		liczba1 = pobierzInt("Podaj pierwsza liczbe: ");
		liczba2 = pobierzInt("Podaj druga liczbe: ");
	}
};

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();

int main() {
	/*
	zad1();
	zad2();
	zad3();
	zad4();
	*/
	zad5();
	return 0;
}
void zad1() {
	/*
		Napisz program kalkulator, gdzie mamy taką klasę:
		class kalkulator {
			private:
			int liczba1;
			int liczba2;
			public:
			kalkulator(void);
			~kalkulator(void);
			int dodawanie(void);
			int odejmowanie(void);
			int mnozenie(void);
			void klawiatura(void);
		};
		Mając klasę, uzupełnij metody, wraz z konstruktorem i destruktorem. Metoda klawiatura ma za
		zadanie pobrać z klawiatury dwie cyfry potrzebne do wykonania obliczeń. W funkcji main wywołaj
		wszystkie metody
	*/
	kalkualtor calc;
	calc.klawiatura();
	std::cout << "Wynik dodawania: " << calc.dodawanie() << '\n';
	std::cout << "Wynik odejmowania: " << calc.odejmowanie() << '\n';
	std::cout << "Wynik mnozenia: " << calc.mnozenie() << '\n';
}

void zad2() {
	/*
		Napisz program, gdzie mamy taką klasę:
		class operacje {
		private:
			int liczba1;
			int liczba2;
			public:
			operacje(void);
			~operacje(void);
			int wieksza(void);
			int mniejsza(void);
			int czy_rowne(void);
			void klawiatura(void);
		};

		Mając klasę, uzupełnij metody, wraz z konstruktorem i destruktorem. Metoda klawiatura ma za
		zadanie pobrać z klawiatury dwie cyfry potrzebne do wykonania obliczeń. Metoda czy_rowne zwraca
		1 gdy liczby są równe lub zwraca 0 gdy liczby są różne. W funkcji main utwórz nowy obiekt o nazwie
		„zadanie" na podstawie klasy operacje, a następnie wywołaj wszystkie metody. Metoda czy_rowne
		ma być wywołana w main w ten sposób:


		if(zadanie.czy_rowne()){
			cout<<" liczby sa rowne";
		}
		else{
			cout<<" liczby sa rozne";
		}
	 */
	class operacje {
		private:
		int liczba1;
		int liczba2;

		public:
		operacje(void) : liczba1(0), liczba2(0) {
			std::cout << "Konstruktor\n";
		};

		~operacje(void) {
			std::cout << "Dekonstruktor\n";
		};

		int wieksza(void) {
			if (liczba1 > liczba2)
				return 1;
			else
				return 0;
		};

		int mniejsza(void) {
			if (liczba1 < liczba2)
				return 1;
			else
				return 0;
		};

		int czy_rowne(void) {
			if (liczba1 == liczba2)
				return 1;
			else
				return 0;
		};

		void klawiatura(void) {
			liczba1 = pobierzInt("Podaj piersza liczbe: ");
			liczba2 = pobierzInt("Podaj druga liczbe: ");
		};
	};

	operacje zadanie;
	zadanie.klawiatura();

	if (zadanie.czy_rowne()) {
		std::cout << "liczby sa rowne\n";
	} else {
		std::cout << "liczby sa rozne\n";
	}

	std::cout << "Większa: " << zadanie.wieksza() << '\n';
	std::cout << "Mniejsza: " << zadanie.mniejsza() << '\n';
}

void zad3() {
	/*
		Napisz program, gdzie mamy taką klasę:
		class algorytmy {
			private:
				int liczba1;
				int liczba2;
				int liczba3;
				int liczba4;
			public:
			algorytmy(void);
			~algorytmy(void);
			int max(void);
			int mini(void);
			int suma(void);
			int szukana(int x);
			int parzyste(void);
			void klawiatura(void);
		};
		Mając klasę, uzupełnij metody, wraz z konstruktorem i destruktorem. Metoda klawiatura ma za
		zadanie pobrać z klawiatury cztery cyfry potrzebne do wykonania obliczeń. Metoda max zwraca
		największą cyfrę z wprowadzonych, metoda mini zwraca najmniejszą cyfrę. Metoda suma zwraca
		sumę czterech cyfr. Metoda szukana pobiera parametr (jakąś cyfrę), a następnie sprawdza czy ta
		cyfra jest jedną z czterech. Jeśli jest to metoda zwraca 1, a jeśli nie to zwraca 0. Metoda parzyste
		zwraca 1 gdy choć jedna liczba z wprowadzonych jest parzysta lub zwraca 0 gdy nie ma liczby
		parzystej. Metody szukana i parzyste wywołaj w menu tak samo jak czy_rowne z poprzednim
		zadaniu. W funkcji main wywołaj wszystkie metody.
	*/
	class algorytmy {
		private:
		int liczba1;
		int liczba2;
		int liczba3;
		int liczba4;

		public:
		algorytmy(void) : liczba1(0), liczba2(0), liczba3(0), liczba4(0) {
			std::cout << "Konstruktor\n";
		};

		~algorytmy(void) {
			std::cout << "Dekonstruktor\n";
		};

		int max(void) {
			int tab[4] = { liczba1, liczba2, liczba3, liczba4 };
			int max = tab[0];
			for (int i = 1; i < 4; i++) {
				if (tab[i] > max)
					max = tab[i];
			}
			return max;
		};

		int mini(void) {
			int tab[4] = { liczba1, liczba2, liczba3, liczba4 };
			int min = tab[0];
			for (int i = 1; i < 4; i++) {
				if (tab[i] < min)
					min = tab[i];
			}
			return min;
		};

		int suma(void) {
			return (liczba1 + liczba2 + liczba3 + liczba4);
		}

		int szukana(int x) {
			int tab[4] = { liczba1, liczba2, liczba3, liczba4 };
			bool znaleziono = false;
			for (int i = 0; i < 4; i++) {
				if (tab[i] == x) {
					znaleziono = true;
					break;
				}
			}
			return (int)znaleziono;
		}

		int parzyste(void) {
			int tab[4] = { liczba1, liczba2, liczba3, liczba4 };
			bool parzyste = false;
			for (int i = 0; i < 4; i++) {
				if (tab[i] % 2 == 0) {
					parzyste = true;
					break;
				}
			}
			return (int)parzyste;
		}

		void klawiatura(void) {
			liczba1 = pobierzInt("Podaj pierwsza liczbe: ");
			liczba2 = pobierzInt("Podaj druga liczbe: ");
			liczba3 = pobierzInt("Podaj trzecia liczbe: ");
			liczba4 = pobierzInt("Podaj czwarta liczbe: ");
		}
	};

	std::cout << std::endl;
	algorytmy a;
	a.klawiatura();

	std::cout << "Najwieksza liczba to: " << a.max() << '\n';
	std::cout << "Najmniejsza liczba to: " << a.mini() << '\n';
	std::cout << "Suma tych liczb to: " << a.suma() << '\n';

	if (a.parzyste()) {
		std::cout << "Co najmniej 1 liczba jest parzysta\n";
	} else {
		std::cout << "Brak liczb parzystych\n";
	}

	if (a.szukana(pobierzInt("Podaj szukana liczbe: "))) {
		std::cout << "Znaleziono szukana liczbe\n";
	} else {
		std::cout << "Nie znaleziono szukanej liczby\n";
	}
}

void zad4() {
	/*
	Napisz program, gdzie mamy taką klasę:
	class trojkat {
		private:
			int podstawa;
			int bok1;
			int bok2;
			int wysokosc;
		public:
			trojkat(void);
			~trojkat(void);
			int obwod(void);
			double pole(void);
			int pitagoras(void);
			int czy_rownoboczny(void);
			int czy_rownoramienny(void);
			void klawiatura(void);
	};
	Mając klasę, uzupełnij metody, wraz z konstruktorem i destruktorem. Metoda klawiatura ma za
	zadanie pobrać z klawiatury cztery cyfry opisujące trójkąt. Metody obwod i pole wyliczają wartości.
	Metoda pitagoras zwraca 1 gdy trójkąt jest prostokątny lub 0 gdy trójkąt nie jest prostokątny.
	Metoda czy_rownoboczny zwraca 1 gdy trójkąt jest równoboczny lub zwraca 0 gdy trójkąt nie jest
	równoboczny. Metoda czy_rownoramienny zwraca 1 gdy trójkąt jest równoramienny, lub zwraca 0
	gdy nie jest równoramienny. W funkcji main wywołaj wszystkie metody.
	*/
	class trojkat {
		private:
		int podstawa;
		int bok1;
		int bok2;
		int wysokosc;
		public:
		trojkat(void) :
			podstawa(0),
			bok1(0),
			bok2(0),
			wysokosc(0) {
			std::cout << "Konstruktor\n";
		};

		~trojkat(void) {
			std::cout << "Dekonstruktor\n";
		};

		int obwod(void) {
			return (podstawa + bok1 + bok2);
		}

		double pole(void) {
			return 0.5 * podstawa * wysokosc;
		}

		int pitagoras(void) {
			bool prostokatny = false;
			if ((pow(bok1, 2) + pow(bok2, 2) == pow(podstawa, 2)) || pow(bok1, 2) + pow(podstawa, 2) == pow(bok2, 2) || pow(bok2, 2) + pow(podstawa, 2) == pow(bok1, 2)) prostokatny = true;
			return (int)prostokatny;
		}

		int czy_rownoboczny(void) {
			if (podstawa == bok1 && bok2 == bok1) {
				return 1;
			} else return 0;
		}

		int czy_rownoramienny(void) {
			if (bok1 == bok2 || bok1 == podstawa || bok2 == podstawa) {
				return 1;
			} else return 0;
		}

		void klawiatura(void) {
			bok1 = pobierzInt("Podaj pierwszy bok trojkata: ");
			bok2 = pobierzInt("Podaj drugi bok trojkata: ");
			podstawa = pobierzInt("Podaj podstawe trojkata: ");
			wysokosc = pobierzInt("Podaj wysokosc trojkata: ");
		}
	};

	trojkat t;
	t.klawiatura();
	std::cout << "Obwod trojakta: " << t.obwod() << '\n';
	std::cout << "Pole trojakta: " << t.pole() << '\n';

	if (t.pitagoras()) {
		std::cout << "Trojkat jest prostokatny\n";
	} else {
		std::cout << "Trojkat nie jest prostokatny\n";
	}

	if (t.czy_rownoboczny()) {
		std::cout << "Trojkat jest rownoboczny\n";
	} else {
		std::cout << "Trojkat nie jest rownoboczny\n";
	}

	if (t.czy_rownoramienny()) {
		std::cout << "Trojkat jest rownoramienny\n";
	} else {
		std::cout << "Trojkat nie jest rownoramienny\n";
	}
}

void zad5() {
	/*
	Napisz program, gdzie mamy taką klasę:
	class prostokat {
		private:
			int bok1;
			int bok2;
		public:
			prostokat(void);
			~prostokat(void);
			int obwod(void);
			int pole(void);
			int czy_kwadrat(void);
			void klawiatura(void);
	};
	Mając klasę, uzupełnij metody, wraz z konstruktorem i destruktorem. Metoda klawiatura ma za
	zadanie pobrać z klawiatury dwie cyfry potrzebne do wykonania obliczeń. Metoda pole i obwod
	wylicza pole i obwód. Metoda czy_kwadrat zwraca 1 gdy bok1 i bok2 są równe lub zwraca 0 gdy boki
	są różne. W funkcji main wywołaj wszystkie metody
	*/
	class prostokat {
		private:
		int bok1;
		int bok2;

		public:
		prostokat(void) : bok1(0), bok2(0) {
			std::cout << "Konstruktor\n\n";
		};

		~prostokat(void) {
			std::cout << "Dekonstruktor\n\n";

		};

		int obwod(void) {
			return ((2 * bok1) + (2 * bok2));
		}

		int pole(void) {
			return bok1 * bok2;
		}

		int czy_kwadrat(void) {
			if (bok1 == bok2) return 1;
			else return 0;
		};

		void klawiatura(void) {
			bok1 = pobierzInt("Podaj pierwszy bok prostokata: ");
			bok2 = pobierzInt("Podaj drugi bok prostokata: ");
		}
	};

	prostokat p;
	p.klawiatura();
	std::cout << "Obwod prostokata: " << p.obwod() << '\n';
	std::cout << "Pole prostokata: " << p.pole() << '\n';
	if (p.czy_kwadrat()) {
		std::cout << "Ten prostokat jest rownoczesnie kwadratem\n";
	}
}