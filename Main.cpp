#include "Library/Operations.cpp"

int main()
{
    User::createDataSource("tahir");
    int MainMenuChoice;
    system("cls");
    introduction();
    getch();
    Account::createFile();
    Account::openFile();
    mainOperation();
    Account::closeFile();
}