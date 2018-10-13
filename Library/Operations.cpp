#include "Utility.cpp"

void accountOperation(int userPosition) {
    int userMenuChoice;
    Account user;
    user.setIndex(userPosition - 1);
    user.readAtIndex(userPosition - 1);

    User manager(user.getName());
    while(1) {
        system("cls");
        printf("WELCOME %s! How can I help you?\n", user.getName());
        accountMenu();
        fflush(stdin);
        scanf("%d", &userMenuChoice);
        switch(userMenuChoice) {
        case 1  : 
            //TODO dislay menu
            break;
        case 2  :
            //TODO add item
            break;
        case 3  :
            //TODO delete last entry
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