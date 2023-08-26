//Created by Ayesha Mahmood 
//March 10, 2023
//Instructor: Professor Kalmin


#ifndef BSTREE_H
#define BSTREE_H

#include "Account.h"

using namespace std;

class BSTree
{
private:
//members for struct node
    struct Node
    {
        Account *accountObject;
        Node *right;
        Node *left;
    };
    

public:
//constructor
    BSTree();
    //destructor
    ~BSTree();
    //fundTypes
    string fundTypes[10] = {"Money Market", "Prime Money Market", "Long-Term Bond", "Short-Term Bond", "500 Index Fund", "Capital Value Fund", "Growth Equity Fund", "Growth Index Fund", "Value Fund", "Value Stock Index"};
    //Node object pointer for root
    Node *root;
    
   
    //bool fucnction to insert account to tree

    bool Insert(Account *);
    //this is helper function to insert 
    bool RecursiveInsert(Account *, Node *);
    //to rerieve or find account 
    
    bool Retrieve(const int &, Account *&) const;
    //for diplaying and printing purposes
    void Display(Node *node) const;
    // recursive function ehich ewe will call in destructor to deallocate all nodes in tree
    
    void BSTPostOrderRecursiveDelete(Node* curr);



    
};
#endif