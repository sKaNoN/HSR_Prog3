#include <iostream>

int averagei(std::istream &in) {
	int sum {0};
	int count {0};
	int tmp {0};
	while(in >> tmp) {
		sum += tmp;
		++count;
	}
	return sum/count;
}

