#include <iostream>

double pamiec;
bool pamiec_uzyta;
double a;
double b;

void wyczysc() {
	pamiec = 0;
	pamiec_uzyta = false;
}

void Menu() {
	std::cout << "Menu:" << std::endl;
	std::cout << " 1) +" << " " << "2) -" << std::endl;
	std::cout << " 3) *" << " " << "4) /" << std::endl;
	std::cout << " 5) %" << " " << "6) Wyczysc pamiec" << std::endl;
	std::cout << " 7) Zakoncz" << std::endl;
}

double dodawanie(double a, double b) {
	pamiec = a + b;
	std::cout << pamiec << std::endl;
	pamiec_uzyta = true;
	return pamiec;
}
double odejmowanie(double a, double b) {
	pamiec = a - b;
	std::cout << pamiec << std::endl;
	pamiec_uzyta = true;
	return pamiec;
}
double iloczyn(double a, double b) {
	pamiec = a * b;
	std::cout << pamiec << std::endl;
	pamiec_uzyta = true;
	return pamiec;
}
double iloraz(double a, double b) {
	if (b == 0) {
		std::cout << "Zly dzielnik";
	} else {
		pamiec = a / b;
		std::cout << pamiec << std::endl;
	}
	pamiec_uzyta = true;
	return pamiec;
}
double modulo(double a, double b) {
	if (b == 0) {
		std::cout << "Zly dzielnik";
	} else {
		pamiec = (int)a % (int)b;
		std::cout << pamiec << std::endl;
		pamiec_uzyta = true;
	}
	return pamiec;
}

void operacje() {
	std::cout << "Wybierz opcje : ";
	int opcja;
	std::cin >> opcja;
	std::cout << "Wprowadz dwie liczby: ";
	switch (opcja)
	{
	case 1:
		
		std::cin >> a >> b;
		dodawanie(a, b);
		Menu();
		operacje();
	case 2:
		std::cin >> a >> b;
		odejmowanie(a, b);
		Menu();
		operacje();

	case 3:
		std::cin >> a >> b;
		iloczyn(a, b);
		Menu();
		operacje();

	case 4:
		std::cin >> a >> b;
		iloraz(a, b);
		Menu();
		operacje();

	case 5:
		std::cin >> a >> b;
		modulo(a, b);
		Menu();
		operacje();

	case 6:
		wyczysc();
		Menu();
		operacje();

	case 7:
		break;
	}
}


int main() {
	Menu();
	operacje();
}