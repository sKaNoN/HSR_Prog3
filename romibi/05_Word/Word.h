#ifndef WORD_H_
#define WORD_H_

#include <string>

class Word {
	std::string value;
public:
	void read(std::ostream &out) const;
	void write(std::istream &in);
	Word(std::string str);
};

std::istream& operator >> (std::istream &in, Word &word);
std::ostream& operator << (std::ostream &out, Word const &word);
#endif /* WORD_H_ */
