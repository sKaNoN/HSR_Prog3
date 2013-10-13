#include "calc.h"
#include "sevenSegment.h"
#include <sstream>

void pocketcalculator(std::istream &in, std::ostream &out) {
	std::stringstream result;
	unsigned scale{3};

	while (in) {
		result = calc(in);
		if(!in.eof()) {
			sevenSegment(result, scale, out);
		}
	}

}
