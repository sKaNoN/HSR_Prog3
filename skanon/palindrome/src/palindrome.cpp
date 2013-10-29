#include "palindrome.h"
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>

bool is_palindrome(std::string str) {
	boost::to_lower(str);
	std::string reverse{str};
	std::copy(str.rbegin(), str.rend(), reverse.begin());
	if (str == reverse) return true;
	else return false;
}
