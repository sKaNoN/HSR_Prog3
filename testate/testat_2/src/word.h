#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iosfwd>

class Word{
	std::string value;
	public:
		Word(std::string str);
		void read(std::istream& in);
		void print(std::ostream& out) const;
};

std::ostream& operator <<(std::ostream &out, Word const& word);
std::istream& operator >>(std::istream& in, Word &word);

#endif /* WORD_H_ */
