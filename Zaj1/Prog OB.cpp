#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <limits> 
#include <istream>
#include <ostream>
using string = std::string;

int pobierzInt(string wiadmomosc);
int mnozenie(int &x, int &y);
int max_tab(int t[], int n);
int *silnia(int *a);
void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();
void zad7();
void zad8();
void zad9();
string zad10();
void zad11();
void zad12();
void zad13();
void zad14();

int main() {
	srand(time(NULL));
	
	zad1();
	zad2();
	zad3();
	zad4();
	zad5();
	zad6();
	zad7();
	zad8();
	zad9();
	std::cout << zad10();
	zad11();
	zad12();
	zad13();
	zad14();
	
	std::cin.get();
	std::cin.get();
}

int pobierzInt(string wiadomosc) {
	int liczba;
	do {
		std::cout << wiadomosc;
		std::cin >> liczba;
		if (!std::cin.fail()) {
			break;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Podano dane które nie sa liczba\n";
	} while (true);
	return liczba;
}


void zad1() {
	/*
		Zad 1

		Napisz program, który dodaje cyfry podane z klawiatury przez użytkownika, cyfra 0 kończy
		program i wyświetla sumę wczytanych cyfr. Chodzi o to że gdy użytkownik poda cyfry: 1,2,3,0
		program wyświetli 6. Gdy użytkownik poda cyfry: 2,2,0 program wyświetli 4.
	*/

	int sum = 0;
	int liczba;
	do {
		liczba = pobierzInt("Podaj cyfre: ");
		sum += liczba;
	} while (liczba != 0);
	std::cout << "suma wynosi: " << sum << std::endl;
}

void zad2() {
	/*
		Zad 2

		Napisz program, który tworzy trzy zmienne dynamiczne. Pierwsza zmienna to podstawa,
		druga i trzecia to boki. Następnie program wypisuje czy to jest trójkąt równoboczny oraz czy jest to
		trójkąt równoramienny
	*/
	int *bok1 = new int, *bok2 = new int, *podstawa = new int;
	*bok1 = pobierzInt("Podaj pierwszy bok trojkata: ");
	*bok2 = pobierzInt("Podaj drugi bok trojkata: ");
	*podstawa = pobierzInt("Podaj podstawe trojkata: ");

	if (*bok1 == *bok2 && *bok1 == *podstawa) std::cout << "Podany trojkat jest rownoboczny\n";
	else if (*bok1 == *bok2 || *bok1 == *podstawa || *bok2 == *podstawa) std::cout << "Podany trojkat jest rownoramienny\n";
	else std::cout << "Podany trojkat nie jest rownoramienny ani rownoboczny";

	delete bok1;
	delete bok2;
	delete podstawa;

}

void zad3() {
	//Napisz program który za pomocą dwóch pętli, wyświetli cyfry w terminalu :
	/*
		1,2,3,4,5,6,7,8,9,10,
		2,4,6,8,10,12,14,16,18,20
		3,6,9,12,15,18,21,24,27,30,
		4,8,12,16,29,24,28,32,36,40,
		5,10,15,20,25,30,35,40,45,50,
		6,12,18,24,30,36,42,48,54,60,
		7,14,21,28,35,42,49,56,63,70,
		8,16,25,32,40,48,56,64,72,80,
		9,18,27,36,45,54,63,72,81,90,
		10,20,30,40,50,60,70,80,90,100,
	*/

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			std::cout << std::setw(4) << (j * i);
		}
		std::cout << std::endl;
	}

}

void zad4() {
	/*
		Napisz program który prosi użytkownika o podanie cyfry.Następnie wyświetla tyle cyfr
		w wierszu oraz tyle samo kolumnie.Macierz musi być wypełniona szachownicą(przykład dla liczby 4)
			0, 1, 0, 1,
			1, 0, 1, 0,
			0, 1, 0, 1,
			1, 0, 1, 0
	*/
	int rozmiar = pobierzInt("Podaj rozmiar szachownicy: ");

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			if (i % 2 == 0)
				if (j % 2 == 0) {
					std::cout << '0';
				} else std::cout << '1';
			else
				if (j % 2 == 0) {
					std::cout << '1';
				} else std::cout << '0';
		}
		std::cout << std::endl;
	}
}

