#include <iostream>

double mem;
bool mem_used;
double a;
double b;
int n;

void Menu() {
	std::cout << "Menu: " << std::endl;
	std::cout << " 1) +" << " " << " 2) -" << std::endl;
	std::cout << " 3) *" << " " << " 4) /" << std::endl;
	std::cout << " 5) %" << " " << " 6) Wyczysc pamiec" << std::endl;
	std::cout << " 7) Zakoncz" << std::endl;
	std::cout << "Wybierz opcje:" << std::endl;
}

class Calculator {
private:
	double mem;
	bool mem_used;

public:
	Calculator() : mem(0), mem_used(false) {}

	double add(double a, double b) {
		mem = a + b;
		mem_used = true;
		return mem;
	}

	double sub(double a, double b) {
		mem = a - b;
		mem_used = true;
		return mem;
	}

	double mult(double a, double b) {
		mem = a * b;
		mem_used = true;
		return mem;
	}

	double div(double a, double b) {
		if (b != 0) {
			mem = a / b;
			mem_used = true;
			return mem;
		}
		else {
			std::cout << "Niepoprawny dzielnik" << std::endl;
			return 0;
		}
	}

	double mod(double a, double b) {
		if (b > 0) {
			mem = (int)a % (int)b;
			mem_used = true;
			return mem;
		}
		else {
			std::cout << "Niepoprawny dzielnik" << std::endl;
			return 0;
		}
	}

	void clear_mem() {
		mem = 0;
		mem_used = false;
	}
};

void function(Calculator& calc) {
	Menu();
	std::cin >> n;
	switch (n) {
	case 1:
		std::cout << "Wprowadz 2 liczby: " << std::endl;
		std::cin >> a >> b;
		calc.add(a, b);
		function(calc);
		break;
	case 2:
		std::cout << "Wprowadz 2 liczby: " << std::endl;
		std::cin >> a >> b;
		calc.sub(a, b);
		function(calc);
		break;
	case 3:
		std::cout << "Wprowadz 2 liczby: " << std::endl;
		std::cin >> a >> b;
		calc.mult(a, b);
		function(calc);
		break;
	case 4:
		std::cout << "Wprowadz 2 liczby: " << std::endl;
		std::cin >> a >> b;
		calc.div(a, b);
		function(calc);
		break;
	case 5:
		std::cout << "Wprowadz 2 liczby: " << std::endl;
		std::cin >> a >> b;
		calc.mod(a, b);
		function(calc);
		break;
	case 6:
		calc.clear_mem();
		function(calc);
		break;
	case 7:
		break;
	}
}


int main() {
	Calculator calc;
	function(calc);
	return 0;
}