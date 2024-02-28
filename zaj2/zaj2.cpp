#include <iostream>
#include <limits>
using string = std::string;

int pobierzInt(string wiadomosc){
	int dane;
	do
	{	
	std::cout<<wiadomosc;
	std::cin>>dane;
	if(!std::cin.fail()) break;
	std::cout<<"Podano bledne dane\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);
	return dane;
	
}

class kalkualtor{
	private:
	int liczba1, liczba2;
	public:
	kalkualtor(): liczba1(0), liczba2(0){
		std::cout<<"Konstruktor\n";

	};
	~kalkualtor(){
		std::cout<<"Destruktor\n";
	}

	int dodawanie(){
		return liczba1+liczba2;
	}

	int odejmowanie(){
		return liczba1-liczba2;
	}

	int mnozenie(){
		return liczba1*liczba2;
	}

	void klawiatura(){
		liczba1=pobierzInt("Podaj pierwsza liczbe: ");
		liczba2=pobierzInt("Podaj druga liczbe: ");
	}
};

void zad1();
void zad2();

int main() {
	/*
	zad1();
	*/
	zad2();
return 0;
}
void zad1(){
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
	std::cout<<"Wynik dodawania: "<<calc.dodawanie()<<'\n';
	std::cout<<"Wynik odejmowania: "<<calc.odejmowanie()<<'\n';
	std::cout<<"Wynik mnozenia: "<<calc.mnozenie()<<'\n';
}

void zad2(){
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
	„zadanie” na podstawie klasy operacje, a następnie wywołaj wszystkie metody. Metoda czy_rowne 
	ma być wywołana w main w ten sposób: 
	
	
	if(zadanie.czy_rowne()){
		cout<<” liczby sa rowne”;
	}
	else{
		cout<<” liczby sa rozne”;
	}
 */
}