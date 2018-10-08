#include "Utility.cpp"

void accountOperation(int userPosition) {
    int userMenuChoice;
    Account user;
    user.read(userPosition - 1);
    while(1) {
        system("cls");
        printf("WELCOME %s! How can I help you?\n", user.getName());
        accountMenu();
        fflush(stdin);
        scanf("%d", &userMenuChoice);
        switch(userMenuChoice) {
        case 1  : 
            //to dislay menu
            break;
        case 2  :
            //to add item
            break;
        case 3  :
            //to delete last entry
            break;
        case 4  :
            printf("\nLOGGED OUT SUCCESSFULLY.");
            getch();
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