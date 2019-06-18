#include <string.h>
#include "Item.cpp"

class User {
    Item item;
    int noOfItems, index;
    fstream *file;
    char username[30];
    void open(char*);
    int countNoOfItems();
    public:
    ~User();
    User(char*);
    void reset();
    void open();
    void close();
    void logOut();
    void newItem();
    void readItem();
    void readItemAt(int index);
    void writeItem();
    void writeItem(int index);
    void printItemsBetweenDate(Date dateRangeStart, Date dateRangeEnd);
    static void createDataSource(char* username);
    static void deleteDataSource(char* username);
    static char* getFilePath(char* username);
    char* getFilePath();
    char* getName();
    int getNoOfItems();
    bool isOpen();
};
User :: ~User() {
    logOut();
}

User :: User(char username[30]) {
    strcpy(this->username, username);
    file = new fstream();
}

void User::reset() {
    close();
    fstream f(username, ios::out | ios::trunc);
    f.close();
    open();
}

bool User :: isOpen() {
    bool isOpen = file->is_open();
    if(isOpen) {
        printf("file is open");
    } else {
        printf("file is not open");
    }
    getch();
    return isOpen;
}

char* User :: getFilePath(char username[]) {
    char filePath[100] = "Data/";
    strcpy(filePath, strcat(filePath, username));
    return filePath;
}

char* User :: getFilePath() {
    char filePath[100] = "Data/";
    strcpy(filePath, strcat(filePath, this->username));
    return filePath;
}

char* User :: getName() {
    return this->username;
}

void User :: createDataSource(char username[]) {
    string filePath = "Data/" + (string)username;
    fstream file(filePath, ios::out);
    file.close();
}

void User :: deleteDataSource(char username[]) {
    char filePath[100] = "Data/";
    strcat(filePath, username);
    remove((char*)filePath);
}

void User :: open() {
    char filePath[100] = "Data/";
    strcat(filePath, this->username);
    file->open(filePath, ios::in | ios::out | ios::binary | ios::ate);
    this->noOfItems = countNoOfItems();
}

void User :: close() {
    if(!file)
        return;
    if(isOpen())
        file->close();
}

void User::logOut() {
    close();
    delete file;
    file = nullptr;
}

// create a new item to save
void User::newItem() {
    item.askForItem();
    item.print();
}

// read item from <username> file from current cursor position
void User::readItem() {
    file->read((char*)&item, sizeof(Item));
}

// Read item details from <username> file from specified index
void User::readItemAt(int index) {
    file->seekg(index * sizeof(Item));
    file->read((char*)&item, sizeof(Item));
}

void User::writeItem() {
    file->seekp(0, ios::end);
    file->write((char*)&item, sizeof(Item));
}

/* Overwrites the Item details in <username> file at specified index
 * with User->item
*/
void User::writeItem(int index) {
    file->seekp(index * sizeof(Item));
    file->write((char*)&item, sizeof(Item));
}

void User::printItemsBetweenDate(Date dateRangeStart, Date dateRangeEnd) {
    
}

int User::getNoOfItems() {
    return this->noOfItems;
}

int User::countNoOfItems() {
    file->seekp(0, ios::end);
    int filesize = (int)file->tellp();
    printf("%d", filesize);
    if(filesize < 0)
        filesize = 0;
    return filesize / (sizeof(Item));
}