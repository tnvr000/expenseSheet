#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <string>

#include "Menu.cpp"
#include "Date.cpp"
#include "Account.cpp"

void listUsers() {
    Account user;
    int noOfAccounts = user.getNoOfAccounts();
    printf("INDEX   NAME                           SPENT    NO OF ITEMS\n");
    printf("----- x ------------------------------x------x-----------\n");
    user.printAll();
    printf("%5d : BACK TO MAIN MENU\n", noOfAccounts + 1);
    printf("CHOOSE AN OPTION : ");
}

void createAccount() {
    Account user;
    char name[30], password[15], check[15], choice;
    while(1) {
        system("cls");
        printf("Enter your name : ");
        fflush(stdin);
        gets(name);
        user.setName(name);
        if(user.isAvailable() == 0) {
            printf("THIS USERNAME ALREADY TAKEN. DO WANT TRY ANOTHER ONE (Yes/No) ? : ");
            fflush(stdin);
            scanf("%c", &choice);
            if(choice == 'n' || choice == 'N') {
                printf("\nACCOUNT NOT CREATED!\n");
                return;
            }
        } else {
            break;
        }
    }
    while(1) {
        system("cls");
        printf("USERNAME : %s\n", name);
        printf("CHOOSE PASSWORD : ");
        fflush(stdin);
        gets(password);
        printf("CONFIRM PASSWORD : ");
        fflush(stdin);
        gets(check);
        if(strcmp(password, check) != 0) {
            printf("\nPASSWORD NOT MATCHCING. DO YOU WANT TO TRY AGAIN (Yes/No)? : ");
            fflush(stdin);
            scanf("%c", &choice);
            if(choice == 'n' || choice == 'N') {
                printf("\nACCOUNT NOT CREATED.\n");
                return;
            }
        } else {
            break;
        }

    }
    user.setName(name);
    user.setPassword(password);
    user.setNoOfItems(0);
    user.setSpent(0);
    user.write();
    printf("\nACCOUNT CREATED SUCCESSFULLY!\n");
}

int logIn() {
    char password[16], retryChoice;
    int isLoggedIn = 0, noOfAccounts, position;
    Account user;
    noOfAccounts = user.getNoOfAccounts();
    while(1) {
        system("cls");
        listUsers();
        fflush(stdin);
        scanf("%d", &position);
        if(position > noOfAccounts) {
            return 0;
        }
        user.setIndex(position - 1);
        printf("ENTER PASSWORD : ");
        fflush(stdin);
        gets(password);
        if(user.authenticate(password) == 1) {
            printf("Log in Successful\n");
            getch();
            return position;
        } else {
            printf("INCORRECT PASSWORD. DO YOU WANT TO TRY AGAIN (Yes/No) ? : ");
            fflush(stdin);
            scanf("%c", &retryChoice);
            if(retryChoice == 'N' || retryChoice == 'n') {
                return 0;
            }
        }
    }
    getch();
}

void deleteAccount() {
    char password[16], retryChoice;
    Account user;
    int position, noOfAccounts = user.getNoOfAccounts();
    while(1) {
        system("cls");
        listUsers();
        fflush(stdin);
        scanf("%d", &position);

        if (position > noOfAccounts) {
            return;
        }

        user.setIndex(position - 1);
        printf("ENTER PASSWORD : ");
        fflush(stdin);
        gets(password);

        if (user.authenticate(password)) {
            user.erase();
            return;
            //TO DO delete the user
        } else {
            printf("INCORRECT PASSWORD. DO YOU WANT TO TRY AGAIN (Yes/No) ? : ");
            fflush(stdin);
            scanf("%c", &retryChoice);
            if(retryChoice == 'N' || retryChoice == 'n') {
                return;
            }
        }
    }
}