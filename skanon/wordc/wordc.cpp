#include "wordc.h"
#include <iostream>
#include <string>

int calcWords(std::istream &in) {
	int result{0};
	std::string str;


	while(in >> str) {
		++result;
	}

	return result;
}

void printResult(std::ostream &out, int& result) {
	out << result << " words";
}



