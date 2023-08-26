//Created by Ayesha Mahmood 
//March 10, 2023
//Instructor: Professor Kalmin

#include "Bank.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include<memory>
using namespace std;
    // Default contrustor initialization for Bank
    Bank::Bank(){

    }
    //Destructor goes thru Transaction Queue while not empty it pops
    Bank::~Bank(){
        while(!TransactionQueue.empty()){
            TransactionQueue.pop();
        }
    }
    // Method takes in a filename as its argument and opens that file for reading using ifstream myfile
    void Bank::readTransactions(string filename){        
        
        ifstream myfile;
    
        myfile.open(filename);
    //If the file cannot be found, then an error message is printed 
        if (!myfile){ 
            cout << "ERROR: Could Not Find File Named" <<""""<<filename<<""""<<endl;
            exit(1);
        }
        //Otherwise, while (!myfile.eof()) method gets line from myfile into stringstream parse(line)
        //where parse>> Action; looks at each line of text the first command for it "O", "D""W", "H",or T


    while (!myfile.eof()){ 
        getline(myfile, line);
    
        // If line empty break out of loop
        if (line.empty()){
            break;
        }
        stringstream parse(line);
        parse>> Action;
        // then we check the value of Action and if it is equal to 'O' create account
        //then will parse firstName, lastName, and accountNum into variables.
        //edge case: if account is not 4 digits then print ERROR message
        //else open account and push to transaction Queue
       

        if (Action == 'O'){   
            parse>> firstName >> lastName >> accountNum;
            if(std::to_string(accountNum).length()!=4){
                   cout<<"ERROR:: Invalid Account Number cannot create account with this number  has to be 4 digits"<<endl;
            }
            Transaction openAccount(Action, firstName, lastName, accountNum);
            TransactionQueue.push(openAccount);
        }
        //If Action equals 'D' , then parse ID and amount into variables 
        //then check for edge cases if account digit is not 5 or if it is negative amount then cant deposit
        //ID Moduluo 10 gives fund last index  number eg. 10011 mod 10 = 1
        //ID/10 gives account Num i.e. 4 digits eg.10011/10 =1001.1 casting it to int 10001
        if (Action == 'D'){ 

                parse>> ID >> amount;
                if(std::to_string(ID).length()!=5){
                    cout<<"ERROR:: Invalid Account Number."<<endl;
                }
                if(amount<0){
                    cout<<"ERROR: Cannot Deposit Negative number."<<endl;
                }
                fundNum = ID % 10;
                accountNum = int(ID / 10);
                Transaction depositInfo(Action, accountNum, fundNum, amount);
                TransactionQueue.push(depositInfo);
            }
        //If Action equals 'W' , then parse ID and amount into variables 
        //then check for edge cases if account digit is not 5 or if it is negative amount then cant deposit
        //ID Moduluo 10 gives fund last index  number eg. 10011 mod 10 = 1
        //ID/10 gives account Num i.e. 4 digits eg.10011/10 =1001.1 casting it to int 10001
         if ( Action == 'W'){ 
            parse>> ID >> amount;
            if(std::to_string(ID).length()!=5){
                cout<<"ERROR:: Invalid Account Number."<<endl;
            }
            if(amount<0){
                cout<<"ERROR: Cannot Deposit Negative number."<<endl;
            }
            fundNum = ID % 10;
            accountNum = int(ID / 10);
            Transaction withdrawInfo(Action, accountNum, fundNum, amount);
            TransactionQueue.push(withdrawInfo);
        }
        ////If Action equals 'T' , then parse ID and amount into variables 
        //then check for edge cases if account digit is not 5 as well as other account not 5 digit or if it is negative amount then cant deposit
        //ID Moduluo 10 gives fund last index  number eg. 10011 mod 10 = 1
        //ID/10 gives account Num i.e. 4 digits eg.10011/10 =1001.1 casting it to int 10001
        if (Action == 'T'){ 
            parse>> ID >> amount >> toID;
            
            if(std::to_string(ID).length()!=5 && std::to_string(toID).length()!=5){
                cout<<"ERROR:: Invalid Account Number."<<endl;
            }
            
            if(amount<0){
                cout<<"ERROR: Cannot Transfer Negative Amount."<<endl;
            }
            fundNum = ID % 10;
            accountNum = int(ID / 10);
            toFundNum = toID % 10;
            toAccountNum = int(toID / 10);
            Transaction transferInfo(Action, accountNum, fundNum, amount, toAccountNum, toFundNum);
            TransactionQueue.push(transferInfo);
        }
        //If Action = 'H' then parse in the ID 
        // if 4 digit then its histry by fund
        // multiply it by -1 so we can later use it as marking for fund history,
        //if it is not negative index and 0-9 then its just overall history not by fund

       if (Action == 'H')
        { 
            parse>> ID;
            if (std::to_string(ID).length()==4){
                accountNum = ID;
                fundNum = ID % 10;
                fundNum = (fundNum)*-1;
                Transaction fundHistoryInfo(Action, accountNum, fundNum);
                TransactionQueue.push(fundHistoryInfo);
            }else{
               accountNum = int(ID / 10);
               fundNum = ID % 10;
               Transaction HistoryInfo(Action, accountNum, fundNum);
               TransactionQueue.push(HistoryInfo);
            }
        }
        if(Action!='O'&&Action!='D'&&Action!= 'W'&&Action!='T'&&Action!= 'H'){
            cout<<" Invalid Command" <<endl;
        }
      
    }
    //Close file after reading 
    myfile.close();
}
//Method to execute transactions
void Bank::executeTransactions()
{
    // as long the Transaction Queue not empty we do the following operations 'O' 'W' 'T' 'H' 'D'
    // make trans Object
    
    while (!TransactionQueue.empty())
    {
        Transaction transObject = TransactionQueue.front();
        char Action;
        Action = transObject.getAction();
        Account *A= NULL;
        // create account if 'O' If can't creat means its duplicate delete it otherwise we allocating extra memory
        if (Action == 'O'){
            Account *A = new Account(transObject.getFirstName(), transObject.getLastName(), transObject.getAccountNum());
           if(!accountList.Insert(A)){
               
                delete A;
            }
        }
        //If deposit then retrieve the account itself and then deposit to it and add to history
        else if (Action == 'D'){
            int accountNum = transObject.getAccountNum(), fundNum = transObject.getFundNum(), amount = transObject.getAmount();
            accountList.Retrieve(accountNum, A);
            A->fundArray[fundNum].Deposit(amount);
            A->fundArray[fundNum].addToHistory(transObject);
        }
        //If withdraw then retrieve the account itself and then withdraw to it and then add to history 
        else if (Action == 'W'){
            int accountNum = transObject.getAccountNum(), fundNum = transObject.getFundNum(), amount = transObject.getAmount();
            accountList.Retrieve(accountNum, A);
            if (amount <= A->fundArray[fundNum].getBalance()){
                A->fundArray[fundNum].Withdraw(amount);
                A->fundArray[fundNum].addToHistory(transObject);
            }
            // if amount to withdraw is more than balance
            if (amount > A->fundArray[fundNum].getBalance()){
                // is special fund // 0 1 and 2 3 are linked so if not enoughh we borrow each other  fundNum mod 0 would given even account 0 and 2 and if even we borrow from the fundNumber +1 so if 0 then 1 and if 2 then 3
                //versus if it is odd 3 and 1 so fundNum-1 so if it is 3 then 2 and if 1 then borrow from 0
                
                if (fundNum<4&&fundNum>=0){
                    if (fundNum%2==0){
                        if (amount > (A->fundArray[fundNum].getBalance() + A->fundArray[fundNum + 1].getBalance())){
                            transObject.setFailed(true);
                            A->fundArray[fundNum].addToHistory(transObject);
                            } else{
                                int newBalance = A->fundArray[fundNum].getBalance();
                                A->fundArray[fundNum].setBalance(0);
                                amount = amount - newBalance;
                                A->fundArray[fundNum + 1].Withdraw(amount);
                                transObject.setBalance(newBalance);
                                Transaction newTrans(Action, accountNum, fundNum + 1, amount);
                                A->fundArray[fundNum].addToHistory(transObject);
                                A->fundArray[fundNum + 1].addToHistory(newTrans);
                            }
                    }
                    else if (fundNum%2==1){
                        if (amount > (A->fundArray[fundNum].getBalance() + A->fundArray[fundNum - 1].getBalance())){
                                transObject.setFailed(true);
                                A->fundArray[fundNum].addToHistory(transObject);
                        }else{
                            int newBalance = A->fundArray[fundNum].getBalance();
                            A->fundArray[fundNum].setBalance(0);
                            amount = amount - newBalance;
                            A->fundArray[fundNum - 1].Withdraw(amount);
                            transObject.setBalance(newBalance);
                            Transaction newTrans(Action, accountNum, fundNum - 1, amount);
                            A->fundArray[fundNum].addToHistory(transObject);
                            A->fundArray[fundNum - 1].addToHistory(newTrans);
                            }
                     }
                }
                //if not special case accounts  just print error message 
                    else{
                    transObject.setFailed(true);
                    cout<< "ERROR: Not enough funds to withdraw " << amount << " from " << A->getLastName() << " " << A->getFirstName() << " " << fundTypes[fundNum] << endl;
                    A->fundArray[fundNum].addToHistory(transObject);
                    }
                  
            }  
            
            
            
        }
        // If action is transfer then retrieve both account and then withdraw from account fund itself to the same account other fund depisit and add to history 
        else if (Action == 'T'){
            int accountNum = transObject.getAccountNum(), fundNum = transObject.getFundNum(), amount = transObject.getAmount();
            int toAccountNum = transObject.getToAccountNum(), toFundNum = transObject.getToFundNum();
            Account *A ,*B;
           if (accountList.Retrieve(accountNum, A)&&accountList.Retrieve(toAccountNum, B)) {
                A->fundArray[fundNum].Withdraw(amount);
                B->fundArray[toFundNum].Deposit(amount);
                A->fundArray[fundNum].addToHistory(transObject);
                B->fundArray[toFundNum].addToHistory(transObject);
            }
       }
       //if action is H then retrieve account and is fubnd num is less than 0 previously we set account history by fund to negative funds as marks so if negative 
       //print history by fund
       //else get account summary 
      else if (Action == 'H'){
            int accountNum = transObject.getAccountNum();
            accountList.Retrieve(accountNum, A);
            if (transObject.getFundNum() < 0){
                cout << "Transaction History for " << A->getLastName() << " " << A->getFirstName() << " by fund." << endl;
                for (int i = 0; i < 10; i++){
                        if (A->fundArray[i].transHistory.size() > 0) {
                            cout<< fundTypes[i] << ": $" << A->fundArray[i].getBalance() << endl;
                            A->printTransaction(i);
                        }
                } 
                    
            }else{
                    cout << "Transaction History for " << A->getLastName() << " " << A->getFirstName() << " " << fundTypes[transObject.getFundNum()] << ": $" << A->fundArray[transObject.getFundNum()].getBalance() << endl;
                    A->printTransaction(transObject.getFundNum());
            }
        }
        TransactionQueue.pop();
    }
}

void Bank::Print()
{
   // sisplay all accound and funds
    cout<< "Processing Done. Final Balances" << endl;
    accountList.Display(accountList.root);
}

