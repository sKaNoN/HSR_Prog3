#include "sevenSegment.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

void scaleHorizontal(unsigned const number, unsigned const scale, std::vector<std::vector<std::string>> &digits) {
	for_each(digits[number].begin(), digits[number].end(),[&scale](std::string& s) {
		s.insert(1,scale-1,s.at(1));
	});
}

void scaleVertical(unsigned const number, unsigned const scale, std::vector<std::vector<std::string>> &digits) {
	digits[number].insert(digits[number].begin()+2,scale-1,digits[number].at(1));
	digits[number].insert(digits[number].begin()+3+scale,scale-1,digits[number].at(2+scale));
}

std::vector<unsigned> getDigits(std::stringstream &ss, unsigned scale) {
	std::string number = ss.str();
	std::vector<unsigned> numbers;

	if (std::isdigit(number.at(0))) {
		if (number.size() > 50/scale) {
			numbers = {10,11,11,12,11};
		} else {
			for_each(number.begin(),number.end(),[&numbers](char c) {
				numbers.push_back(c-'0');
		});
		}
	} else numbers = {10,11,11,12,11};

	return numbers;
}

void print(std::vector<unsigned> const numbers, std::ostream &out, std::vector<std::vector<std::string>> const digits) {

	for (size_t i{0}; i < digits[numbers.at(0)].size();i++) {
		for_each(numbers.begin(),numbers.end(),[&out, &i, &digits](unsigned j){
			out << digits[j].at(i);
		});
		out << "\n";
	}
}

void scaleDigits(std::vector<unsigned> const numbers, unsigned const scale, std::vector<std::vector<std::string>> &digits) {
	if (scale>1) {
		for_each(numbers.begin(), numbers.end(),[&scale, &digits](unsigned i){
			if (digits[i].size()<=5){
				scaleHorizontal(i, scale, digits);
				scaleVertical(i, scale, digits);
			}
		});
	}
}

void sevenSegment(std::stringstream &ss, unsigned const scale, std::ostream &out) {
	std::vector<unsigned> numbers = getDigits(ss, scale);

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

	scaleDigits(numbers, scale, digits);

	print(numbers, out, digits);


}

