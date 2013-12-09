#include "dynArray.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

void DefaultConstructor() {
	dynArray<int> dyn{};
	ASSERT(dyn.empty());
}

void InitializerListConstructor() {
	dynArray<std::string> dyn{"hello", "world"};
	ASSERT_EQUAL("hello", dyn.at(0));
	ASSERT_EQUAL("world", dyn[1]);
	ASSERT_EQUAL(2, dyn.size());
}

void IteratorConstructor() {
	std::vector<double> v{4.2, 3.14, 6.66, 456.9867};
	dynArray<double> dyn(v.begin(), v.end());
	size_t n = dyn.size();

	ASSERT_EQUAL_DELTA(v[0], dyn[-n], 0.1);
	ASSERT_EQUAL_DELTA(v.at(1), dyn.at(1), 0.1);
	ASSERT_EQUAL_DELTA(v.at(2), dyn.at(-(n-2)), 0.1);
	ASSERT_EQUAL_DELTA(v[3], dyn.at(3), 0.1);

	ASSERT_EQUAL(4, dyn.size());
}

void OtherConstructor() {
	unsigned u = 12u;
	dynArray<unsigned> dyn(5, u);

	ASSERT_EQUAL(u, dyn[0]);
	ASSERT_EQUAL(u, dyn[4]);
	ASSERT_EQUAL(5, dyn.size());

}

void NegativeIndex() {
	dynArray<char> dyn{'a','b','c','x','y','z'};
	size_t n = dyn.size();
	ASSERT_EQUAL(dyn[0],dyn[-n]);
	ASSERT_EQUAL(dyn.at(1), dyn.at(-(--n)));
	ASSERT_EQUAL(dyn.at(2), dyn[-(--n)]);
	ASSERT_EQUAL(dyn[3], dyn.at(-(--n)));
}


void EraseAndClear() {
	dynArray<char> dyn{'a','b','c','x','y','z'};
	ASSERT_EQUAL(6, dyn.size());
	dyn.erase(dyn.cbegin());
	ASSERT_EQUAL(5, dyn.size());
	ASSERT_EQUAL('b', dyn[0]);
	dyn.erase(dyn.cbegin(), dyn.cbegin()+2);
	ASSERT_EQUAL(3, dyn.size());
	ASSERT_EQUAL('x', dyn[0]);
	dyn.clear();
	ASSERT(dyn.empty());

}

void PushAndPop() {
	dynArray<int> dyn{};
	ASSERT(dyn.empty());

	dyn.push_back(42);
	ASSERT_EQUAL(1, dyn.size());

	dyn.pop_back();
	ASSERT(dyn.empty());
}

void Resize() {
	dynArray<unsigned> dyn(4,2);
	ASSERT_EQUAL(4, dyn.size());

	dyn.resize(10);
	ASSERT_EQUAL(10, dyn.size());
	ASSERT_EQUAL(0, dyn.at(9));

	dyn.resize(15, 42);
	ASSERT_EQUAL(15, dyn.size());
	ASSERT_EQUAL(42, dyn.at(10));
	ASSERT_EQUAL(42, dyn.at(14));

	dyn.resize(4);
	ASSERT_EQUAL(4, dyn.size());
	ASSERT_EQUAL(2, dyn.at(3));
}

void NonConstIterators() {
	dynArray<std::string> dyn{"hello", "world!"};
	ASSERT_EQUAL("hello", *dyn.begin());
	*dyn.begin()="Hello";
	ASSERT_EQUAL("Hello", *dyn.begin());

	ASSERT_EQUAL("world!", *(dyn.end()-1));
	*(dyn.end()-1)="world";
	ASSERT_EQUAL("world", *(dyn.end()-1));
}

void ConstIterators() {
	dynArray<char> dyn{'h','e','l','l','o'};

	std::string str{dyn.cbegin(), dyn.cend()};

	ASSERT_EQUAL("hello", str);
}

void ReverseIterators() {
	dynArray<char> dyn{'h','e','l','l','o'};
	std::string str{dyn.cbegin(),dyn.cend()};
	ASSERT_EQUAL("hello", str);

	*(dyn.rend()-2) = 'a';
	std::string str1{dyn.cbegin(),dyn.cend()};
	ASSERT_EQUAL("hallo", str1);

	*dyn.rbegin()='i';

	std::string str2{dyn.cbegin(),dyn.cend()};
	ASSERT_EQUAL("halli", str2);
}

void ConstReverseIterators() {
	dynArray<char> dyn{'h','e','l','l','o'};
	std::string str{dyn.crbegin(), dyn.crend()};

	ASSERT_EQUAL("olleh", str);
}

void Factory() {
	makedynArray({"hello", "world"});
	dynArray<std::string> dyn{"hello", "world"};
	ASSERT_EQUAL("hello", dyn.at(0));
	ASSERT_EQUAL("world", dyn[1]);
	ASSERT_EQUAL(2, dyn.size());
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(DefaultConstructor));
	s.push_back(CUTE(InitializerListConstructor));
	s.push_back(CUTE(IteratorConstructor));
	s.push_back(CUTE(OtherConstructor));
	s.push_back(CUTE(NegativeIndex));
	s.push_back(CUTE(EraseAndClear));
	s.push_back(CUTE(PushAndPop));
	s.push_back(CUTE(Resize));
	s.push_back(CUTE(NonConstIterators));
	s.push_back(CUTE(ConstIterators));
	s.push_back(CUTE(ReverseIterators));
	s.push_back(CUTE(ConstReverseIterators));
	s.push_back(CUTE(Factory));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    dynArray<char> a1{};
    dynArray<int> a2{1,2,3,4,5}; // initializer_list
    dynArray<double> a3(10,3.14); // count + value
    dynArray<std::string> a4(std::istream_iterator<std::string>{std::cin},std::istream_iterator<std::string>{});
    return 0;
}