void zad5() {
	/*
		Napisz program, który zadeklaruje tablice 20 elementową, a następnie prosi użytkownika
		o wpisanie cyfr z klawiatury i zapisanie do tablicy. Następnie program wypisuje: największą cyfrę,
		najmniejszą cyfrę, sumę cyfr liczb parzystych
	*/

	int tablica[20];
	int *wskaznik = tablica;

	for (int i = 0; i < (sizeof(tablica) / sizeof(int)); i++) {
		*wskaznik = pobierzInt("Podaj " + std::to_string(i) + " element tablicy: ");
		wskaznik++;
	}

	wskaznik = tablica;
	int najmniejsza = tablica[0], najwieksza = tablica[0], suma = 0;

	for (int i = 0; i < (sizeof(tablica) / sizeof(int)); i++) {
		std::cout << '\n' << *wskaznik;
		wskaznik++;
	}
	std::cout << std::endl;

	for (int i = 0; i < (sizeof(tablica) / sizeof(int)); i++) {
		if (tablica[i] < najmniejsza) {
			najmniejsza = tablica[i];
		}

		if (tablica[i] > najwieksza) {
			najwieksza = tablica[i];
		}

		if (tablica[i] % 2 == 0) suma += tablica[i];
	}

	std::cout << "najmniejszy element tablicy: " << najmniejsza << std::endl;
	std::cout << "najwiekszy element tablicy: " << najwieksza << std::endl;
	std::cout << "suma parzystych elementow tablicy: " << suma << std::endl;
}

void zad6() {
	/*
		Napisz program, który zadeklaruje dwie tablice tabA[4][4] i tabB[4][4]. Do tabA wygeneruj
		następnie cyfry:
			2 2 2 2
			4 4 4 4
			6 6 6 6
			8 8 8 8
		Za pomocą pętli, przepisz do tabB cyfry z tablicy tabA tak aby tabB była uzupełniona w ten sposób:
			2 4 6 8
			2 4 6 8
			2 4 6 8
			2 4 6 8
		Wypisz na ekran obie tablice.
	*/
	const int rozmiar = 4;

	int tabA[rozmiar][rozmiar] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int tabB[rozmiar][rozmiar] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	const int zmienna_stala = 2;
	int zmienna_pomocnicza = zmienna_stala;

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			tabA[i][j] = zmienna_pomocnicza;
		}
		zmienna_pomocnicza += zmienna_stala;
	}


	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			std::cout << ' ' << tabA[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			tabB[j][i] = tabA[i][j];
		}
	}

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			std::cout << ' ' << tabB[i][j];
		}
		std::cout << std::endl;
	}
}

void zad7() {
	/*
		Napisz program, który zadeklaruje trzy tablice tabA[4][4], tabB[4][4] i tabC[4][4]. Do tabA
		wpisze następnie cyfry:
			1 0 0 0
			1 1 0 0
			1 1 1 0
			1 1 1 1
		Do tablicy tabB wpisz następujące cyfry:
			0 1 0 1
			1 0 1 0
			0 1 0 1
			1 0 1 0
		Do tablicy tabC zapisz sumę tablicy tabA i tabB. Wypisz na ekran wszystkie trzy tablice
	*/
	const int rozmiar = 4;
	int tabA[rozmiar][rozmiar] = {
		{1,0,0,0},
		{1,1,0,0},
		{1,1,1,0},
		{1,1,1,1},
	};

	int tabB[rozmiar][rozmiar] = {
		{0,1,0,1},
		{1,0,1,0},
		{0,1,0,1},
		{1,0,1,0},
	};

	int tabC[rozmiar][rozmiar];

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			std::cout << ' ' << tabA[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			std::cout << ' ' << tabB[i][j];
		}
		std::cout << std::endl;

		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				tabC[i][j] = (tabA[i][j] + tabB[i][j]);
			}
		}

	}

	std::cout << std::endl;


	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			std::cout << ' ' << tabC[i][j];
		}
		std::cout << std::endl;
	}
}

