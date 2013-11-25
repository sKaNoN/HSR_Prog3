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
	dynArray(size_type size, T const &value):v(size,value){}
	dynArray(std::initializer_list<T> il):v(il){}

	template <typename ITER>
		 dynArray(ITER b, ITER e):v(b,e){}

	size_type size() const { return v.size();}
	size_type capacity() const {return v.capacity();}

	bool empty() const { return v.empty();}

	T & front() { return v.front();}
	T const& front() const { return v.front();}

	T & back() {return v.back();}
	T const& back() const { return v.back();}

	T & at(size_type pos) {
		if (pos<0) return v.at(size()+pos);
		else return v.at(pos);
	}

	T const& at(size_type pos) const {
		if (pos<0) return v.at(size()+pos);
		else return v.at(pos);
	}

	T & operator[]( size_type pos) { return at(pos);}
	T const & operator[]( size_type pos ) const { return at(pos);}

	void clear(){v.clear();}
	iterator erase( const_iterator pos ) {return v.erease(pos);}
	iterator erase( const_iterator first, const_iterator last ) {return v.erease(first,last);}

	void push_back( const T& value ) { v.push_back(value);}
	void pop_back () {v.pop_back();}

	void resize( size_type count ) { v.resize(count);}
	void resize( size_type count, const T& value) {v.resize(count, value);}

	iterator begin() const {return v.begin();}
	iterator end() const {return v.end();}
	const_iterator cbegin() const {return v.cbegin();}
	const_iterator cend() const {return v.cend();}
	reverse_iterator rbegin() const {return v.rbegin();}
	reverse_iterator rend() const {return v.rend();}
	const_reverse_iterator crbegin() const {return v.crbegin();}
	const_reverse_iterator crend() const {return v.crend();}
};

#endif /* DYNARRAY_H_ */
