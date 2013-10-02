#include "multab.h"
#include <iostream>


int getSize(std::ostream &out, std::istream &in) {
	int size{};
	 out << "Bitte geben Sie eine Grösse zwischen 0 und 30 an \n";
	 while (in >> size){};
	 return size;
}


void createTable(std::ostream &out, int size) {
	for (int x{0};x<=size;x++) {
		for (int y{0};y<=size;y++) {
			if (x == 0) {
				out << y << '\t';
			} else if (y == 0) {
				out << x << '\t';
			} else {
				out << x*y << '\t';
			}

		}
		out << '\n';
	}
}





