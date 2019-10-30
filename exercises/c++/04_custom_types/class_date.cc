#include <iostream>

bool is_leap(const int y);
enum class Month {                                  														// scoped enum for month
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
	private:
		int _y;								// year
		Month _m;  
		int _d;								// day
		
		void add_1day();
		void next_month(int n);
	
	
	public:
		Date(int d, Month m, int y): _d{d}, _m{m}, _y{y} {} 			// constructor
		int day() const { return _d; }
		Month month() const { return _m; }
		int year() const { return _y; }
		void add_days(const unsigned int n)	{                           // add n days calling add_1day n times
			for(int i{0}; i<n; i++)
				add_1day();
			}
};

void Date::next_month(int n) {												     // private function call by add_1_day: increment day and month accordingly
	if (_d < n)
		_d = _d +1;
	else if (_d == n) {
		int m = static_cast<int>(_m);
		_d = 1;
		if (_m == Month::dec) {
			_m = Month::jan;
			++_y;
		} 
		else _m = Month(m+1);
	}
}	

void Date::add_1day() {                                                                // take into account also leap year
	switch(_m) {
		case Month::jan: case Month::mar: case Month::may: case Month::jul:
		case Month::aug: case Month::oct: case Month::dec:
			next_month(31); 
			break;
			
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			next_month(30);
			break;
			
		case Month::feb:
			if (!is_leap(_y)) next_month(28);
			else if (is_leap(_y)) next_month(29);
			break;
	}
}


/// helper functions ///

bool operator==(const Date& lhs, const Date&rhs) {
	return lhs.year() == rhs.year()
		&& lhs.month() == rhs.month()
		&& lhs.day() == rhs.day();
}

bool operator!=(const Date& lhs, const Date& rhs) {
	return lhs.year() != rhs.year()
		&& lhs.month() != rhs.month()
		&& lhs.day() != rhs.day();
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
	return os << d.day() << "/" << int(d.month()) << "/" << d.year() << "\n";
}

bool is_leap(const int y) {
	if ((y%400 == 0) || (y%4 == 0 && y%100 !=0)) {	
		return true;
	}
	else return false;
}


int main() {
	int d,y;
	int n{100};
	Month m;
	Date dd{28,Month::feb,2020};
	dd.add_days(n);
	std::cout << dd;
	
return 0;
}