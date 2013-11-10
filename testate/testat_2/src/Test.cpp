#include "kwic.h"
#include "word.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "word.h"
#include "sstream"

void testKwicWith1LineInput() {
	std::stringstream in{"this is a test"};
	std::stringstream out{};
	kwic(in, out);
	ASSERT_EQUAL("a test this is \n"
			"is a test this \n"
			"test this is a \n"
			"this is a test \n", out.str());
}

void testKwicWith2LineInput() {
	std::stringstream in{"this is a test\n"
						"avocado has an old hat"};
	std::stringstream out{};
	kwic(in, out);
	ASSERT_EQUAL("a test this is \n"
			"an old hat avocado has \n"
			"avocado has an old hat \n"
			"has an old hat avocado \n"
			"hat avocado has an old \n"
			"is a test this \n"
			"old hat avocado has an \n"
			"test this is a \n"
			"this is a test \n", out.str());
}

void testKwicWithCasedWords() {
	std::stringstream in{"An aN anD And"};
	std::stringstream out{};
	kwic(in, out);
	ASSERT_EQUAL("an an and and \n"
			"an and and an \n"
			"and an an and \n"
			"and and an an \n", out.str());
}

void testKwicWithLeetWords() {
	std::stringstream in{"th12 12 4 t35t"};
		std::stringstream out{};
		kwic(in, out);
		ASSERT_EQUAL("t t th \n"
				"t th t \n"
				"th t t \n", out.str());
}

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
	ASSERT_EQUAL("word",w);
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
	s.push_back(CUTE(testKwicWith1LineInput));
	s.push_back(CUTE(testKwicWith2LineInput));
	s.push_back(CUTE(testKwicWithCasedWords));
	s.push_back(CUTE(testKwicWithLeetWords));
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



