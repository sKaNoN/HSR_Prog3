#include <iostream>

int wc(std::istream &in) {
	int result{0};
	std::string str;
	while(in >> str) {
		result++;
	}
	return result;
}
