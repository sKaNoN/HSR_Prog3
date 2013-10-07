
#include "calc.h"
#include <sstream>

void pocketcalculator(std::istream &in, std::ostream &out) {
	std::stringstream result;
	result = calc(in);
	std::cout << result.str();
}
