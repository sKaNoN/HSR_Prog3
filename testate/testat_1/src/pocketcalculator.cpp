#include "calc.h"
#include "sevenSegment.h"
#include <sstream>

void pocketcalculator(std::istream &in, std::ostream &out) {
	std::stringstream result;
	result = calc(in);
	unsigned scale{5};
	sevenSegment(result, scale, out);

}
