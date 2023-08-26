/// Created by Ayesha
// Professor: Lesley Kalmin
// Jan 12, 2023
#include <cassert>
#include "library.h"
#include<string>
#include<iostream>
using namespace std;

// Global variable that keeps track of last book added
int tracker=0;

// Implementing overload friend function for output
ostream &operator<<(ostream &out, const Library &lib){
        out<<lib.arr[0];
        lib.ListAllBooks();
        return out;
       
    
    
}
// Implementation of Parametrized Constructor


    
// findBook function that iterates through array to find book
// returns index of book if book found
// else returns -1

int Library::findBook(const std::string &name)const

{
    for(int i = 0; i<100; i++)
    {
        if (arr[i]==name){
            return i;
            
        }
    }
    return -1;
}
// bool function for AddBook method
// Checks 4 Edge Cases:


bool Library::AddBook(const std::string &name){
 // Case 1:  to check if index  = 100 once it hits 100 return false because no more book can be added
    if(tracker==100){
        return false;
    }
    
// Case 2: If index =0 means its empty container add boook to the 0th index and increase count of tracker(index)
    else if(tracker==0){
        arr[0] = name;
        tracker++;
        return true;
    }else{
// Case 3: If book is in the container of array - return false - can't add same book twice 
        for(int i=0;i<100;i++){
            if(arr[i]==name){
                return false;
            } 
        }
// Case 4: If book is not in the container - return true - tracker +1 is the index of 
//last book added index plus the one- so place book there
        arr[tracker+1]= name;
        // increase count of tracker after adding
        tracker++;
        return true;
    }
}
// Function to Remove Book
// iterate through  the container of books
// If array of index is == to book you wanna remove
// substitute array of index you removing  with array of last index of book
// make last index of book empty
// since removed decrease count of tracker

bool Library::RemoveBook(const std::string &name){
    for(int i=0;i<100;i++){
        if(arr[i]==name){
            arr[i]=arr[tracker];
            arr[tracker]="";
            tracker--;
            return true;
        }
        
    }return false;
}
// iterate through all the books in library and print out contents
void Library::ListAllBooks()const{
    cout<<"\n"<<"The names of books in Library are:"<<"\n";
    for(int i =0; i<100;i++){
        if (arr[i]!=""){
            
            cout<<"\n"<<arr[i]<<"\n";
        }
    }
}
// checks if specific book in library
// returns boolean
bool Library::IsInLibrary(const std::string &name)const{
    
    for(int i=0;i<100;i++){
        if (name==arr[i]){
        cout<<"Book is in the library"<<endl;
        return true;
       }
    }
    return false;

}
