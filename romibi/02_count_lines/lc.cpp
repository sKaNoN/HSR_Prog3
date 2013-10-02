#include <iostream>

int lc(std::istream &in) {
	int result{0};
	std::string str;
	while(!in.eof()) {
		getline(in, str);
		result++;
	}
	return result;
}
