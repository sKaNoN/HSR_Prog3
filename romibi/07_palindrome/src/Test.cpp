#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "isPalindrome.h"

void isPalindromeTrueTest() {
	ASSERT(is_palindrome("otto"));
}

void isPalindromeFalseTest(){
	ASSERT(!is_palindrome("ottomobil"));
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(isPalindromeTrueTest));
	s.push_back(CUTE(isPalindromeFalseTest));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

//int main(int argc, char const *argv[]){
//    runAllTests(argc,argv);
//    return 0;
//}



