//Created by Ayesha Mahmood 
//March 10, 2023
//Instructor: Professor Kalmin


#include <iostream>
#include "Fund.h"
using namespace std;

//Fund Constructor 
//set balance as deault 0 
Fund::Fund(){
    this->balance = 0;
}
//Fund Destructor 

Fund::~Fund(){
    
}
int Fund::getBalance(){
    return balance;
}

// setter for setting balance it take in amount affter deduction or addition and sets balance
void Fund::setBalance(int amount){
    balance = amount;
}

//deposit method it adds specified amount to old balance
void Fund::Deposit(int amount){
    int newBalance = getBalance() + amount;
    setBalance(newBalance);
}

//withdraw it withdraws soecified amount from old balance 
void Fund::Withdraw(int amount){
    int newBalance = getBalance() - amount;
    setBalance(newBalance);
}

// this method is for adding transactions to history
void Fund::addToHistory(Transaction history){
    transHistory.push_back(history);
}