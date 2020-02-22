#ifndef __ACCOUNTDATA_H_INCLUDED__
#define __ACCOUNTDATA_H_INCLUDED__

// forward declared dependencies

// included dependencies
#include <string.h>

using namespace std;

class AccountData {
    private:
    char name[30], password[15];
    int noOfItems;
    float spent;
    
    public:
    AccountData();
    AccountData(string name, string password, float spent, int noOfItem);
    void printAccount();
    void reset();
    int isAvailable();
    void setName(string name);
    void setPassword(string password);
    void setNoOfItems(int noOfItems);
    void setSpent(float spent);
    string getName();
    string getPassword();
    float getSpent();
    int getNoOfItems();
};

#endif