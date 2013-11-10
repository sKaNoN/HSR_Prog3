#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iosfwd>
#include <boost/operators.hpp>

class Word{
	std::string value;
	public:
		Word()=default;
		Word(std::string str);
		Word(std::istream &in);
		std::istream& read(std::istream& in);
		std::ostream& print(std::ostream& out) const;
		bool operator== (Word const &otherword) const;
		bool operator< (Word const &otherword) const;
};

std::ostream& operator <<(std::ostream &out, Word const& word);
std::istream& operator >>(std::istream& in, Word &word);

#endif /* WORD_H_ */
