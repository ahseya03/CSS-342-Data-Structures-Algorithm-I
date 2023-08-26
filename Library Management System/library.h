// Created by Ayesha
// Professor: Lesley Kalmin
// Jan 12, 2023

#ifndef SPRING22_LIBRARY_H
#define SPRING22_LIBRARY_H
#include <string>
#include <iostream>
using namespace std;
class Library
{   
    int index=0;
    // Friend Operator Overload
    friend ostream &operator<<(ostream &out, const Library &lib);
    private:
        // Private variables
        static const int MAX = 100;
        int numberOfBooks;
        string arr[MAX];
        // Private Method
        int findBook(const string &name)const;
        

    public:
        // Parameterized Constructors
        Library(std::string name){
            cout<<name;
        }

        //Public Methods
        const int findNumberOfBooks();
        bool AddBook(const string &name);
        bool RemoveBook(const string &name);
        void ListAllBooks()const;
        // void TestAll();
        bool IsInLibrary(const string &name)const;
        


};
#endif 
