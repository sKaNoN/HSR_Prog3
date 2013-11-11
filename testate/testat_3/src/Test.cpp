#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <functional>
#include <cmath>

void xPlusY() {
	using std::placeholders::_1;
	using std::placeholders::_2;
	auto func=std::bind(std::plus<double>{}, _1, _2);
	double x = 2;
	double y = 5;
	ASSERT_EQUAL((x+y),func(x,y));
}

void twoXMinusYthird() {
	using std::placeholders::_1;
	using std::placeholders::_2;
	auto firstinner=std::bind(std::multiplies<double>{}, 2, _1);
	auto secondinner=std::bind(std::divides<double>{}, _1, 3);
	auto func=std::bind(std::minus<double>{}, bind(firstinner,_1), bind(secondinner,_2));
	double x = 2;
	double y = 5;
	ASSERT_EQUAL(((2 * x) - (y / 3)),func(x,y));
}

void squaredXmodY() {
	using std::placeholders::_1;
	using std::placeholders::_2;
	auto square=std::bind(std::multiplies<unsigned>{}, _1, _1);
	auto func=std::bind(std::modulus<unsigned>{}, bind(square,_1), _2);
	unsigned x = 2;
	unsigned y = 5;
	ASSERT_EQUAL(((x * x) % y),func(x,y));
}

void squareRootXpowered() {
	using std::placeholders::_1;
	using std::placeholders::_2;

	struct sqrt_functor {
		double operator()(double y) { return sqrt(y); }
	} sqrtfnc;

	auto square=std::bind(std::multiplies<double>{}, _1, _1);
	auto func=std::bind(sqrtfnc, bind(square,_1));
	//auto func=std::bind(static_cast<double(*)(double)>(sqrt),bind(square,_1));

	double x = 2;
	ASSERT_EQUAL((sqrt(x * x)),func(x));
}


void wtf() {
	using std::placeholders::_1;
	using std::placeholders::_2;

	struct sqrt_functor {
		double operator()(double y) { return sqrt(y); }
	} sqrtfnc;

	auto square=std::bind(std::multiplies<double>{}, _1, _1);
	auto half=std::bind(std::divides<double>{},_1,2);
	auto squarerootinner=std::bind(std::minus<double>{}, bind(square,bind(half,_1)), _2);

	auto func=std::bind(std::minus<double>{}, bind(sqrtfnc,bind(squarerootinner,_1,_2)),bind(half,_1));

	double x = 20; //problem mit 2...
	double y = 5;
	ASSERT_EQUAL((-(x/2)+sqrt( (x/2)*(x/2) - y )),func(x,y));

}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(xPlusY));
	s.push_back(CUTE(twoXMinusYthird));
	s.push_back(CUTE(squaredXmodY));
	s.push_back(CUTE(squareRootXpowered));
	s.push_back(CUTE(wtf));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



