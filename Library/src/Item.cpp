#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

#include "../Date.h"
#include "../Item.h"

using namespace std;

int Item::index = 0;

// contructors
Item::Item() { ; }
Item::Item(Date date, string name, float price, string remark) {
    this->date.setDate(date);
    strcpy(this->name, name.c_str());
    this->price = price;
    strcpy(this->remark, remark.c_str());
}
Item::Item(int year, int month, int day, string name, float price, string remark) {
    this->date.setDate(year, month, day);
    strcpy(this->name, name.c_str());
    this->price = price;
    strcpy(this->remark, remark.c_str());
}

/* promts for input item details via console
 */
void Item::askForItem() {
    this->date.askForDate();
    printf("Enter name of Item : ");
    fflush(stdin);
    gets(this->name);
    
    printf("Enter prie of item : ");
    fflush(stdin);
    scanf("%f", &this->price);

    printf("Enter remark of item : ");
    fflush(stdin);
    gets(this->remark);
}

/* prints headers for displaying item list
 */
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

/* prints underlines that aligns with the headers
 */
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

/* prints items details in a format
 */
void Item::print() {
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
    cout<<this->price;
    cout<<"|";

    // Remarks
    cout.width(20);
    cout.unsetf(ios::right);
    cout.setf(ios::left);
    cout<<this->remark;
    cout<<"|";
    
    cout.copyfmt(state);
    Item::index++;
}

/* ptints provided spent amount in a format
 */
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

// getters
Date Item::getDate() {
    return this->date.getDate();
}
string Item::getName() {
    return this->name;
}
float Item::getPrice() {
    return this->price;
}
string Item::getRemark() {
    return this->remark;
}