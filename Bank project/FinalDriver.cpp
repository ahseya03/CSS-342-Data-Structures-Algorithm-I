//Created by Ayesha Mahmood 
//March 10, 2023
//Instructor: Professor Kalmin


#include <iostream>
#include "Bank.h"

using namespace std;


void test1(){
     Bank A;
    A.readTransactions("BankTransIn.txt");
    A.executeTransactions();
    A.Print();



}

int main()
{
   test1();
 
    return 0;
}