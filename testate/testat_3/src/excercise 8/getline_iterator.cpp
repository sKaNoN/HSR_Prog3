#include "getline_iterator.h"
#include <sstream>

namespace {
std::istringstream empty{}; // a global helper needed...
}

line_iterator::line_iterator():in(empty) {
	 in.clear(std::ios_base::eofbit); // guarantee it is not good()
}



