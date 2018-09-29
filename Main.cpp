#include "Library/Operations.cpp"

int main()
{
    int MainMenuChoice;
    system("cls");
    Introduction();
    getch();
    Account::CreateFile();
    Account::OpenFile();
    MainOperation();
    Account::CloseFile();
}