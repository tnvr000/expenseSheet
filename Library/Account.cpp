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
    static void createFile() {
        fstream f("Data/AccountFile.txt", ios::in | ios::out | ios::binary | ios::app);
        f.close();
    }
    /*
    * OpenFile() streams the "AccountFile.txt" file accessible by file attribute which is static, makes it available to every object of Account class
    */
    static void openFile() {
        countNoOfAccounts();
        file->open("Data/AccountFile.txt", ios::in | ios::out | ios::binary | ios::ate);
    }
    /*
    * closes the file and delete the allocated memory
    */
    static void closeFile() {
        file->close();
        delete file;
    }
    /*
    * count the no of users recored in the file for convinience
    */
    static void countNoOfAccounts () {
        Account tempAccount;
        fstream f("Data/AccountFile.txt", ios::in | ios::binary);
        f.seekp(0, ios::end);
        int fileSize = f.tellp();
        noOfAccounts = fileSize/(sizeof(AccountData));
        f.close();
    }
    static int isFileOpen() {
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
    void read();
    void read(int);
    void print();
    void printAll();
    void write();
    void write(int);
    int logIn(char*);
    int isAvailable();
    void reset();
    void setName(char*);
    void setPassword(char*);
    void setNoOfItems(int);
    void setSpent(float);
    void setIndex(int);
    char* getName();
    int getNoOfItems();
    int getNoOfAccounts();
    float getSpent();
};

fstream* Account::file = new fstream();
int Account::noOfAccounts = 0;
int Account::index = 0;
Account::Account () {
    ;
}
Account::Account (char name[], char password[], int noOfItems, float spent) {
    data.setName(name);
    data.setPassword(password);
    data.setNoOfItems(noOfItems);
    data.setSpent(spent);
    index = 0;
}
void Account::read() {
    file->read((char*)&data, sizeof(AccountData));
}
void Account::read(int index) {
    file->seekg(index * sizeof(AccountData));
    read();
}
void Account::print() {
    printf("%-30s %6.2f %11d", data.getName(), data.getSpent(), data.getNoOfItems());
}
void Account::printAll() {
    file->seekg(0, ios::beg);
    int currentAccountIndex = 0;
    while(currentAccountIndex++ < noOfAccounts) {
        read();
        printf("%5d : ", currentAccountIndex);
        print();
        printf("\n");
    }
}
void Account::write() {
    file->seekp(0, ios::end);
    file->write((char*)&data, sizeof(AccountData));
    noOfAccounts += 1;
}
void Account::write(int index) {
    file->seekp(index * sizeof(AccountData), ios::beg);
    file->write((char*)&data, sizeof(AccountData));
}
int Account::logIn(char password[]) {
    read(Account::index);
    if(strcmp(data.getPassword(), password) == 0) {
        return 1;
    } else {
        return 0;
    }
}
int Account::isAvailable() {
    file->seekg(0, ios::beg);
    AccountData tempData;
    int currentAccountIndex = 0;
    while(currentAccountIndex++ < noOfAccounts) {
        file->read((char*)&tempData, sizeof(AccountData));
        if(strcmp(tempData.getName(), data.getName()) == 0) {
            return 0;
        }
    }
    return 1;
}
void Account::reset() {
    data.reset();
}
void Account::setName(char name[]) {
    data.setName(name);
}
void Account::setPassword(char password[]) {
    data.setPassword(password);
}
void Account::setNoOfItems(int noOfItems) {
    data.setNoOfItems(noOfItems);
}
void Account::setSpent(float spent) {
    data.setSpent(spent);
}
void Account::setIndex(int index) {
    this->index = index;
}
char* Account::getName() {
    return data.getName();
}
int Account::getNoOfItems() {
    return data.getNoOfItems();
}
int Account::getNoOfAccounts() {
    return Account::noOfAccounts;
}
float Account::getSpent() {
    return data.getSpent();
}
