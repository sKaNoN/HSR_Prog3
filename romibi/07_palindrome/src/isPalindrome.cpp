#include "isPalindrome.h"
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>

bool is_palindrome(std::string word) {
	boost::to_lower(word);
	std::string reversedWord(word);
	copy(word.rbegin(),word.rend(),reversedWord.begin());
	if( word == reversedWord ) return true;
	return false;
}
