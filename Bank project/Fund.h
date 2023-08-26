
//Created by Ayesha Mahmood 
//March 10, 2023
//Instructor: Professor Kalmin


#ifndef FUND_H
#define FUND_H
#include <string>
#include <vector>
#include "Transaction.h"
using namespace std;
//Class Declaration
class Fund
{
//private member 
//fundNumber and balance intialization 
private:
    int fundNum;
    int balance;

public:
//creating  vector of Transaction objects.
    vector<Transaction> transHistory;
    //fund constructor
    Fund();
    //fund destructor
    ~Fund();
    //getter for balance

    int getBalance();
    //setter for balance 
    void setBalance(int amount);
    //deposit method
    void Deposit(int amount);
    //withdraw method
    void Withdraw(int amount);
    //Add to history method 
    void addToHistory(Transaction history);
};
#endif