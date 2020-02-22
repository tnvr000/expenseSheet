#include <stdio.h>
#include <conio.h>
#include <iostream>

#include "../Date.h"

using namespace std;

// constructors
Date::Date() {
    this->day = this->month = this->year = 0;
}

Date::Date(int year) {
    this->year = year;
    this->month = this->day = 0;
}

Date::Date(int year, int month) {
    this->year = year;
    this->month = month;
    this-> day = 0;
}

Date::Date(int year, int month, int day) {
    this->day = day;
    this->month = month;
    this->year = year;
    this->validateDate();
}

/* promt for input date via console
 */
void Date::askForDate() {
    char temp;
    printf("Enter the date (dd/mm/yyyy) : ");
    fflush(stdin);
    scanf("%d%c%d%c%d", &day, &temp, &month, &temp, &year);
    this->validateDate();
}

/* print the data to comsoole in format dd/mm/yyyy
 */
void Date::printDate() {
    printf("%02d/%02d/%d", day, month, year);
}

/* checks if the date is valid, and make it valid if it is not.
 * for example:
 * 20/13/1999 becomes 20/1/1669
 * 32/1/1999 becomes 1/1/1999
 */
void Date::validateDate() {
    if(this->month > 12) {
        this->month %= 12;
    }
    if(this->day > this->getLastDayOfMonth()) {
        this->day %= this->getLastDayOfMonth();
    }
}

/* checks if the current month have 31 days
 */
bool Date::is31DayMonth() {
    bool flag = false;
    switch(this->month) {
        case  1 : ;
        case  3 : ;
        case  5 : ;
        case  7 : ;
        case  8 : ;
        case 10 : ;
        case 12 : flag = true;
    }
    return flag;
}

/* checks if the current month have 30 days
 */
bool Date::is30DayMonth() {
    bool flag = false;
    switch(this->month) {
        case  4 : ;
        case  6 : ;
        case  9 : ;
        case 11 : flag = true;
    }
    return flag;
}

/* checks if the current year is leap year
 */
bool Date::isLeapYear() {
    return (this->year % 4 == 0);
}

// setter methods
void Date::setDate(int year, int month, int day) {
    this->day = day;
    this->month = month;
    this->year = year;
    this->validateDate();
}
void Date::setDate(Date date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
    this->validateDate();
}

// getter methods
int Date::getDay() {
    return this->day;
}
int Date::getMonth() {
    return this->month;
}
int Date::getYear() {
    return this->year;
}
Date Date::getDate() {
    Date date(this->year, this->month, this->day);
    return date;
}
Date Date::getBeginingOfMonth() {
    return Date(this->year, this->month, 1);
}
Date Date::getBeginingOfYear() {
    return Date(this->year, 1, 1);
}
Date Date::getEndOfMonth() {
    return Date(this->year, this->month, this->getLastDayOfMonth());
}
Date Date::getEndOfYear() {
    return Date(this->year, 12, 31);
}
int Date::getLastDayOfMonth() {
    int day;
    if(this->is31DayMonth()) {
        day = 31;
    } else if(this->is30DayMonth()) {
        day = 30;
    } else { // this is febuary month
        day = this->isLeapYear() ? 29 : 28;
    }
    return day;
}

// overloaded operators
int Date::operator==(Date otherDate) {
    if (this->year == otherDate.year && this->month == otherDate.month && this->day == otherDate.day) {
        return 1;
    } else {
        return 0;
    }
}
int Date::operator!=(Date otherDate) {
    if (*this == otherDate) {
        return 0;
    } else {
        return 1;
    }
}
int Date::operator>(Date otherDate) {
    if (this->year > otherDate.year) {
        return 1;
    } else if (this->year < otherDate.year) {
        return 0;
    }

    if (this->month > otherDate.month) {
        return 1;
    } else if (this->month < otherDate.month) {
        return 0;
    }

    if (this->day > otherDate.day) {
        return 1;
    }
    return 0;
}
int Date::operator<(Date otherDate) {
    if (this->year < otherDate.year) {
        return 1;
    } else if (this->year > otherDate.year) {
        return 0;
    }

    if (this->month < otherDate.month) {
        return 1;
    } else if (this->month > otherDate.month) {
        return 0;
    }

    if (this->day < otherDate.day) {
        return 1;
    }
    return 0;
}
int Date::operator>=(Date otherDate) {
    if (*this < otherDate) {
        return 0;
    } else {
        return 1;
    }
}
int Date::operator<=(Date otherDate) {
    if (*this > otherDate) {
        return 0;
    } else {
        return 1;
    }
}