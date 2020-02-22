#ifndef __ACCOUNT_H_INCLUDED__
#define __ACCOUNT_H_INCLUDED__

// forward declared dependencies

// included dependencies
#include <fstream>
#include <string>
#include "AccountData.h"

using namespace std;

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

#endif