#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <string>

#include "Menu.cpp"
#include "Date.cpp"
#include "User.cpp"
#include "Files.cpp"

void CreateAccount()
{
    Account user;
    char name[30], password[15], check[15], choice;
    while(1) {
        system("cls");
        printf("Enter your name : ");
        fflush(stdin);
        gets(name);
        user.SetName(name);
        if(user.IsAvailable() == 0) {
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
    user.SetName(name);
    user.SetPassword(password);
    user.SetNoOfItems(0);
    user.SetSpent(0);
    user.Write();
    printf("\nACCOUNT CREATED SUCCESSFULLY!\n");
}
