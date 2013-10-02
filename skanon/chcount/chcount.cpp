#include <iterator>
#include <iostream>
#include <algorithm>
#include <numeric>

void charCount(std::istream &cin, std::ostream &cout) {
	using input=std::istream_iterator<char>;
	input eof{};
	input in{cin};

	std::ostream_iterator<std::string>out{cout," "};
	cout << "without whitespaces: " << distance(in,eof);
}

void charCountWithWhitespace(std::istream &cin, std::ostream &cout) {
	using input=std::istreambuf_iterator<char>;
	input eof{};
	input in{cin};

	cout << "With whitespaces: "<< distance(in,eof);
}

void wordCount(std::istream &cin, std::ostream &cout) {
	using input=std::istream_iterator<std::string>;
	input eof{};
	input in{cin};

	cout << "Words: "<< distance(in,eof);
}

void aCount(std::istream &cin, std::ostream &cout) {
	using input=std::istream_iterator<char>;
	input eof{};
	input in{cin};

	cout << "a's: "<< count(in,eof,'a');
}

void lineCount(std::istream &cin, std::ostream &cout) {
	using input=std::istreambuf_iterator<char>;
	input eof{};
	input in{cin};

	cout << "lines: "<< count(in,eof,'\n');
}

void sumi(std::istream &cin, std::ostream &cout) {
	using input=std::istream_iterator<int>;
	input eof{};
	input in{cin};

	cout << "sumi: "<< accumulate(in,eof,0);
}

void sumd(std::istream &cin, std::ostream &cout) {
	using input=std::istream_iterator<double>;
	input eof{};
	input in{cin};

	cout << "sumd: "<< accumulate(in,eof,0.);
}

int main(){
	//charCount(std::cin, std::cout);
	//charCountWithWhitespace(std::cin, std::cout);
	//wordCount(std::cin, std::cout);
	//aCount(std::cin, std::cout);
	//lineCount(std::cin, std::cout);
	sumd(std::cin, std::cout);
}

