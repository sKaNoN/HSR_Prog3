#ifndef DATE_H_
#define DATE_H_

#include <iosfwd>
namespace date {

enum class Month {
	Jan=1, Feb, Mar, Apr, Mai, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

class Date {
	unsigned day;
	Month month;
	unsigned year;

public:
	explicit Date(std::istream &in);
	Date(unsigned d, Month m, unsigned y);
//	Date(Month m, unsigned d, unsigned y);
	Month day_of_week();
};
}

#endif /* DATE_H_ */
