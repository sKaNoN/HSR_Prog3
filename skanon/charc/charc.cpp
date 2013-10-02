#include "charc.h"
#include <iostream>

int calcChars(std::istream &in) {
	int result{0};
	char c;


	while(in >> c) {
		++result;
	}

	return result;
}

void printResult(std::ostream &out, int& result) {
	out << result << " characters";
}



