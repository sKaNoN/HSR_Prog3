#include "word.h"
#include <iostream>
#include <sstream>

int main() {
		std::stringstream stream{"blah blubb! blubbedi :blubb"};
		Word word{""};
		stream >> word;
		std::cout << word << "\n";
		stream >> word;
		std::cout << word << "\n";
		stream >> word;
		std::cout << word << "\n";
		stream >> word;
		std::cout << word << "\n";
		stream >> word;
		std::cout << word << "\n";
}
