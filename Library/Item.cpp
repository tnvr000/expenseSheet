#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "Date.cpp"

class Item {
    Date date;
    char name[30], remark[20];
    float price;
public:
    Item();
    Item(Date, char*, float, char*);
    Item(int, int, int, char*, float, char*);
    void askForItem();
    void print();
    Date getDate();
    char* getName();
    float getPrice();
    char* getRemark();
};

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
    this->date.setDate(day, month, year);
    strcpy(this->name, name);
    this->price = price;
    strcpy(this->remark, remark);
}

void Item :: print() {
    date.printDate();
    printf(" %-30s %6.2f %-20s", name, price, remark);
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
