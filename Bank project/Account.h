//Created by Ayesha Mahmood 
//March 10, 2023
//Instructor: Professor Kalmin

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <fstream>
#include "Transaction.h"
#include "Fund.h"


using namespace std;

//declaration of constant max for fund array size 
const int FUND_ARRAY_MAX_SIZE = 10;

//Account class 
class Account
{
    //private data like account number, balance and first name and last name of client 
private:
    int accountNum, balance;
    string firstName, lastName;

public:
    //fund Array object array that consist of max size of 10
    Fund fundArray[FUND_ARRAY_MAX_SIZE];
    //Account constructor default
    Account();
    //Account parametrized constructor that take sin client first last name and account number to create an account 
    Account(string firstName, string lastName, int accountNum);
    ~Account();
    //getters 
    string getFirstName();
    string getLastName();
    int getAccountNum();
    int getBalance(int fundNum);

    //method rinting transaction for specific fund of an account 
    void printTransaction(int fundNum);
};
#endif