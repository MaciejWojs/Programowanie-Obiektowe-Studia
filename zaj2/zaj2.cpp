#include <iostream>
#include <limits>
using string = std::string;



class kalkualtor{
	private:
	int liczba1, liczba2;
	public:
	kalkualtor(): liczba1(0), liczba2(0){};
	~kalkualtor(){
		std::cout<<"Destruktor\n";
	}

	int dodawanie(){
		return this->liczba1+liczba2;
	}
	int odejmowanie(){
		return this->liczba1-liczba2;
	}
	int mnozenie(){
		return this->liczba1*liczba2;
	}
	int klawiatura(){
		std::cout<<Podaj pierwsza liczbe;
	}
}

int main() {

kalkualtor calc;
}
