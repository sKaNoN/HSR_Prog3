#include "sumi.h"
#include <iostream>

int calcSum(std::istream &in) {
	int result{0};
	int tmp{};


	while(in >> tmp) {
		result += tmp;
	}

	return result;
}

void printResult(std::ostream &out, int& result) {
	out << result;
}



