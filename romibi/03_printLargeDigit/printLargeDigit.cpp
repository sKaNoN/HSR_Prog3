#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<std::vector<std::string>> const digits = {{" - ",
												"| |",
												"   ",
												"| |",
												" - "},
												{"   ",
												"  |",
												"   ",
												"  |",
												"   "},
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
												"|  ",
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

std::string getScaledLine(std::string line, int scale) {
	if(line.length()==3) {
		std::string newLine = line[0];
		for(int n=0; n<scale; n++) {
			newLine += line[1];
		}
		newLine += line[2];
		return newLine;
	} else {
		return line;
	}
}

std::vector<std::string> getScaledDigit(std::vector<std::string> digit, int scale) {
	std::vector<std::string> newDigit(3+2*scale);
	newDigit.at(0) = getScaledLine(digit.at(0), scale);
	newDigit.at(1) = getScaledLine(digit.at(1), scale);
	int n=2;
	for(; n<=scale; n++) {
		newDigit.at(n) = newDigit.at(1);
	}
	newDigit.at(++n) = getScaledLine(digit.at(2), scale);
	newDigit.at(++n) = getScaledLine(digit.at(3), scale);
	for(int m=1;m<scale;m++) {
		newDigit.at(++n) = newDigit.at(n-1);
	}
	newDigit.at(++n) = getScaledLine(digit.at(4), scale);
	return newDigit;
} //Öm...

void printLargeDigit(unsigned i, std::ostream &out) {
	std::ostream_iterator<std::string> out_i{out, "\n"};
	copy(digits.at(i).begin(), digits.at(i).end(), out_i);
}
