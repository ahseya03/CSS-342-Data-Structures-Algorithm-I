//Created by Ayesha Mahmood 
//March 10, 2023
//Instructor: Professor Kalmin

#ifndef BANK_H
#define BANK_H
#include <string>
#include <queue>
#include <iostream>
#include "BSTree.h"
#include "Transaction.h"
using namespace std;


class Bank
{
//three private members: fileName, TransactionQueue, and accountList.
private:
  
    string fileName;
    queue<Transaction> TransactionQueue;
    BSTree accountList;

public:
 
    //bank destructor
    ~Bank();
    //bank constructor
    Bank();
    
 //The public member is the string line which stores information about transactions in the queue.
    //string line for reading in file 
    string line;
    // firstName string to hold client first name
    string firstName;
    //client last name
    string lastName;
    //client account number
    int accountNum;
    //client fund Number 
    int fundNum;
    //used for transferrrig to other account
    int toAccountNum;
    //usef for transfeering o specific fund index
    int toFundNum;
    //initializing ID 
    int ID;
    //intiliazing the other other ID 
    int toID;
    // intializing action type like 'O', 'W' , 'H' , D and T
    char Action;
    // amount 
    int amount;
    string fundTypes[10] = {"Money Market", "Prime Money Market", "Long-Term Bond", "Short-Term Bond", "500 Index Fund", "Capital Value Fund", "Growth Equity Fund", "Growth Index Fund", "Value Fund", "Value Stock Index"};
    //The readTransactions() function reads transactions from a file named "transactions.txt" and places them into the queue for execution by executeTransactions().
    void readTransactions(string fileName);
    // method for execute transaction
    void executeTransactions();
    //The print() function prints out all of the data stored in line to standard output (the screen).
    void Print();
 
    
   
   
};


#endif