#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <string.h>

#include "../accountData.h"

using namespace std;

// contructors
AccountData::AccountData() {
    strcpy(name, "");
    strcpy(password, "");
    this->spent = 0;
    this->noOfItems = 0;
}
AccountData::AccountData(string name, string password, float spent, int noOfItems) {
    strcpy(this->name, name.c_str());
    strcpy(this->password, password.c_str());
    this->spent = spent;
    this->noOfItems = noOfItems;
}

/* prints account details in a format
 */
void AccountData::printAccount() {
    printf("%-20s %6.2f %-15d\n", this->name, this->spent, this->noOfItems);
}

/* resets noOfItems and spent to 0 in the object
 */
void AccountData::reset() {
    this->spent = this->noOfItems = 0;
}

// setter methods
void AccountData::setName(string name) {
    strcpy(this->name, name.c_str());
}
void AccountData::setPassword(string password) {
    strcpy(this->password, password.c_str());
}
void AccountData::setNoOfItems(int noOfItems) {
    this->noOfItems = noOfItems;
}
void AccountData::setSpent(float spent) {
    this->spent = spent;
}

// getter methods
string AccountData::getName() {
    return this->name;
}
string AccountData::getPassword() {
    return this->password;
}
int AccountData::getNoOfItems() {
    return this->noOfItems;
}
float AccountData::getSpent() {
    return this->spent;
}