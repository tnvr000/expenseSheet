#include <iostream>

#include "Utility.cpp"

using namespace std;

void accountOperation(int userPosition) {
    int userMenuChoice;
    
    Account userDetails;
    userDetails.setIndex(userPosition - 1);
    userDetails.read();

    User user(userDetails.getAccountData()->getName());
    user.open();
    while(1) {
        system("cls");
        printf("WELCOME %s! How can I help you?\n", userDetails.getAccountData()->getName());
        accountMenu();
        fflush(stdin);
        scanf("%d", &userMenuChoice);
        switch(userMenuChoice) {
        case 1  : 
            displayMenu(&user);
            break;
        case 2  :
            addItem(&user);
            updateAccountDetails(&userDetails, &user);
            getch();
            break;
        case 3  :
            deleteItem(&user);
            updateAccountDetails(&userDetails, &user);
            getch();
            break;
        case 4  :
            // The destrutor will cleanup the object and memory
            user.logOut();
            printf("\nLOGGED OUT SUCCESSFULLY.");
            return;
        default :
            printf("\nINVALID CHOICE! TRY AGAIN.");
            getch();
        }
    }

}

void mainOperation() {
    int mainMenuChoice, logInStatus;
    do {
        system("cls");
        mainMenu();
        cin >> mainMenuChoice;
        switch (mainMenuChoice) {
        case 1:
            logInStatus = logIn();
            if(logInStatus != 0) {
                accountOperation(logInStatus);
            }
            break;
        case 2:
            system("cls");
            createAccount();
            getch();
            break;
        case 3:
            system("cls");
            deleteAccount();
            getch();
            break;
        case 4:
            system("cls");
            closingLine();
            getch();
            break;
        default:
            printf("Invalid Option");
        }
    } while (mainMenuChoice != 4);
}