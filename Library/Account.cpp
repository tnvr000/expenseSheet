#include <string.h>
#include "AccountData.cpp"
class Account { 
    AccountData data;
    static int noOfAccounts, index;
    static fstream* file;
    public:
    Account ();
    Account (string name, string password, int noOfItems, float spent);

    static void createFile();
    static void openFile();
    static void closeFile();
    static void countNoOfAccounts ();
    static bool isFileOpen();
    
    void readNext();
    void readAtIndex(int index);
    void read();
    void print();
    void printAll();
    void write();
    void write(int index);
    void save();
    void erase();
    bool authenticate(string password);
    bool isAvailable();
    void reset();
    void setIndex(int index);
    int getNoOfAccounts();
    AccountData* getAccountData();
};

fstream* Account::file = new fstream();
int Account::noOfAccounts = 0;
int Account::index = 0;

// constructors
Account::Account () { ; }
Account::Account (string name, string password, int noOfItems, float spent) {
    this->data.setName(name);
    this->data.setPassword(password);
    this->data.setNoOfItems(noOfItems);
    this->data.setSpent(spent);
    Account::index = 0;
}

/* a file, if doesn't exist, will not be opened unless it is opened in "out"  and "append" mode
 * but opening a file in append mean the get and put pointers can't to changed by seekg() and seekp()
 */
void Account :: createFile() {
    fstream f("Data/AccountFile.txt", ios::in | ios::out | ios::binary | ios::app);
    f.close();
}

/* OpenFile() streams the "AccountFile.txt" file accessible by file attribute which is static,
 * makes it available to every object of Account class
 */
void Account :: openFile() {
    Account::countNoOfAccounts();
    Account::file->open("Data/AccountFile.txt", ios::in | ios::out | ios::binary | ios::ate);
}

/* closes the file and delete the allocated memory
 */
void Account :: closeFile() {
    Account::file->close();
    delete Account::file;
}

/* count the no of users recored in the file for convinience
 */
void Account :: countNoOfAccounts () {
    Account tempAccount;
    fstream f("Data/AccountFile.txt", ios::in | ios::binary);
    f.seekp(0, ios::end);
    int fileSize = f.tellp();
    Account::noOfAccounts = fileSize/(sizeof(AccountData));
    f.close();
}

/* checks if the AccountFile.txt is open or not
 */
bool Account :: isFileOpen() {
    bool flag = false;
    if(*Account::file) {
        flag = true;
    }
    return flag;
}


/*  reads the account details from AccountFile.txt from current cursor position
 * Generally called immediatly
 */ 
void Account::readNext() {
    Account::file->read((char*)&data, sizeof(AccountData));
}

/* reads the account details from AccountFile.txt from specified user index
 * cursor position is calculated by multiply index to size of AccountData
 */
void Account::readAtIndex(int index) {
    Account::file->seekg(index * sizeof(AccountData));
    this->readNext();
}

/* reads the account details from AccountFile.txt at index Account->index
 */
void Account::read() {
    Account::file->seekp(Account::index * sizeof(AccountData));
    this->readNext();
}

/* prints the AccountData->data on the screen
 */
void Account::print() {
    printf("%-30s %6.2f %11d", data.getName().c_str(), data.getSpent(), data.getNoOfItems());
}

/* prints all account details in AccountFile.txt prefixed with thier position
 */
void Account::printAll() {
    Account::file->seekg(0, ios::beg);
    int currentAccountIndex = 0;
    while(currentAccountIndex++ < Account::noOfAccounts) {
        this->readNext();
        printf("%5d : ", currentAccountIndex);
        this->print();
        printf("\n");
    }
}

/* Appends the AccountData->data to the AccountFile.txt
 * Used for adding new user
 */
void Account::write() {
    Account::file->seekp(0, ios::end);
    Account::file->write((char*)&data, sizeof(AccountData));
    Account::noOfAccounts += 1;
}

/* Overwrites the account details in AccountFile.txt
 * of specified index with AccountData->data 
 */
void Account::write(int index) {
    Account::file->seekp(index * sizeof(AccountData), ios::beg);
    Account::file->write((char*)&data, sizeof(AccountData));
}

/* save the changes made in the AccountData->data
 */
void Account::save() {
    this->write(this->index);
}

/* creates a tempAccountFile.txt and copy-paste every AccountData
 * except current user (the (Account->index)+1) user)
 * then closes both files, removes original AccountFile.txt,
 * renames tempAccountFile.txt to AccountFile.txt and reopens the file 
 */
void Account::erase() {
    fstream tempFile("Data/tempAccountFile.txt", ios::out | ios::binary | ios::app);
    AccountData tempData;
    Account::file->seekg(0, ios::beg);
    for (int i = 0; i < Account::noOfAccounts; ++i) {
        Account::file->read((char*)&tempData, sizeof(AccountData));
        if (i != index) {
            tempFile.write((char*)&tempData, sizeof(AccountData));
        }
    }
    tempFile.close();
    Account::file->close();
    remove ("Data/AccountFile.txt");
    rename ("Data/tempAccountFile.txt", "Data/AccountFile.txt");
    Account::openFile();
}

/* Authenticate the password
 * if correct, returns 1
 * if not, return 0
 */
bool Account::authenticate(string password) {
    this->readAtIndex(Account::index);
    return this->data.getPassword() == password;
}

/* Check if Account->data.name is avialable for an new user or not
 * return 1 if available
 * else returns 0
 */
bool Account::isAvailable() {
    Account::file->seekg(0, ios::beg);
    AccountData tempData;
    int currentAccountIndex = 0;
    while(currentAccountIndex++ < Account::noOfAccounts) {
        Account::file->read((char*)&tempData, sizeof(AccountData));
        if(tempData.getName() == this->data.getName()) {
            return false;
        }
    }
    return true;
}

/* sets the AccountData->data.spent and AccountData->data.noOfItems to 0
 */
void Account::reset() {
    this->data.reset();
}

// setter methods
void Account::setIndex(int index) {
    this->index = index;
}

// getter methods
int Account::getNoOfAccounts() {
    return Account::noOfAccounts;
}
AccountData* Account::getAccountData() {
    return &(this->data);
}