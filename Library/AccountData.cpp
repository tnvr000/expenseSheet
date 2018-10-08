#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <string.h>

using namespace std;
class AccountData {
private:
    char name[30], password[15];
    int noOfItems;
    float spent;
public:
    AccountData();
    AccountData(char*, char*, float, int);
    void printAccount();
    void reset();
    int isAvailable();
    void setName(char*);
    void setPassword(char*);
    void setNoOfItems(int);
    void setSpent(float);
    char* getName();
    char* getPassword();
    float getSpent();
    int getNoOfItems();
};

AccountData::AccountData() {
    strcpy(name, "");
    strcpy(password, "");
    spent = 0;
    noOfItems = 0;
}
AccountData::AccountData(char name[], char password[], float spent, int noOfItems) {
    strcpy(this->name, name);
    strcpy(this->password, password);
    this->spent = spent;
    this->noOfItems = noOfItems;
}

void AccountData::printAccount() {
    printf("%-20s %6.2f %-15d\n", name, spent, noOfItems);
}
void AccountData::setName(char name[]) {
    strcpy(this->name, name);
}
void AccountData::setPassword(char password[]) {
    strcpy(this->password, password);
}
void AccountData::setNoOfItems(int noOfItems) {
    this->noOfItems = noOfItems;
}
void AccountData::setSpent(float spent) {
    this->spent = spent;
}
char* AccountData::getName() {
    return name;
}
char* AccountData::getPassword() {
    return password;
}
int AccountData::getNoOfItems() {
    return noOfItems;
}
float AccountData::getSpent() {
    return spent;
}
void AccountData::reset() {
    spent = noOfItems = 0;
}