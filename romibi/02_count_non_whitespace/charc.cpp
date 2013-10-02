#include <iostream>

int charc(std::istream &in) {
	int result{0};
	//std::string str;
	char chr;
	while(in >> chr) {
		result++;
	}
	return result;
}
