#ifndef DATE_H_
#define DATE_H_

namespace date {enum class Month {
	Jan=1, Feb, Mar, Apr, Mai, Jun, Jul, Aug, Sep, Okt, Nov, Dez
};

	class Date {



	private:
		unsigned int day,year;
		Month month;

		bool isValid();

	public:
		Date(unsigned int d, Month m, unsigned int y);
		Date(Month m, unsigned int d, unsigned int y);
	};
}


#endif /* DATE_H_ */
