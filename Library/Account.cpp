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

    // a file, if doesn't exist, will not be opened unless it is opened in "out"  and "append" mode
    // but opening a file in append mean the get and put pointers can't to changed by seekg() and seekp()
    static void createFile() {
        fstream f("Data/AccountFile.txt", ios::in | ios::out | ios::binary | ios::app);
        f.close();
    }
    
    // OpenFile() streams the "AccountFile.txt" file accessible by file attribute which is static,
    // makes it available to every object of Account class
    static void openFile() {
        countNoOfAccounts();
        file->open("Data/AccountFile.txt", ios::in | ios::out | ios::binary | ios::ate);
    }

    // closes the file and delete the allocated memory
    static void closeFile() {
        file->close();
        delete file;
    }

    // count the no of users recored in the file for convinience
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
    void readNext();
    void readAtIndex(int);
    void print();
    void printAll();
    void write();
    void write(int);
    void erase();
    int authenticate(char*);
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

// reads the account details from AccountFile.txt from current cursor position
// Generally called immediatly 
void Account::readNext() {
    file->read((char*)&data, sizeof(AccountData));
}

// reads the account details from AccountFile.txt from specified user index
// cursor position is calculated by multiply index to size of AccountData
void Account::readAtIndex(int index) {
    file->seekg(index * sizeof(AccountData));
    readNext();
}

// prints the AccountData->data on the screen
void Account::print() {
    printf("%-30s %6.2f %11d", data.getName(), data.getSpent(), data.getNoOfItems());
}

// prints all account details in AccountFile.txt prefixed with thier position
void Account::printAll() {
    file->seekg(0, ios::beg);
    int currentAccountIndex = 0;
    while(currentAccountIndex++ < noOfAccounts) {
        readNext();
        printf("%5d : ", currentAccountIndex);
        print();
        printf("\n");
    }
}

// Appends the AccountData->data to the AccountFile.txt
// Used for adding new user
void Account::write() {
    file->seekp(0, ios::end);
    file->write((char*)&data, sizeof(AccountData));
    noOfAccounts += 1;
}

// Overwrites the account details in AccountFile.txt
// of specified index with AccountData->data 
void Account::write(int index) {
    file->seekp(index * sizeof(AccountData), ios::beg);
    file->write((char*)&data, sizeof(AccountData));
}

// creates a tempAccountFile.txt and copy-paste every AccountData
// except current user (the (Account->index)+1) user)
// then closes both files, removes original AccountFile.txt,
// renames tempAccountFile.txt to AccountFile.txt and reopens the file 
void Account::erase() {
    fstream tempFile("Data/tempAccountFile.txt", ios::out | ios::binary | ios::app);
    AccountData tempData;
    file->seekg(0, ios::beg);
    for (int i = 0; i < noOfAccounts; ++i) {
        file->read((char*)&tempData, sizeof(AccountData));
        if (i != index) {
            tempFile.write((char*)&tempData, sizeof(AccountData));
        }
    }
    tempFile.close();
    file->close();
    remove ("Data/AccountFile.txt");
    rename ("Data/tempAccountFile.txt", "Data/AccountFile.txt");
    openFile();
    printf("ACCOUNT DELETED");
}

//Authenticate the password
//if correct, returns 1
//if not, return 0
int Account::authenticate(char password[]) {
    readAtIndex(Account::index);
    if(strcmp(data.getPassword(), password) == 0) {
        return 1;
    } else {
        return 0;
    }
}

//Check if Account->data.name is avialbel for an new user or not
//return 1 if available
//else returns 0
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

//sets the AccountData->data.spent and AccountData->data.noOfItems to 0
void Account::reset() {
    data.reset();
}

//setter methods
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

//getter methods
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
