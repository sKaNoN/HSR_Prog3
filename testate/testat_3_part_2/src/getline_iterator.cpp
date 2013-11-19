#include "getline_iterator.h"
#include <sstream>

namespace {
std::istringstream empty{}; // a global helper needed...
}

getline_iterator::getline_iterator():in(empty) {
	 in.clear(std::ios_base::eofbit); // guarantee it is not good()
}


bool getline_iterator::operator==(const getline_iterator& other) const {
	 return !in.good() && !other.in.good();
}
