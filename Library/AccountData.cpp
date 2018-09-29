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
    void PrintAccount();
    void Reset();
    int IsAvailable();
    void SetName(char*);
    void SetPassword(char*);
    void SetNoOfItems(int);
    void SetSpent(float);
    char* GetName();
    char* GetPassword();
    float GetSpent();
    int GetNoOfItems();
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

void AccountData::PrintAccount() {
    printf("%-20s %6.2f %-15d\n", name, spent, noOfItems);
}
void AccountData::SetName(char name[]) {
    strcpy(this->name, name);
}
void AccountData::SetPassword(char password[]) {
    strcpy(this->password, password);
}
void AccountData::SetNoOfItems(int noOfItems) {
    this->noOfItems = noOfItems;
}
void AccountData::SetSpent(float spent) {
    this->spent = spent;
}
char* AccountData::GetName() {
    return name;
}
char* AccountData::GetPassword() {
    return password;
}
int AccountData::GetNoOfItems() {
    return noOfItems;
}
float AccountData::GetSpent() {
    return spent;
}
void AccountData::Reset() {
    spent = noOfItems = 0;
}