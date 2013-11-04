#include "Word.h"
#include <algorithm>
#include <vector>

struct sentence:std::vector<Word>{
	using std::vector<Word>::vector;
};