void zad8() {
	const string nazwa = "dane.txt";
	/*
		Napisz program, który wypisze ilość wystąpień cyfr od 0 do 100 na ekran w ten sposób :
			‘0’ -> 2
			‘1’ -> 0
		zera są dwa, jedynka występuje zero razy, itp.
		plik z danymi który trzeba wczytać należy samemu utworzyć i wpisać 40 cyfr z zakresu od 0 do 100.
		Plik ma się nazywać „dane.txt”.
	*/

	std::fstream plik;


	//plik.open(nazwa, std::ios::out);
	//for (int i = 0; i < 40; i++) {

	//	plik << rand() % 100 << '\n';
	//}

	//plik.close();


	for (int i = 0; i <= 100; i++) {
		int licznik = 0;
		string linia;
		plik.open(nazwa, std::ios::in);

		while (plik >> linia) {
			if (i == std::stoi(linia)) {
				licznik++;
			} else continue;
		}
		std::cout << '\'' << i << '\'' << " -> " << licznik << '\n';
		plik.close();
	}

	if (plik.is_open()) plik.close();
}

void zad9() {
	/*
		Utwórz plik o nazwie zad1.txt i wpisz do niego ręcznie przez notatnik takie cyfry :
			1 0 0 0
			1 1 0 0
			1 1 1 0
			1 1 1 1
		Następnie utwórz plik o nazwie zad2.txt i wpisz do niego takie cyfry :
			0 0 0 0
			3 3 3 3
			0 0 0 0
			3 3 3 3
		Następnie zapisz sumę tych macierzy do pliku wynik.txt .
	*/

	const string zad1 = "zad1.txt";
	const string zad2 = "zad2.txt";
	const string wynik = "wynik.txt";
	const int rozmiar = 4;

	int tabA[rozmiar][rozmiar];
	int tabB[rozmiar][rozmiar];
	int tabC[rozmiar][rozmiar];

	std::fstream plik;
	int linia;
	plik.open(zad1, std::ios::in);
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			plik >> linia;
			tabA[i][j] = linia;
		}
	}

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			std::cout << std::setw(3) << tabA[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	plik.close();

	plik.open(zad2, std::ios::in);
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			plik >> linia;
			tabB[i][j] = linia;
		}
	}

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			std::cout << std::setw(3) << tabB[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	plik.close();


	plik.open(wynik, std::ios::app);
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			tabC[i][j] = tabA[i][j] + tabB[i][j];
		}
	}

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			plik << ' ' << tabC[i][j];
		}
		plik << '\n';
	}
	plik.close();
}

string zad10() {
	/*
		Napisz program który pobierze dwie cyfry od użytkownika a następnie przekaże je do
		funkcji.Funkcja ma za zadanie pomnożyć je i wynik przekazać do funkcji main.Deklaracja funkcji
		wygląda tak : int mnozenie(int &x, int &y)
	*/

	int a = pobierzInt("Podaj pierwsza liczbe do pomnozenia: ");
	int b = pobierzInt("Podaj druga liczbe do pomnozenia: ");

	return "Wynik mnozenia: " + std::to_string(mnozenie(a, b)) + '\n';
}

int mnozenie(int &x, int &y) {
	return x * y;
}

void zad11() {
	/*
		Napisz funkcję która zwraca największą liczbę w tabeli. Definicja funkcji to:
		int max_tab(int t[], int n), funkcja pobiera tablicę oraz ilość elementów, a zwraca największy
		element.Tablica musi być zadeklarowana w main oraz ma takie wartości wpisane przy tworzeniu :
		2, 4, 10, 1, 1, 2, 4, 5, 1, 3
	*/

	const int n = 10;
	int tab[n] = {2,4,10,1,1,2,4,5,1,3};
	std::cout << "Najwiekszy element tablicy to: " << max_tab(tab, n) << std::endl;
}

