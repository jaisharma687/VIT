#include <iostream>
using namespace std;

const int DaysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
enum Months { unused, January, February, March, April, May, June, July, August, September, October, November, December };
const char *MonthNames[]={"Unused", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

class Date {
    friend bool before(Date &d1, Date &d2);

public:
    Date(int d = 1, int m = 1, int y = 1970) {
        setMonth(m);
        setDay(d);
        setYear(y);
    }

    ~Date() {}

    Date(const Date &date) {
        day = date.day;
        month = date.month;
        year = date.year;
    }

    int getDay() { return day; }

    void setDay(int d) {
        if (d > 0 && d <= DaysInMonth[month]) {
            day = d;
        }
        else {
            cerr << "Invalid Day value " << d << endl;
            exit(1);
        }
    }

    int getMonth() { return month; }

    void setMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
        }
        else {
            cerr << "Invalid Month value " << m << endl;
            exit(1);
        }
    }

    int getYear() { return year; }

    void setYear(int y) {
        year = y;
    }

    void print() {
        cout << day << " of " << MonthNames[month] << ", " << year << endl;
    }

private:
    int day;
    int month;
    int year;
};

bool before(Date &d1, Date &d2);

int main() {
    Date today;
    Date lecture11(6, 8, 2008);
    today.setMonth(August);
    today.setDay(7);
    today.setYear(2008);
    today.print();
    lecture11.print();
    if (before(lecture11, today))
        cout << "lecture11 was before today" << endl;
    Date tomorrow(8, 8, 2008);
    if (before(tomorrow, today))
        cout << "tomorrow was before today" << endl;
    else
        cout << "tomorrow was not before today" << endl;
    return 0;
}

bool before(Date &d1, Date &d2) {
    if (d1.year < d2.year)
        return true;
    else if (d1.year == d2.year) {
        if (d1.month < d2.month)
            return true;
        else if (d1.month == d2.month) {
            if (d1.day < d2.day)
                return true;
        }
    }
    return false;
}