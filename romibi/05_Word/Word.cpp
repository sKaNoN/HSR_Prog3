#include "Word.h"
#include <string>
#include <iostream>
#include <sstream>

void Word::read(std::ostream &out) const {
	out << value;
}

void Word::write(std::istream &in) {
	in >> value;
}


Word::Word(std::string str){
	std::stringstream strstream;
	strstream << str;
	write(strstream);
}


std::istream& operator >> (std::istream &in, Word &word) {
	word.write(in);
	return in;
}
std::ostream& operator << (std::ostream &out, Word const &word) {
	word.read(out);
	return out;
}
