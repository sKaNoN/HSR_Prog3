#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#include <vector>

template<typename T>
class dynArray {

	using vector=std::vector<T>;
	vector v;

public:
	using size_type = typename vector::size_type;
	using iterator = typename vector::iterator;
	using const_iterator = typename vector::const_iterator;
	using reverse_iterator = typename vector::reverse_iterator;
	using const_reverse_iterator = typename vector::const_reverse_iterator;

	dynArray() = default;




	size_type size() const {
		return v.size();
	}

	T const& at(size_type index) const {
		if (index<0) return v.at(size()+index);
		else return v.at(index);
	}

};

#endif /* DYNARRAY_H_ */
