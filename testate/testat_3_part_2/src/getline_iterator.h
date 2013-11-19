#ifndef GETLINE_ITERATOR_H_
#define GETLINE_ITERATOR_H_

#include <boost/operators.hpp>
#include <string>
#include <iosfwd>

struct line_iterator : boost::input_iterator_helper<line_iterator, std::string> {

	explicit line_iterator(std::istream &input):in(input) {
		++(*this);
	}

	line_iterator();

	value_type operator *() {
		return value;
	}

	line_iterator& operator++() {
		std::getline(in, value);
		return *this;
	}

	bool operator==(const line_iterator& other) const;

private:
	std::istream &in;
	std::string value{};
};

#endif /* GETLINE_ITERATOR_H_ */
