//Created by Ayesha Mahmood 
//March 10, 2023
//Instructor: Professor Kalmin


#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

using namespace std;
//class declaration 
class Transaction{
//private memebers 
private:
    string firstName;
    string lastName;
    int accountNumber1;
    int accountNumber2;
    int Fund1;
    int Fund2;
    int amount;
    char Action;
    bool failed = false;

public:
    // Constructor
    Transaction();
    //destructor 
    ~Transaction(){
        
      
    }
    
    //  these parametrized constructor wll support transactions and stored them into transaction queue
    Transaction(char Action, int accountNumber1, int Fund1);

    Transaction(char Action, int accountNumber1, int Fund1, int amount);
    Transaction(char Action, string firstName, string lastName, int accountNumber1);
    Transaction(char Action, int accountNumber1, int Fund1, int amount, int accountNumber2, int Fund2);

    // ostream for printing transactions 
    friend ostream &operator<<(ostream &os, Transaction &transaction);

    // getters for get action, account number , fund number, amount , getTo Account num 
    char getAction();
    int getAccountNum();
    int getFundNum();
    int getAmount();
    int getToAccountNum();
    int getToFundNum();
    // help mark it as failed if transactions fails will use in bank.cpp
    bool getFailed();
    // Setters for setting transaction as failed
    void setFailed(bool x);
    //getter for get first name last name 
    string getFirstName();
    string getLastName();
     void setBalance(int x);
};

#endif