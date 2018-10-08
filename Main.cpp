#include "Library/Operations.cpp"

int main()
{
    int MainMenuChoice;
    system("cls");
    introduction();
    getch();
    Account::CreateFile();
    Account::OpenFile();
    mainOperation();
    Account::CloseFile();
}