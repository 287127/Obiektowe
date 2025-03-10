#include <iostream>

void Z1a (unsigned int n) {
	for (unsigned int i = 0; i <= n; i++) {
		std::cout << i % 10;
	}
}

void Z1b (unsigned int n) {
	for (unsigned int i = 1; i <= n; i++) {
		std::cout << i % 2;
	}
}

void Z1c (unsigned int n) {
	for (unsigned int i = 0; i <= n; i++) {
		std::cout << i % 4;
	}
}

void Z1d (unsigned int n) {
	for (unsigned int i = 1; i <= n; i++) {
		std::cout << "0123";
	}
}

void Z1e (unsigned int n) {
	for (unsigned int i = 0; i < n; i++) {
		std::cout << "0123456789";
	}
	std::cout << "0123";
}

void Z1f (unsigned int n) {
	for (unsigned int i = 0; i <= n; i++) {
		if (i % 2 == 0) {
			std::cout << "7";
		}
		else {
			std::cout << "3";
		}
	}
}