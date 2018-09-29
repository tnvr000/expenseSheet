#include "Utility.cpp"

void AccountOperation(int userPosition) {
    int userMenuChoice;
    Account user;
    user.Read(userPosition - 1);
    while(1) {
        system("cls");
        printf("WELCOME %s! How can I help you?\n", user.GetName());
        AccountMenu();
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

void MainOperation() {
    int MainMenuChoice, logInStatus;
    do {
        system("cls");
        MainMenu();
        cin >> MainMenuChoice;
        switch (MainMenuChoice) {
        case 1:
            logInStatus = LogIn();
            if(logInStatus != 0) {
                AccountOperation(logInStatus);
            }
            break;
        case 2:
            system("cls");
            CreateAccount();
            getch();
            break;
        case 3:
            break;
        case 4:
            system("cls");
            ClosingLine();
            getch();
            break;
        default:
            printf("Invalid Option");
        }
    } while (MainMenuChoice != 4);
}