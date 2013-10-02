#include "linec.h"
#include <iostream>
#include <string>

int calcLines(std::istream &in) {
	int result{0};
	std::string line;


	while(!in.eof()) {
		getline(in, line);
		++result;
	}

	return result-1;
}

void printResult(std::ostream &out, int& result) {
	out << result << " lines";
}



