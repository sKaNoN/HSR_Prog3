#ifndef GETLINE_ITERATOR_H_
#define GETLINE_ITERATOR_H_

#include <boost/operators.hpp>
#include <string>
#include <iostream>

struct getline_iterator : boost::input_iterator_helper<getline_iterator, std::string> {

	explicit getline_iterator(std::istream &input):in(input) {
		++(*this);
	}

	getline_iterator();

	value_type operator *() {
		return value;
	}

	getline_iterator& operator++() {
		std::getline(in, value);
		if (in.eof() && value.size()) in.clear();
		return *this;
	}

	bool operator==(const getline_iterator& other) const;

private:
	std::istream &in;
	std::string value{};
};

#endif /* GETLINE_ITERATOR_H_ */
