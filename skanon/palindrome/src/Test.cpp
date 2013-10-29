#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "palindrome.h"
#include <fstream>
#include <iostream>

void testCorrectPalindrome() {
	std::string otto{"Otto"};
	ASSERT_EQUAL(true, is_palindrome(otto));
}

void testWrongPalindrome() {
	std::string haus{"Haus"};
	ASSERT_EQUAL(false, is_palindrome(haus));
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testCorrectPalindrome));
	s.push_back(CUTE(testWrongPalindrome));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    std::ifstream myfile;
    myfile.open("/usr/share/dict/words");
    std::string line;
    if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
          if (is_palindrome(line))
        	  std::cout << line << "\n";
        }
        myfile.close();
      }


    return 0;
}



