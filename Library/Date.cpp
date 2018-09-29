#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

class Date
{
private:
    int Day, Month, Year;
public:
    Date(){;}
    Date(int, int, int);
    int GetDay();
    int GetMonth();
    int GetYear();
    void ValidateDate();
    void ReadDate();
    void PrintDate();
};

Date :: Date(int Day, int Month, int Year)
{
    this->Day = Day;
    this->Month = Month;
    this->Year = Year;
}

int Date :: GetDay()
{
    return Day;
}

int Date :: GetMonth()
{
    return Month;
}

int Date :: GetYear()
{
    return Year;
}

void Date ::ValidateDate()
{
    if(Month > 12)
        Month = Month % 12;
    if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
    {
        if(Day > 31)
            Day %= 31;
    }
    else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
    {
        if(Day > 30)
        Day %= 30;
    }
    else if (Month == 4)
    {
        if (Year / 4 == 0 && Day > 29)
        {
            Day %= 29;
        }
        else if (Day > 28)
        {
            Day %= 28;
        }
    }
}

void Date ::ReadDate()
{
    char temp;
    printf("Enter the date (dd/mm/yyyy) : ");
    scanf("%d%c%d%c%d", &Day, &temp, &Month, &temp, &Year);
    ValidateDate();
}

void Date ::PrintDate()
{
    printf("%02d/%02d/%d", Day, Month, Year);
}
