#include "Library/Operations.cpp"

using namespace std;

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