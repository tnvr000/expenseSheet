#include <stdio.h>
#include <vector>

#include "../Menu.h"

using namespace std;

void introduction() {
    printf("\n\n\n\n\n\t\t\t");
    printf("THE EXPENSE SHEET\n\t\t\tBY TANVEER\n");
}

void mainMenu() {
    printf(" 1 : LOG INTO AN ACCOUNT\n");
    printf(" 2 : CREATE A NEW ACCOUNT\n");
    printf(" 3 : DELETE AN ACCOUNT\n");
    printf(" 4 : CLOSE APPLICATION\n");
    printf("\n ENTER YOUR CHOICE : ");
}

void accountMenu() {
    printf(" 1 : DISPLAY ALL ENTRIES\n");
    printf(" 2 : MAKE A NEW ENTRY\n");
    printf(" 3 : DELETE LAST ENTRY\n");
    printf(" 4 : LOG OUT\n");
    printf("\n ENTER YOUR CHOICE : ");
}

void displayMonths() {
    printf("1  : January\n");
    printf("2  : Febuary\n");
    printf("3  : March\n");
    printf("4  : April\n");
    printf("5  : May\n");
    printf("6  : June\n");
    printf("7  : July\n");
    printf("8  : August\n");
    printf("9  : Setember\n");
    printf("10 : October\n");
    printf("11 : November\n");
    printf("12 : December\n");
}

void closingLine() {
    printf("\n\n\n\t\t\tTHANK YOU");
}
