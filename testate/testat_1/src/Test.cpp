#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "sevenSegment.h"
#include "calc.h"
#include <iostream>
#include <sstream>

void testScalingNegative() {
	std::ostringstream os;
	std::stringstream ss;
	ss << 42;
	sevenSegment(ss,-5,os);
	std::string str{"    - \n| |  |\n -  - \n  ||  \n    - \n"};
	ASSERT_EQUAL(str,os.str());
}

void testScalingZero() {
	std::ostringstream os;
	std::stringstream ss;
	ss << 42;
	sevenSegment(ss,0,os);
	std::string str{"    - \n| |  |\n -  - \n  ||  \n    - \n"};
	ASSERT_EQUAL(str,os.str());
}

void testScalingTwo() {
	std::ostringstream os;
	std::stringstream ss;
	ss << 42;
	sevenSegment(ss,2,os);
	std::string str{"     -- \n|  |   |\n|  |   |\n --  -- \n   ||   \n   ||   \n     -- \n"};
	ASSERT_EQUAL(str,os.str());
}

void testScalingThree() {
	std::ostringstream os;
	std::stringstream ss;
	ss << 42;
	sevenSegment(ss,3,os);
	std::string str{"      --- \n|   |    |\n|   |    |\n|   |    |\n ---  --- \n    ||    \n    ||    \n    ||    \n      --- \n"};
	ASSERT_EQUAL(str,os.str());
}

void testScalingOverflow() {
	std::ostringstream os;
	std::stringstream ss;
	ss << 42;
	sevenSegment(ss,26,os);
	std::string str{" -             \n|              \n -  -  -  -  - \n|  |  |  | ||  \n -        -    \n"};
	ASSERT_EQUAL(str,os.str());
}

void testInputNegative() {
	std::ostringstream os;
	std::stringstream ss;
	ss << -42;
	sevenSegment(ss,1,os);
	std::string str{" -             \n|              \n -  -  -  -  - \n|  |  |  | ||  \n -        -    \n"};
	ASSERT_EQUAL(str,os.str());
}

void testInputInvalid() {
	std::ostringstream os;
	std::stringstream ss;
	ss << "4f2sdf";
	sevenSegment(ss,1,os);
	std::string str{" -             \n|              \n -  -  -  -  - \n|  |  |  | ||  \n -        -    \n"};
	ASSERT_EQUAL(str,os.str());
}

void testAnotherInputInvalid() {
	std::ostringstream os;
	std::stringstream ss;
	ss << "wer42";
	sevenSegment(ss,1,os);
	std::string str{" -             \n|              \n -  -  -  -  - \n|  |  |  | ||  \n -        -    \n"};
	ASSERT_EQUAL(str,os.str());
}

void testAdd() {
	ASSERT_EQUAL(8,add(3,5));
	ASSERT_EQUAL(3,add(0,3));
	ASSERT_EQUAL(7,add(7,0));
	ASSERT_EQUAL(0,add(0,0));
	ASSERT_EQUAL(3,add(-1,4));
	ASSERT_EQUAL(2,add(6,-4));
}

void testSub() {
	ASSERT_EQUAL(-2,sub(3,5));
	ASSERT_EQUAL(-3,sub(0,3));
	ASSERT_EQUAL(7,sub(7,0));
	ASSERT_EQUAL(0,sub(0,0));
	ASSERT_EQUAL(-5,sub(-1,4));
	ASSERT_EQUAL(10,sub(6,-4));
	ASSERT_EQUAL(2,sub(5,3));
	ASSERT_EQUAL(3,sub(3,0));
	ASSERT_EQUAL(-7,sub(0,7));
	ASSERT_EQUAL(5,sub(4,-1));
	ASSERT_EQUAL(-10,sub(-4,6));
}

void testMult() {
	ASSERT_EQUAL(15,mult(3,5));
	ASSERT_EQUAL(0,mult(0,3));
	ASSERT_EQUAL(0,mult(7,0));
	ASSERT_EQUAL(0,mult(0,0));
	ASSERT_EQUAL(-4,mult(-1,4));
	ASSERT_EQUAL(-24,mult(6,-4));
}

void testDivide() {
	ASSERT_EQUAL(0,divide(3,5));
	ASSERT_EQUAL(0,divide(0,3));
	ASSERT_EQUAL(0,divide(-1,4));
	ASSERT_EQUAL(-1,divide(6,-4));
	ASSERT_EQUAL(1,divide(5,3));
	ASSERT_EQUAL(0,divide(0,7));
	ASSERT_EQUAL(-4,divide(4,-1));
	ASSERT_EQUAL(0,divide(-4,6));
}

void testMod() {
	ASSERT_EQUAL(3,mod(3,5));
	ASSERT_EQUAL(0,mod(0,3));
	ASSERT_EQUAL(-1,mod(-1,4));
	ASSERT_EQUAL(2,mod(6,-4));
	ASSERT_EQUAL(2,mod(5,3));
	ASSERT_EQUAL(0,mod(0,7));
	ASSERT_EQUAL(0,mod(4,-1));
	ASSERT_EQUAL(-4,mod(-4,6));
}

void testCheckOperatorAndCalc() {
	ASSERT_EQUAL("19", checkOperatorAndCalc(12,'+',7).str());
	ASSERT_EQUAL("5", checkOperatorAndCalc(12,'-',7).str());
	ASSERT_EQUAL("84", checkOperatorAndCalc(12,'*',7).str());
	ASSERT_EQUAL("1", checkOperatorAndCalc(12,'/',7).str());
	ASSERT_EQUAL("Error", checkOperatorAndCalc(12,'/',0).str());
	ASSERT_EQUAL("5", checkOperatorAndCalc(12,'%',7).str());
	ASSERT_EQUAL("Error", checkOperatorAndCalc(12,'%',0).str());
}

void testCalc() {
	std::stringstream ss1;
	ss1 << "123+456";
	ASSERT_EQUAL("579", calc(ss1).str());

	std::stringstream ss2;
	ss2 << "456/123";
	ASSERT_EQUAL("3", calc(ss2).str());

	std::stringstream ss3;
	ss3 << "123 % 456";
	ASSERT_EQUAL("123", calc(ss3).str());

	std::stringstream ss4;
	ss4 << "123 456 %";
	ASSERT_EQUAL("Error", calc(ss4).str());

	std::stringstream ss5;
	ss5 << "-12 / 6";
	ASSERT_EQUAL("-2", calc(ss5).str());

	std::stringstream ss6;
	ss6 << "12 / -6";
	ASSERT_EQUAL("-2", calc(ss6).str());

	std::stringstream ss7;
	ss7 << "irgend etwas das kein sinn ergibt";
	ASSERT_EQUAL("Error", calc(ss7).str());
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(testScalingNegative));
	s.push_back(CUTE(testScalingZero));
	s.push_back(CUTE(testScalingTwo));
	s.push_back(CUTE(testScalingThree));
	s.push_back(CUTE(testScalingOverflow));
	s.push_back(CUTE(testInputNegative));
	s.push_back(CUTE(testInputInvalid));
	s.push_back(CUTE(testAnotherInputInvalid));
	s.push_back(CUTE(testAdd));
	s.push_back(CUTE(testSub));
	s.push_back(CUTE(testMult));
	s.push_back(CUTE(testDivide));
	s.push_back(CUTE(testMod));
	s.push_back(CUTE(testCalc));
	s.push_back(CUTE(testCheckOperatorAndCalc));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
}



