#include "isPalindrome.h"
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ifstream myfile;
  myfile.open ("/usr/share/dict/words");
  std::string line;
  if (myfile.is_open())
  {
	  while ( getline (myfile,line) )
      {
    	  if(is_palindrome(line)){
    		  std::cout << line << "\n";
    	  }
      }
  }

  myfile.close();
  return 0;
}
