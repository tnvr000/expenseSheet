#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "Date.cpp"

class Item {
    Date date;
    char name[30], remark[20];
    static int index;
    float price;

    public:
    Item();
    Item(Date, char*, float, char*);
    Item(int, int, int, char*, float, char*);
    void askForItem();
    void printHeaders();
    void print();
    static void printUnderlines();
    static void printTotal(float spent);
    Date getDate();
    char* getName();
    float getPrice();
    char* getRemark();
};

int Item::index = 0;

Item :: Item() {
    ;
}
Item :: Item(Date date, char name[], float price, char remark[]) {
    this->date.setDate(date);
    strcpy(this->name, name);
    this->price = price;
    strcpy(this->remark, remark);
}

Item :: Item(int day, int month, int year, char name[], float price, char remark[]) {
    this->date.setDate(year, month, day);
    strcpy(this->name, name);
    this->price = price;
    strcpy(this->remark, remark);
}

void Item::printHeaders() {
    Item::index = 0;
    ios state(nullptr);
    state.copyfmt(cout);

    //common format
    cout.setf(ios::left);
    cout.fill(' ');

    //date
    cout.width(10);
    cout<<"Date";
    cout<<"|";

    //Name
    cout.width(30);
    cout<<"Name";
    cout<<"|";

    //price
    cout.width(9);
    cout<<"Price";
    cout<<"|";

    //Remark
    cout.width(20);
    cout<<"remark";
    cout<<"|";

    
    cout.fill('-');
    cout<<"\n";
    cout.copyfmt(state);
    
    Item::printUnderlines();
}

void Item::printUnderlines() {
    ios state(nullptr);
    state.copyfmt(cout);

    cout.fill('-');
    //Date underline
    cout.width(10);
    cout<<"";
    cout<<"+";

    // Name underline
    cout.width(30);
    cout<<"";
    cout<<"+";

    // Price Underline
    cout.width(9);
    cout<<"";
    cout<<"+";

    // Remark underline
    cout.width(20);
    cout<<"";
    cout<<"+";

    cout.copyfmt(state);
}

void Item :: print() {
    char fillingChar[2] = {' ', '-'};
    date.printDate();
    cout<<"|";
    
    ios state(nullptr);
    state.copyfmt(cout);

    //common settings
    cout.setf(ios::fixed);
    cout.precision(2);
    cout.fill(fillingChar[(Item::index)%2]);

    // Name
    cout.width(30);
    cout.setf(ios::left);
    cout<<this->name;
    cout<<"|";


    // Price
    cout.width(9);
    cout.unsetf(ios::left);
    cout.setf(ios::right);
    cout<<this->price<<"|";

    // Remarks
    cout.width(20);
    cout.unsetf(ios::right);
    cout.setf(ios::left);
    cout<<this->remark;
    cout<<"|";
    
    cout.copyfmt(state);
    Item::index++;
}

void Item::printTotal(float spent) {
    Item::printUnderlines();
    cout<<"\n";
    ios state(nullptr);
    state.copyfmt(cout);

    cout.fill(' ');

    // cover remaining
    cout.width(10);
    cout<<"";
    cout<<"|";

    // Total
    cout.width(30);
    cout.setf(ios::right);
    cout<<"Total";
    cout<<"|";

    // Spent
    cout.width(9);
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<spent;
    cout<<"|";

    // cover remaining
    cout.width(20);
    cout<<"";
    cout<<"|\n";

    cout.copyfmt(state);

    Item::printUnderlines();
}

void Item :: askForItem() {
    date.askForDate();
    printf("Enter name of Item : ");
    fflush(stdin);
    gets(name);
    
    printf("Enter prie of item : ");
    fflush(stdin);
    scanf("%f", &price);

    printf("Enter remark of item : ");
    fflush(stdin);
    gets(remark);
}

Date Item::getDate() {
    return date.getDate();
}

char* Item :: getName() {
    return name;
}

float Item :: getPrice() {
    return price;
}

char* Item :: getRemark() {
    return remark;
}
