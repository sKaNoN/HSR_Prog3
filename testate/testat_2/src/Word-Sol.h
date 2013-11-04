#ifndef WORD_H_
#define WORD_H_
#include <iosfwd>
#include <string>
#include <boost/operators.hpp>

struct Word : boost::equality_comparable<Word>
, boost::equality_comparable<Word,char const *>
, boost::less_than_comparable<Word>
, boost::less_than_comparable<Word, char const *>{
	Word()=default; // allow empty words for storing in vector.
	Word(std::string const &word);
	bool operator==(Word const &other) const {
		return stringcaselessequal(w,other.w);
	}
	bool operator==(char const *otherptr) const {
		std::string other{otherptr};
		return stringcaselessequal(w,other);
	}
	bool operator<(Word const &other) const {
		return stringcaselessless(w,other.w);
	}
	bool operator<(char const *othercptr) const {
			std::string other{othercptr};
			return stringcaselessless(w,other);
	}
	std::ostream& print(std::ostream& out) const;
	std::istream& read(std::istream& in);
private:
	static bool stringcaselessequal(std::string const &w, std::string const &other);
	static bool stringcaselessless(std::string const &w, std::string const &other);
	std::string w;
};
inline std::ostream &operator<<(std::ostream &out,Word const &w){
	return w.print(out);
}
inline std::istream &operator>>(std::istream &in, Word &w){
	return w.read(in);
}
#endif /* WORD_H_ */
