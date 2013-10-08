#include "printLargeDigit.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

std::vector<std::vector<std::string>> digits {
	{ " - ", "| |", "   ", "| |", " - " },
	{ "   ", "  |", "   ", "  |", "   " },
	{ " - ", "  |", " - ", "|  ", " - " },
	{ " - ", "  |", " - ", "  |", " - " },
	{ "   ", "| |", " - ", "  |", "   " },
	{ " - ", "|  ", " - ", "  |", " - " },
	{ " - ", "|  ", " - ", "| |", " - " },
	{ " - ", "  |", "   ", "  |", "   " },
	{ " - ", "| |", " - ", "| |", " - " },
	{ " - ", "| |", " - ", "  |", " - " },
	{ " - ", "|  ", " - ", "|  ", " - " },
	{ "   ", "   ", " - ", "|  ", "   " },
	{ "   ", "   ", " - ", "| |", " - " }};

void scaleHorizontal(unsigned number, unsigned scale) {
	for_each(digits[number].begin(), digits[number].end(),
			[&scale](std::string& s) {
				for (unsigned j{0};j<scale-1;j++) {
					s.insert(s.end()-1, s.at(1));
				}

			});
}

void scaleVertical(unsigned number, unsigned scale) {
	for (unsigned i{0}; i<scale-1; i++) {
		digits[number].insert(digits[number].begin() + 2 + i,
				digits[number].at(1));
		digits[number].insert(digits[number].begin() + 5 + i,
				digits[number].at(4 + i));
	}
}

void printError(std::vector<unsigned> &numbers){
	numbers.push_back(10);
	numbers.push_back(11);
	numbers.push_back(11);
	numbers.push_back(12);
	numbers.push_back(11);
}

void getDigits(std::vector<unsigned> &numbers, std::string str) {
	if (str.compare("Error")==0) {
		printError(numbers);
	} else if (str.size()>10) {
		printError(numbers);
	} else if (str.at(0)=='-') {
		printError(numbers);
	} else {
		unsigned i{0};
		for_each(str.begin(),str.end(),[&i, &numbers](char c) {
			i = c-'0';
			numbers.push_back(i);
		});
	}
}

void print(std::vector<unsigned> &numbers, std::ostream &out) {

	for (size_t i{0}; i < digits[numbers.at(0)].size();i++) {
		for_each(numbers.begin(),numbers.end(),[&out, &i](unsigned j){
			out << digits[j].at(i);
		});
		out << "\n";
	}
}

bool isNotScaled(unsigned i){
	return (digits[i].size()<=5);
}

void scaleDigits(std::vector<unsigned> &numbers, unsigned &scale) {
	if (scale>1) {
		for_each(numbers.begin(), numbers.end(),[&scale](unsigned i){
			if (isNotScaled(i)){
				scaleHorizontal(i, scale);
				scaleVertical(i, scale);
			}
		});
	}
}

void printLargeDigit(std::stringstream &number, unsigned scale, std::ostream &out) {
	std::string str = number.str();
	std::vector<unsigned> numbers;

	getDigits(numbers, str);
	scaleDigits(numbers, scale);

	print(numbers, out);


}

