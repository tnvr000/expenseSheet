#ifndef __USER_H_INCLUDED__
#define __USER_H_INCLUDED__

// forward declared dependencies

// include dependencies
#include <string.h>
#include <vector>
#include "Item.h"

using namespace std;

class User {
    Item item;
    int noOfItems, index;
    float spent;
    fstream *file;
    char username[30];
    void open(string username);
    void countNoOfItems();
    void calculateSpent();

    public:
    ~User();
    User(string username);
    void reset();
    void open();
    void reload();
    void close();
    void logOut();
    bool isOpen();
    void newItem();
    void readItem();
    void readItemAt(int index);
    void writeItem();
    void writeItem(int index);
    Item deleteLastRecord();
    vector<int> getYears();
    void printItemsForAllYears();
    void printItemsForYear(int year);
    void printItemsForYearAndMonth(int years, int month);
    void printItemsBetweenDates(Date dateRangeStart, Date dateRangeEnd);
    static void createDataSource(string username);
    static void deleteDataSource(string username);
    static string getFilePath(string username);
    string getFilePath();
    string getName();
    int getNoOfItems();
    float getSpent();
};

#endif