#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "sevenSegment.h"
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

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testScalingNegative));
	s.push_back(CUTE(testScalingZero));
	s.push_back(CUTE(testScalingTwo));
	s.push_back(CUTE(testScalingThree));
	s.push_back(CUTE(testScalingOverflow));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

//int main(int argc, char const *argv[]){
//    runAllTests(argc,argv);
//    return 0;
//}



