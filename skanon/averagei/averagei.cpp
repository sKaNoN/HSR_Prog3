#include "averagei.h"
#include <iostream>

int calcAverage(std::istream &in) {
	int result{0};
	int tmp{};
	int count{0};


	while(in >> tmp) {
		result += tmp;
		++count;
	}

	return result/count;
}

void printResult(std::ostream &out, int& result) {
	out << result;
}



