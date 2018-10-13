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
    void open();
    void close();
    void newItem();
    void readItem();
    void writeItem();
    void writeItem(int);
    int getNoOfItems();
};
User :: ~User() {
    close();
}
User :: User(char username[30]) {
    strcpy(this->username, username);
    file = new fstream();
    open();
    noOfItems = getNoOfItems();
}

void User :: open() {
    file->open(username, ios::in | ios::out | ios::binary | ios::ate);
    noOfItems = countNoOfItems();
}

void User :: close() {
    file->close();
    delete file;
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

int User::getNoOfItems() {
    return noOfItems;
}

int User::countNoOfItems() {
    file->seekp(0, ios::end);
    int filesize = file->tellp();
    return filesize / (sizeof(Item));
}