#include "Word.h"
#include <string>
#include <iostream>
#include <sstream>

int main() {
	std::string bla { "bla" };
	std::istringstream blubb{ "blubb" };
	Word x{bla};
	//blubb >> x;
	std::cout << x;
}
