#include "Library/Operations.cpp"

int main()
{
    int MainMenuChoice;
    system("cls");
    introduction();
    getch();
    Account::createFile();
    Account::openFile();
    mainOperation();
    Account::closeFile();
}