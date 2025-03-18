#include <iostream>

double pamiec;
bool pamiec_uzyta;
double a;
double b;

void wyczysc() {}

void Menu() {
	std::cout << "Menu:" << std::endl;
	std::cout << " 1) +" << " " << "2) -" << std::endl;
	std::cout << " 3) *" << " " << "4) /" << std::endl;
	std::cout << " 5) %" << " " << "6) Wyczysc pamiec" << std::endl;
}

double dodawanie(double a, double b) {
	pamiec = a + b;
	std::cout << pamiec;
	pamiec_uzyta = true;
	return pamiec;
}
double odejmowanie(double a, double b) {
	pamiec = a - b;
	std::cout << pamiec;
	pamiec_uzyta = true;
	return pamiec;
}
double iloczyn(double a, double b) {
	pamiec = a * b;
	std::cout << pamiec;
	pamiec_uzyta = true;
	return pamiec;
}
double iloraz(double a, double b) {
	if (b == 0) {
		std::cout << "Zly dzielnik";
	} else {
		pamiec = a / b;
		std::cout << pamiec;
	}
	pamiec_uzyta = true;
	return pamiec;
}
double modulo(double a, double b) {
	if (b == 0) {
		std::cout << "Zly dzielnik";
	} else {
		pamiec = (int)a % (int)b;
	}
	pamiec_uzyta = true;
	return pamiec;
}

void operacje() {
	int opcja;
	std::cin >> opcja;
	switch (opcja)
	{
	case 1:
		std::cin >> a, b;
		dodawanie(a, b);
		break;
	case 2:
		std::cin >> a, b;
		odejmowanie(a, b);
		break;
	case 3:
		std::cin >> a, b;
		iloczyn(a, b);
		break;
	case 4:
		std::cin >> a, b;
		iloraz(a, b);
		break;
	case 5:
		std::cin >> a, b;
		modulo(a, b);
		break;
	case 6:
		wyczysc();
		break;
	}
}

int main() {
	Menu();
	operacje();
}