#include <iostream>

void multab(std::ostream &out, std::istream &in) {
	int sizeX{0};
	in>>sizeX;

	int sizeY{0};
	sizeY = sizeX;

	int x{1};
	int y{1};
	while(x<=sizeX) {
		y = 1;
		while(y<=sizeY) {
			out << x*y << "\t";
			++y;
		}
		out << "\n";
		++x;
	}
}




