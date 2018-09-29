#include <string.h>
#include "AccountData.cpp"
class Account
{
    AccountData data;
    static int noOfAccounts, index;
    static fstream* file;
public:
    Account ();
    Account (char*, char*, int, float);
    /**
    * a file, if doesn't exist, will not be opened unless it is opened in "out"  and "append" mode
    * but opening a file in append mean the get and put pointers can't to changed by seekg() and seekp()
    */
    static void CreateFile() {
        fstream f("Data/AccountFile.txt", ios::in | ios::out | ios::binary | ios::app);
        f.close();
    }
    /*
    * OpenFile() streams the "AccountFile.txt" file accessible by file attribute which is static, makes it available to every object of Account class
    */
    static void OpenFile() {
        CountNoOfAccounts();
        file->open("Data/AccountFile.txt", ios::in | ios::out | ios::binary | ios::ate);
    }
    /*
    * closes the file and delete the allocated memory
    */
    static void CloseFile() {
        file->close();
        delete file;
    }
    /*
    * count the no of users recored in the file for convinience
    */
    static void CountNoOfAccounts () {
        Account tempAccount;
        fstream f("Data/AccountFile.txt", ios::in | ios::binary);
        f.seekp(0, ios::end);
        int fileSize = f.tellp();
        noOfAccounts = fileSize/(sizeof(AccountData));
        f.close();
    }
    static int IsFileOpen() {
        int flag = 0;
        if(*file) {
            printf("File is open\n");
            flag = 1;
        } else {
            printf("File is not open\n");
        }
        getch();
        return flag;
    }
    void Read();
    void Read(int);
    void Print();
    void PrintAll();
    void Write();
    void Write(int);
    int LogIn(char*);
    int IsAvailable();
    void Reset();
    void SetName(char*);
    void SetPassword(char*);
    void SetNoOfItems(int);
    void SetSpent(float);
    void SetIndex(int);
    char* GetName();
    int GetNoOfItems();
    int GetNoOfAccounts();
    float GetSpent();
};

fstream* Account::file = new fstream();
int Account::noOfAccounts = 0;
int Account::index = 0;
Account::Account () {
    ;
}
Account::Account (char name[], char password[], int noOfItems, float spent) {
    data.SetName(name);
    data.SetPassword(password);
    data.SetNoOfItems(noOfItems);
    data.SetSpent(spent);
    index = 0;
}
void Account::Read() {
    file->read((char*)&data, sizeof(AccountData));
}
void Account::Read(int index) {
    file->seekg(index * sizeof(AccountData));
    Read();
}
void Account::Print() {
    printf("%-30s %6.2f %11d", data.GetName(), data.GetSpent(), data.GetNoOfItems());
}
void Account::PrintAll() {
    file->seekg(0, ios::beg);
    int currentAccountIndex = 0;
    while(currentAccountIndex++ < noOfAccounts) {
        Read();
        printf("%5d : ", currentAccountIndex);
        Print();
        printf("\n");
    }
}
void Account::Write() {
    file->seekp(0, ios::end);
    file->write((char*)&data, sizeof(AccountData));
    noOfAccounts += 1;
}
void Account::Write(int index) {
    file->seekp(index * sizeof(AccountData), ios::beg);
    file->write((char*)&data, sizeof(AccountData));
}
int Account::LogIn(char password[]) {
    Read(Account::index);
    if(strcmp(data.GetPassword(), password) == 0) {
        return 1;
    } else {
        return 0;
    }
}
int Account::IsAvailable() {
    file->seekg(0, ios::beg);
    AccountData tempData;
    int currentAccountIndex = 0;
    while(currentAccountIndex++ < noOfAccounts) {
        file->read((char*)&tempData, sizeof(AccountData));
        if(strcmp(tempData.GetName(), data.GetName()) == 0) {
            return 0;
        }
    }
    return 1;
}
void Account::Reset() {
    data.Reset();
}
void Account::SetName(char name[]) {
    data.SetName(name);
}
void Account::SetPassword(char password[]) {
    data.SetPassword(password);
}
void Account::SetNoOfItems(int noOfItems) {
    data.SetNoOfItems(noOfItems);
}
void Account::SetSpent(float spent) {
    data.SetSpent(spent);
}
void Account::SetIndex(int index) {
    this->index = index;
}
char* Account::GetName() {
    return data.GetName();
}
int Account::GetNoOfItems() {
    return data.GetNoOfItems();
}
int Account::GetNoOfAccounts() {
    return Account::noOfAccounts;
}
float Account::GetSpent() {
    return data.GetSpent();
}
