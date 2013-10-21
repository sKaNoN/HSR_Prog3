#include "Date.h"
#include <stdexcept>

namespace date {
bool checkValidDate(unsigned d, date::Month m, unsigned y) {
	switch (m) {
	case Month::Jan:
	case Month::Mar:
	case Month::Mai:
	case Month::Jul:
	case Month::Aug:
	case Month::Oct:
	case Month::Dec: return (d<=31);
	case Month::Apr:
	case Month::Jun:
	case Month::Sep:
	case Month::Nov: return (d<=30);
	case Month::Feb: {
		if (!y%4) {
			if (!y%100){
				if (y%400) return (d<=29);
			}
		}
		return (d<=28);
	}
	default: return false;
}
}
Date::Date(unsigned d, Month m, unsigned y) :
		day { d }, month { m }, year { y } {
		if(!checkValidDate(d , m ,y)){
			throw std::out_of_range{"Invalid Arguments"};
		}

};
}
