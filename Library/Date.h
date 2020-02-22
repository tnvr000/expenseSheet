#ifndef __DATE_H_INCLUDED__
#define __DATE_H_INCLUDED__

// forward declared dependencies

// incldued dependencies

using namespace std;

class Date {
    private:
    int day, month, year;

    public:
    Date();
    Date(int year);
    Date(int year, int month);
    Date(int year, int month, int day);
    void askForDate();
    void printDate();
    void validateDate();
    bool is31DayMonth();
    bool is30DayMonth();
    bool isLeapYear();
    void setDate(int year, int month, int day);
    void setDate(Date);
    int getDay();
    int getMonth();
    int getYear();
    Date getDate();
    Date getBeginingOfMonth();
    Date getBeginingOfYear();
    Date getEndOfMonth();
    Date getEndOfYear();
    int getLastDayOfMonth();
    int operator==(Date otherDate);
    int operator!=(Date othreDate);
    int operator>(Date otherDate);
    int operator<(Date otherDate);
    int operator>=(Date otherDate);
    int operator<=(Date otherDate);
};

#endif