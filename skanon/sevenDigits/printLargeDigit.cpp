#include "printLargeDigit.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

std::vector<std::vector<std::string>> digits { { " - ", "| |", "   ", "| |",
		" - " }, { "   ", "  |", "   ", "  |" }, { " - ", "  |", " - ", "|  ",
		" - " }, { " - ", "  |", " - ", "  |", " - " }, { "   ", "| |", " - ",
		"  |", "   " }, { " - ", "|  ", " - ", "  |", " - " }, { " - ", "|  ",
		" - ", "| |", " - " }, { " - ", "  |", "   ", "  |", "   " }, { " - ",
		"| |", " - ", "| |", " - " }, { " - ", "| |", " - ", "  |", " - " } };

void scaleHorizontal(unsigned number, unsigned scale) {
	for_each(digits[number].begin(), digits[number].end(),
			[&scale](std::string& s) {
				for (unsigned j {0};j<scale;j++) {
					s.insert(s.end()-1, s.at(1));
				}
			});
}

void scaleVertical(unsigned number, unsigned scale) {
	for (unsigned i { 0 }; i < scale - 1; i++) {
		digits[number].insert(digits[number].begin() + 2 + i,
				digits[number].at(1));
		digits[number].insert(digits[number].begin() + 5 + i + i,
				digits[number].at(4 + i));
	}
}

void printLargeDigit(unsigned number, unsigned scale, std::ostream &cout) {

	std::ostream_iterator<std::string> out { cout, "\n" };
	scaleHorizontal(number, scale);
	scaleVertical(number, scale);
	copy(digits[number].begin(), digits[number].end(), out);

}

