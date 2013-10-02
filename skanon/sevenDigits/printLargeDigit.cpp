#include "printLargeDigit.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

std::vector<std::vector<std::string>> digits{
	{" - ",
	 "| |",
	 "   ",
	 "| |",
	 " - "},
	{"   ",
	 "  |",
	 "   ",
     "  |"},
	{" - ",
     "  |",
     " - ",
     "|  ",
     " - "},
    {" - ",
     "  |",
     " - ",
     "  |",
     " - "},
    {"   ",
     "| |",
     " - ",
     "  |",
     "   "},
    {" - ",
     "|  ",
     " - ",
     "  |",
     " - "},
    {" - ",
     "|  ",
     " - ",
     "| |",
     " - "},
    {" - ",
     "  |",
     "   ",
     "  |",
	 "   "},
    {" - ",
     "| |",
     " - ",
     "| |",
     " - "},
    {" - ",
     "| |",
     " - ",
     "  |",
     " - "}
	};

void scaleDigit(unsigned number, unsigned scale){
	for_each(digits[number].begin(), digits[number].end(),
		[&scale](std::string& s) {
			char begin = s.at(0);
			char c = s.at(1);
			char end = s.at(2);

			s = begin;
			for (int i{0};i<scale;i++) {
				s.push_back(c);
			}
			s.push_back(end);
		}
	);

	for (size_t i{0}; i < digits[number].size();i++ ) {
		if (i%2==1) {
			std::string s = digits[number].at(i);
			for (int j{1};j<scale;j++) {
				digits[number].at(i).append("\n" + s);
			}
		}
	}
}


void printLargeDigit(unsigned number, unsigned scale, std::ostream &cout) {

	std::ostream_iterator<std::string> out{cout, "\n"};
	scaleDigit(number, scale);
	copy(digits[number].begin(), digits[number].end(), out);

}



