#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>

void chcount() {
	using input=std::istream_iterator<char>;
	input eof{};
	input in{std::cin};
	std::cout << distance(in,eof);
}

void chacount() {
	using input=std::istreambuf_iterator<char>;
	input eof{};
	input in{std::cin};
	std::cout << distance(in,eof);
}

void wcount() {
	using input=std::istream_iterator<std::string>;
	input eof{};
	input in{std::cin};
	std::cout << distance(in,eof);
}

void acount() {
	using input=std::istream_iterator<char>;
	input eof{};
	input in{std::cin};
	std::cout << count(in,eof,'a');
}

void lcount() {
	using input=std::istreambuf_iterator<char>;
	input eof{};
	input in{std::cin};
	std::cout << count(in,eof,'\n');
}

void sumi() {
	using input=std::istream_iterator<int>;
	input eof{};
	input in{std::cin};
	std::cout << accumulate(in,eof, 0);
}

void sumd() {
	using input=std::istream_iterator<double>;
	input eof{};
	input in{std::cin};
	//std::ostream_iterator<std::string> out{std::cout, " "};
	std::cout << accumulate(in,eof, 0.0);
}

// multab

// fractab

int main() {
	//chcount();
	//chacount();
	//wcount();
	//acount();
	//lcount();
	//sumi();
	sumd();
}
