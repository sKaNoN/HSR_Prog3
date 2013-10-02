#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "helloworld.h"

void thisIsATest() {
	std::ostringstream os;
	helloworld(os);
	ASSERT_EQUAL("Hello World!\n", os.str());
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



