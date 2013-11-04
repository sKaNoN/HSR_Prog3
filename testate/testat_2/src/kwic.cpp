#include "kwic.h"
#include "word.h"
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <iostream>
#include <sstream>

struct sentence:std::vector<Word>{
	using std::vector<Word>::vector;
};

sentence rotate(sentence const s, size_t const pos){
	sentence rotated{s};
	std::rotate_copy(s.begin(), s.begin()+pos, s.end(), rotated.begin());
	return rotated;
}

void generate_rotations(sentence s,
		std::multiset<sentence>& result) {
	for(size_t i=0; i <s.size(); ++i){
		rotate(s.begin(),s.begin()+1, s.end());
		result.insert(s);
	}
}



std::istream& operator>>(std::istream &is,sentence &s){
	using input=std::istream_iterator<Word>;
	std::string line;
	if (getline(is,line)){
		s.clear();
		std::istringstream forSplit{line};
		copy(input{forSplit},input{},back_inserter(s));
	}
	return is;
}

std::ostream& operator<<(std::ostream &os,sentence const &s){
	std::copy(s.begin(),s.end(),std::ostream_iterator<Word>(os," "));
	return os;
}

void kwic(std::istream& in, std::ostream& out) {
	std::vector<sentence> sentences{};
	std::multiset<sentence> result{};

	using inputstream = std::istream_iterator<sentence>;
	std::copy(inputstream{in},inputstream{},std::back_inserter(sentences));

	std::for_each(sentences.begin(), sentences.end(),[&result](sentence s){
		generate_rotations(s, result);

	});

	copy(result.begin(),result.end(),std::ostream_iterator<sentence>{out,"\n"});

}
