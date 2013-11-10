#include "kwic.h"
#include "word.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "word.h"

void testStringConstructor() {
	Word w{"hello"};
	ASSERT_EQUAL("hello", w);
}

void emptyWordNotAllowed() {
	ASSERT_THROWS(Word{""}, std::invalid_argument);
}

void wordLessThan(){
	Word w{"hallo"};
	Word v{"Hello"};
	ASSERT(w < v);
}

void wordOutputOperator(){
	std::ostringstream out;
	Word w{"hallo"};
	out << w;
	ASSERT_EQUAL("hallo",out.str());
}

void wordInputOperatorNormal(){
	std::istringstream in{"Hello World"};
	Word w{"emptyword"};
	in >> w;
	ASSERT_EQUAL("hello",w);
	in >> w;
	ASSERT_EQUAL("world",w);
}
void wordInputOperatorFails(){
	std::istringstream in{};
	Word w{"word"};
	in >> w;
	ASSERT(in.fail());
}
void wordInputOperatorParsesSentences(){
	std::istringstream in{"Hello,world!"};
	Word w{"emptyword"};
	in >> w;
	ASSERT_EQUAL("hello",w);
	in >> w;
	ASSERT_EQUAL("world",w);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testStringConstructor));
	s.push_back(CUTE(emptyWordNotAllowed));
	s.push_back(CUTE(wordLessThan));
	s.push_back(CUTE(wordOutputOperator));
	s.push_back(CUTE(wordInputOperatorNormal));
	s.push_back(CUTE(wordInputOperatorFails));
	s.push_back(CUTE(wordInputOperatorParsesSentences));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}


int main(int argc, char const *argv[]){
    runAllTests(argc,argv);

    return 0;

}



