#include <iostream>

void fractab(std::ostream &out, std::istream &in) {
	int sizeX{0};
	in>>sizeX;

	int sizeY{0};
	sizeY = sizeX;

	double x{1};
	double y{1};

	while(y<=sizeY) {
		out << y << "\t";
		++y;
	}
	out << "\n";

	while(x<=sizeX) {
		y = 1;
		while(y<=sizeY) {
			out << x/y << "\t";
			++y;
		}
		out << "\n";
		++x;
	}
}




