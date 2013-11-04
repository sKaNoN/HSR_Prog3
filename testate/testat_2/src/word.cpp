#include "word.h"
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

Word::Word(std::istream &in){
	read(in);
}

void Word::print(std::ostream& out) const{
	out << value;
}

void Word::read(std::istream &in){
	char character{};
	std::string w;
	while(in.get(character) && !std::isalpha(character));
	if(std::isalpha(character)) w.push_back(tolower(character));
	while(in.get(character) && std::isalpha(character)) {
		w.push_back(tolower(character));
	}
	//if(w.length()==0) throw std::invalid_argument("No Word-Input Found");
	value = w; //oder value.push_back(w); ?
}

std::ostream& operator<<(std::ostream &out, Word const& word){
	word.print(out);
	return out;
}

std::istream& operator>>(std::istream& in, Word &word){
	word.read(in);
	return in;
}
