#include "date.h"

namespace date {

	bool Date::isValid() {
		switch (month) {
			case Month::Feb:
				if(day<=28) {
					return true;
				} else if(!year%4 && (year%100 || !year%400)) {
					return day==29;
				} else {
					return false;
				}
				break;
			case Month::Apr:
			case Month::Jun:
			case Month::Sep:
			case Month::Nov:
				return day<=30;
				break;
			default:
				return day<=31;
		}
		return true;
	}

	Date::Date(unsigned int d, Month m, unsigned int y) : day{d}, year{y}, month{m} {
		if(!isValid()) {
			throw "Invalid Date";
		}
	}
	Date::Date(Month m, unsigned int d, unsigned int y) : day{d}, year{y}, month{m} {
		if(!isValid()) {
			throw "Invalid Date";
		}
	}
}
