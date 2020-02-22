#ifndef __ITEM_H_INCLUDED__
#define __ITEM_H_INCLUDED__

// forward declared dependencies

// include dependencies
#include <string.h>
#include "Date.h"

using namespace std;

class Item {
    Date date;
    char name[30], remark[20];
    static int index;
    float price;

    public:
    Item();
    Item(Date date, string name, float price, string remark);
    Item(int year, int month, int day, string name, float price, string remark);
    void askForItem();
    void printHeaders();
    void print();
    static void printUnderlines();
    static void printTotal(float spent);
    Date getDate();
    string getName();
    float getPrice();
    string getRemark();
};

#endif