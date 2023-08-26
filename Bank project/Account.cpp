
//Created by Ayesha Mahmood 
//March 10, 2023
//Instructor: Professor Kalmin

#include "Account.h"
#include "Fund.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
// Account constructor
Account::Account(){
    
}
//Account Destructor

Account::~Account(){
     
}
//Account parametrized constructor that take in first name last name and account number
//will be used in bank.cpp to create an account for client 
Account::Account(string firstName, string lastName, int accountNum){
   
    this->firstName = firstName;
    this->lastName = lastName;
    this->accountNum = accountNum;
}
//getters for get first name
//returns Client's firstname 
string Account::getFirstName(){
   
    return firstName;
}
//returns client's last name 

string Account::getLastName(){

    return lastName;
}
//returns Account Number 
int Account::getAccountNum(){

    return accountNum;
}
//gets balance in specific fund 

int Account::getBalance(int fundNum){

    int balance = fundArray[fundNum].getBalance();
    return balance;
}

//prints the transaction iterating through fund array and if anyone transaction had failed adds a "Failed"
void Account::printTransaction(int fundNum){

    for (int i = 0; i < fundArray[fundNum].transHistory.size(); i++){
       
        if (fundArray[fundNum].transHistory[i].getFailed() == true){
            cout << "    " << fundArray[fundNum].transHistory[i] << " (Failed)" << endl;
        }else{
          cout << "    " << fundArray[fundNum].transHistory[i] << endl;
        }
    }
}
