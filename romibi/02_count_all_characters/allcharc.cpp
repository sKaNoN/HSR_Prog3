#include <iostream>

int allcharc(std::istream &in) {
	int result{0};
	std::string str;
	while(!in.eof()) {
		in.get();
		result++;
	}
	return result;
}
