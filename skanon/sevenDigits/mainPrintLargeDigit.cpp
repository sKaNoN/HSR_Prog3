#include "printLargeDigit.h"
#include <iostream>

int main() {
	unsigned number;
	unsigned scale{20};
	std::cin >> number;
	printLargeDigit(number,scale, std::cout);
}