int max_tab(int tab[], int n) {
	int max = tab[0];
	for (int i = 0; i < n; i++) {
		if (tab[i] > max) {
			max = tab[i];
		} else continue;
	}

	return max;
}

void zad12() {
	/*
		Napisz funkcję która liczy silnię.Wszystkie zmienne w programie main są zmiennymi
		dynamicznymi(new). Pobierz od użytkownika jedną cyfrę a następnie przekaż ją do funkcji za
		pomocą wskaźnika. Funkcja zwraca wynik do programu za pomocą wskaźnika(w funkcji utwórz
		zmienną dynamiczną i zwróć ją do funkcji main). Deklaracja funkcji wygląda tak :
		int *silnia(int *a)
	*/

	int *a = new int;
	*a = pobierzInt("Podaj liczbe ktorej silnia zostanie obliczona: ");
	int *wynik = silnia(a);
	std::cout << "Silnia z " << *a << " to " << *wynik << std::endl;

	delete a;
	delete wynik;
}

int *silnia(int *a) {
	int *wynik = new int;
	*wynik = 1;
	for (int i = 1; i <= *a; i++) {
		*wynik *= i;
	}
	return wynik;
}

typedef struct {
	int re; 
	int im;

	void uzupelnij(){
		this->re=pobierzInt("Podaj czesc reczywista: ");
		this->im=pobierzInt("Podaj czesc zespolona: ");
	}

	}zespolona;


	zespolona operator+(zespolona a, zespolona b){
		zespolona n;
		n.re = b.re + a.re;
		n.im = b.im + a.im;
		return n;
	}

void zad13() {
	/* 
		Program ma taką strukturę:
			typedef struct {
			int re; //część rzeczywista
			int im; //część urojona
			}zespolona;
		Napisz program, który stworzy dwie zmienne według struktury „zespolona”. Następnie program musi 
		poprosić o wpisanie do liczby pierwszej (cyfry do części rzeczywistej oraz cyfry do części urojonej). To 
		samo trzeba zrobić z drugą liczbą. Następnie dodaj obie liczby zespolone. Dodawanie polega na 
		dodaniu części rzeczywistej do części rzeczywistej, a części urojonej do urojonej. Po czym wypisz 
		wynik według przykładu: 3+4i gdzie w tym przykładzie 3 to część rzeczywista, a 4 to część urojona. 
	*/

	zespolona pierwesza;
	pierwesza.uzupelnij();

	zespolona druga;
	druga.uzupelnij();

	zespolona t = pierwesza+druga;
	string znak = "";
	(t.im>0) ? znak="+":znak;
	std::cout<<t.re<<znak<<t.im<<'i'<<std::endl;
	std::cin.get();
}

void zad14(){
	/* 
		Program ma taką strukturę:
		typedef struct {
		int wysokosc;
		int szerokosc;
		}prostokat;
		Napisz program, który stworzy zmienną dynamiczną według struktury „prostokat”, następnie wczyta 
		z klawiatury dane. Następnie rysuje prostokąt z gwiazdek o podanej szerokości i wysokości oraz liczy 
		obwód oraz pole.
 	*/
	typedef struct {
	int wysokosc;
	int szerokosc;
	}prostokat;

	prostokat p;
	p.wysokosc=pobierzInt("Podaj wysokosc prostokata: ");
	p.szerokosc=pobierzInt("Podaj szerokosc prostokata: ");
	std::cout<<std::endl;

	for (int i = 0; i < p.wysokosc; i++)
	{
		for (int j = 0; j < p.szerokosc; j++)
		{
			if(i==0||i==p.wysokosc-1) std::cout<<'*';
			else if (j==0 || j==p.szerokosc-1 ) std::cout<<'*';
			else std::cout<<' ';
		}
		std::cout<<std::endl;
		
	}
}
