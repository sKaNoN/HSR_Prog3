#include "word.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <sstream>


bool checkWord(std::string const &w){
	return (w.empty()
	   ||count_if(w.begin(),w.end(),[](char c){return !isalpha(c);}));
}

Word::Word(std::string const str){
	if (checkWord(str))
		throw std::invalid_argument{"Invalid word characters"};

	std::stringstream ss;
	ss << str;
	read(ss);
}

Word::Word(std::istream &in){
	read(in);
}

std::ostream& Word::print(std::ostream& out) const{
	out << value;
	return out;
}

std::istream& Word::read(std::istream &in){
	char character{};
	std::string w{};
	while(in.get(character) && !std::isalpha(character));
	while (std::isalpha(character)){
		w += character;
		if (!in.get(character)) break;
	}
	if (checkWord(w))
		 in.clear(std::ios::failbit);
	else {
		value=w;
		if (in.eof()) in.clear();
	}

	return in;
}

bool Word::operator==(Word const &otherword) const {
	return value == otherword.value;
}

bool Word::operator<(Word const &otherword) const {
	return value < otherword.value;
}

bool Word::operator==(char const *otherptr) const {
	std::string otherword{otherptr};
	return value == otherword;
}

std::ostream& operator<<(std::ostream &out, Word const& word){
	word.print(out);
	return out;
}

std::istream& operator>>(std::istream& in, Word &word){
	word.read(in);
	return in;
}
