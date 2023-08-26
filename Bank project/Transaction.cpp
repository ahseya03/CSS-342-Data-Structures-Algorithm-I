//Created by Ayesha Mahmood 
//March 10, 2023
//Instructor: Professor Kalmin



#include <ostream>
#include "Transaction.h"
#include<iostream>

using namespace std;

// this paramaterized constructor will be used for deposit or withdraw
Transaction::Transaction(char Action, int accountNumber1, int Fund1, int amount){
    this->Action = Action;
    this->accountNumber1 = accountNumber1;
    this->Fund1= Fund1;
    this->amount = amount;
  
}
//will be used for tranfer

Transaction::Transaction(char Action ,int accountNumber1, int Fund1 ,int amount, int accountNumber2, int Fund2){
    this->Action = Action;
    this->accountNumber1 = accountNumber1;
    this->Fund1 = Fund1;
    this->amount = amount;
    this->accountNumber2 = accountNumber2;
    this->Fund2 = Fund2;

}
//will be used to to create account 
Transaction::Transaction(char Action, string firstName, string lastName, int accountNumber1){
    this->Action = Action;
    this->firstName = firstName;
    this->lastName = lastName;
    this->accountNumber1 = accountNumber1;

}
// this paramaterized constructor will be used for history transaction 
Transaction::Transaction(char Action, int accountNumber1, int Fund1){
    this->Action = Action;
    this->accountNumber1 = accountNumber1;
    this->Fund1= Fund1;

}

//getters
//returns action type
char Transaction::getAction(){
    return Action;
}
//return account number1 account Num itself
int Transaction::getAccountNum(){
    return accountNumber1;
}

//get acccount fund number 
int Transaction::getFundNum(){
    return Fund1;
}
//get to fund Num you are making change to 
int Transaction::getToFundNum(){
    return Fund2;
}
//get Amount 

int Transaction::getAmount(){
    return amount;
}

//get other account you making change to
int Transaction::getToAccountNum(){
    return accountNumber2;
}
//get wheter failed or not 
bool Transaction::getFailed(){
    return failed;
}
//get client first name 
string Transaction::getFirstName(){
    return firstName;
}
//get client last name 
string Transaction::getLastName(){
    return lastName;
}

// Setter for setting transaction to failed 

void Transaction::setFailed(bool f){
    this->failed = f;
}
//setter for setting balance 

void Transaction::setBalance(int amount){
    this->amount = amount;
    //ostream to help print transactionss
}
ostream &operator<<(ostream &os, Transaction &transaction){


      if (transaction.getAction() == 'T'){
        os<< transaction.getAction() << " " << transaction.getAccountNum() << transaction.getFundNum() << " " << transaction.getAmount() << " " << transaction.getToAccountNum() << transaction.getToFundNum();
    }else{
        os<< transaction.getAction() << " " << transaction.getAccountNum() << transaction.getFundNum() << " " << transaction.getAmount();
    }
  
    return os;
}