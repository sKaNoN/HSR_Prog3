#include "multab.h"
#include <iostream>

int main() {
	int const size  = getSize(std::cout, std::cin);
	createTable(std::cout, size);
}
