#include "allcharc.h"
#include <iostream>

int calcAllChars(std::istream &in) {
	int result{0};


	while(!in.eof()) {
		in.get();
		++result;
	}

	return result-1;
}

void printResult(std::ostream &out, int& result) {
	out << result << " characters";
}



