#include "getline_iterator.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <sstream>

void DefaultEqualsEmpty() {
	std::istringstream eof{};
	getline_iterator it{eof};
	getline_iterator it1{};

	ASSERT(it1 == it);
}

void InputConstructorNotEmpty() {
	std::istringstream in{"hello"};
		getline_iterator it{in};
		getline_iterator eof{};

		ASSERT(it != eof);
}

void ReadsLineCorrectly() {
	std::istringstream in{"hello\n"};
		getline_iterator it{in};

		ASSERT("hello" == *it++);
}

void ReadsMultipleLineCorrectly() {
	std::istringstream in{"hello\nworld\n"};
		getline_iterator it{in};

		ASSERT("hello" == *it++);
		ASSERT("world" == *it++);

}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(DefaultEqualsEmpty));
	s.push_back(CUTE(InputConstructorNotEmpty));
	s.push_back(CUTE(ReadsLineCorrectly));
	s.push_back(CUTE(ReadsMultipleLineCorrectly));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



