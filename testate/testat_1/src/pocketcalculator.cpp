#include "calc.h"
#include "sevenSegment.h"
#include <sstream>

void pocketcalculator(std::istream &in, std::ostream &out) {
	std::stringstream result;
	std::stringstream tmp;
	unsigned scale{5};

	while (in) {
		result = calc(in);
		sevenSegment(result, scale, out);
	}

}
