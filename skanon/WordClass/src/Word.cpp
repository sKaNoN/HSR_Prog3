#include "Word.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <sstream>


Word::Word(std::string str){
	std::stringstream ss;
	ss << str;
	read(ss);
}

void Word::print(std::ostream& out) const{
	out << value;
}

void Word::read(std::istream &in){

	std::string w;
	in >> w;
	value.insert(value.end(),w.begin(),w.end());

}

std::ostream& operator<<(std::ostream &out, Word const& word){
	word.print(out);
	return out;
}

std::istream& operator>>(std::istream& in, Word &word){
	word.read(in);
	return in;
}
