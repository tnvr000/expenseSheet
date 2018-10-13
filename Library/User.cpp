#include <string.h>
#include "Item.cpp"

class User {
    Item item;
    int noOfItems, index;
    fstream *file;
    char username[30];
    void open(char*);
public:
    ~User();
    User(char*);
    void open();
    void close();
};
User :: ~User() {
    close();
}
User :: User(char username[30]) {
    strcpy(this->username, username);
    file = new fstream();
    open();
}

void User :: open() {
    file->open(username, ios::in | ios::out | ios::binary | ios::ate);
}

void User :: close() {
    file->close();
    delete file;
}
