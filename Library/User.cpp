#include <string>
#include "Item.cpp"
#include "vector"

class User {
    Item item;
    int noOfItems, index;
    float spent;
    fstream *file;
    char username[30];
    void open(string username);
    void countNoOfItems();
    void calculateSpent();

    public:
    ~User();
    User(string username);
    void reset();
    void open();
    void reload();
    void close();
    void logOut();
    bool isOpen();
    void newItem();
    void readItem();
    void readItemAt(int index);
    void writeItem();
    void writeItem(int index);
    void deleteLastRecord();
    vector<int> getYears();
    void printItemsForAllYears();
    void printItemsForYear(int year);
    void printItemsForYearAndMonth(int years, int month);
    void printItemsBetweenDates(Date dateRangeStart, Date dateRangeEnd);
    static void createDataSource(string username);
    static void deleteDataSource(string username);
    static string getFilePath(string username);
    string getFilePath();
    string getName();
    int getNoOfItems();
    float getSpent();
};

// contructors
User :: ~User() {
    this->logOut();
}
User :: User(string username) {
    strcpy(this->username, username.c_str());
    this->file = new fstream();
}

/* truncate data from the user file and starts over
 */
void User::reset() {
    this->close();
    fstream f(username, ios::out | ios::trunc);
    f.close();
    this->open();
}

/* opens file of user's name
 */
void User :: open() {
    file->open(this->getFilePath().c_str(), ios::in | ios::out | ios::binary | ios::ate);
    this->calculateSpent();
}

/* closes and opens the current user's file to make realtime changes in the file to be reflected
 */
void User::reload() {
    User::close();
    User::open();
}

/* closes the current user's file
 */
void User :: close() {
    if(!this->file) {
        return;
    }
    if(this->isOpen()) {
        file->close();
    }
}

/* closes the file and deallocates file pointer memory
 */
void User::logOut() {
    close();
    delete this->file;
    this->file = nullptr;
}

/* checks if the current user's file is open or not
 */
bool User :: isOpen() {
    return this->file->is_open();
}

/* create a new item object complete with to be saved 
 */
void User::newItem() {
    this->item.askForItem();
}

/* read item from current user's file from current cursor position
 */
void User::readItem() {
    this->file->read((char*)&this->item, sizeof(Item));
}

/* Read item details from current user's file from specified index
 */
void User::readItemAt(int index) {
    this->file->seekg(index * sizeof(Item), ios::beg);
    this->file->read((char*)&this->item, sizeof(Item));
}

/* appends the item details in current user's file with User->item
 */
void User::writeItem() {
    this->file->seekp(0, ios::end);
    this->file->write((char*)&this->item, sizeof(Item));
    this->reload();
}

/* Overwrites the Item details in current user's file at specified index
 * with User->item
 */
void User::writeItem(int index) {
    this->file->seekp(index * sizeof(Item));
    this->file->write((char*)&this->item, sizeof(Item));
    this->reload();
}

/* deletes the last item written in current user's file.
 * A new temperary file is created and all but last item from original file
 * is copied to temperary file.
 * The original file is then deleted and the temperary file is renamed as
 * original file.
 */
void User::deleteLastRecord() {
    fstream tempUserFile("Data/tempUserFile", ios::out | ios::binary | ios::app);
    Item tempItem;
    this->file->seekg(0, ios::beg);
    for(int i = 0; i < getNoOfItems() - 1; ++i) {
        this->file->read((char*)&tempItem, sizeof(Item));
        tempUserFile.write((char*)&tempItem, sizeof(Item));
    }
    tempUserFile.close();
    this->file->close();
    remove(this->getFilePath().c_str());
    rename("Data/tempUserFile", this->getFilePath().c_str());
    this->open();
}

/* prints item from all years, basically each and every item in current
 * user's file
 */
void User::printItemsForAllYears() {
    vector<int> years = this->getYears();
    Date dateRangeStart, daterangeEnd;
    dateRangeStart.setDate(years.front(), 1, 1);
    daterangeEnd.setDate(years.back(), 12, 31);

    system("cls");

    this->printItemsBetweenDates(dateRangeStart, daterangeEnd);
}

/* prints all item for the specified year
 */
void User::printItemsForYear(int year) {
    Date DateRangeStart, dateRangeEnd;
    DateRangeStart.setDate(year, 1, 1);
    dateRangeEnd.setDate(year, 12, 31);

    system("cls");

    this->printItemsBetweenDates(DateRangeStart, dateRangeEnd);
}

/* prints all items for the year and month
 */
void User::printItemsForYearAndMonth(int year, int month) {
    Date dateRangeStart, dateRangeEnd;
    dateRangeStart.setDate(year, month, 1);
    dateRangeEnd = dateRangeStart.getEndOfMonth();

    system("cls");

    this->printItemsBetweenDates(dateRangeStart, dateRangeEnd);
}

/* prints all item between specified date range
 */
void User::printItemsBetweenDates(Date dateRangeStart, Date dateRangeEnd) {
    float spent = 0;
    this->file->seekg(0, ios::beg);
    this->item.printHeaders();
    cout<<endl;
    for(int i = 0; i < this->getNoOfItems(); ++i) {
        this->readItem();
        if(this->item.getDate() >= dateRangeStart && this->item.getDate() <= dateRangeEnd) {
            spent += this->item.getPrice();
            this->item.print();
            cout<<"\n";
        }
    }
    Item::printTotal(spent);
}
/* create a new file of specified name
 */
void User :: createDataSource(string username) {
    fstream file(User::getFilePath(username).c_str(), ios::out);
    file.close();
}

/* delete the file of specified name
 */
void User :: deleteDataSource(string username) {
    remove(User::getFilePath(username).c_str());
}

/* return a colllection of years presentin the current user's file
 */
vector<int> User::getYears() {
    vector<int> years;
    int year;
    bool isYearNotPresent;
    this->file->seekg(0, ios::beg);
    for (int i = 0; i < this->getNoOfItems(); ++i ) {
        this->readItem();
        year = this->item.getDate().getYear();
        isYearNotPresent = true;
        for (int j = 0; j < years.size(); ++j) {
            if(years.at(j) == year) {
                isYearNotPresent = false;
            }
        }
        if(isYearNotPresent) {
            years.emplace_back(year);
        }
    }
    return years;
}

/* counts the no of item present in current user's file
 * the position of put pointer of file is equal to size of file, which when 
 * divided by size of Item class gives no of items
 */
void User::countNoOfItems() {
    this->file->seekp(0, ios::end);
    int filesize = (int)this->file->tellp();
    if(filesize < 0) {
        filesize = 0;
    }
    this->noOfItems = (filesize / (sizeof(Item)));
}

/* calculate the total amount spent
 */
void User::calculateSpent() {
    float spent = 0;
    this->countNoOfItems();
    this->file->seekg(0, ios::beg);
    for(int i = 0; i < this->getNoOfItems(); ++i) {
        this->readItem();
        spent += this->item.getPrice();
    }
    this->spent = spent;
}

// getter methods
string User :: getFilePath(string username) {
    return "Data/" + username;
}
string User :: getFilePath() {
    return "Data/" + this->getName();
}
string User :: getName() {
    return this->username;
}
int User::getNoOfItems() {
    return this->noOfItems;
}
float User::getSpent() {
    return this->spent;
}