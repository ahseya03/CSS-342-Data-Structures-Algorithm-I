
//Created by Ayesha Mahmood 
//March 10, 2023
//Instructor: Professor Kalmin


#include "BSTree.h"

#include <iostream>
#include <fstream>
using namespace std;
//The constructor : we are  setting  root to nullptr, meaning that it is not yet initialized.
BSTree::BSTree(){
    root = nullptr;
    
}
//The destructor of the BSTree class deletes all nodes in the tree and then deletes itself from memory.
//It does this by calling its own destructor recursively until there are no more nodes left to delete.
BSTree::~BSTree(){
   BSTPostOrderRecursiveDelete(root);

}
//This is  recursive function that deletes the node at the root of the tree.
//This is used to delete all nodes in a BST tree.
void BSTree::BSTPostOrderRecursiveDelete(Node* curr){
    
    if (curr == nullptr){
		return; 
	}
    BSTPostOrderRecursiveDelete(curr->left);
	BSTPostOrderRecursiveDelete(curr->right);
    delete curr->accountObject;
    delete curr;
	curr = nullptr;
}


//function to insert account into tree as root 
//if it cant then it passes root node to recursive helper that will find the current place to put account 

bool BSTree::Insert(Account *accountNode){

    if (root == nullptr){
        root = new Node;
        root->accountObject = accountNode;
        root->left = nullptr;
        root->right = nullptr;
        return true;
    }
    else{
        Node *curNode = root;
        return RecursiveInsert(accountNode, curNode);
    }
}
/*The code is recursive, meaning it will go thru all of the nodes in the tree and try to insert that account into each node.
so this function if curNode is left we check if less if null  and account we trying to add is greater so we place it in left node  else call recursive insert to find place to add again 
else if right is null we just place it right else call recursive insert to try again 

*/
bool BSTree::RecursiveInsert(Account *accountNode, Node *curNode){
    
    if (accountNode->getAccountNum() < curNode->accountObject->getAccountNum()){
        if (curNode->left == nullptr){
            Node *nNode = new Node();
            nNode->accountObject = accountNode;
            nNode->left = nullptr;
            nNode->right = nullptr;
            curNode->left = nNode;
            return true;
        }
        else{
            return RecursiveInsert(accountNode, curNode->left);
        }
    }
    else if (accountNode->getAccountNum() > curNode->accountObject->getAccountNum()){
        if (curNode->right == nullptr)
        {
            Node *nNode = new Node();
            nNode->accountObject = accountNode;
            nNode->left = nullptr;
            nNode->right = nullptr;
            curNode->right = nNode;
            return true;
        }
        else{
            return RecursiveInsert(accountNode, curNode->right);
        }
    }else{
        cout << "ERROR: Account " << accountNode->getAccountNum() << " is already open. Transaction refused." << endl;
        return false;
    }
}

//this function is to search for account as long as root not null and account number is root you have found account first case
//second case if root not null meaning tree not empty  if account number is freater you go to lesser side which is right
// if less then go right till you find at end ig not found meaninf meaning account not present 

bool BSTree::Retrieve(const int &accountNumber, Account *&accountObject) const{
    
    Node *temp = root;
    bool found= false;
    while (!found){
        if (temp != nullptr && accountNumber == temp->accountObject->getAccountNum()){
            found = true;
            accountObject = temp->accountObject;
            return found;
        }
        else if (temp != nullptr && accountNumber > temp->accountObject->getAccountNum()){
            temp = temp->right;
        }
        else if (temp != nullptr && accountNumber < temp->accountObject->getAccountNum()) {
            temp = temp->left;
        }
        else{
            found= true;
        }
    }
    cout << "ERROR: Account " << accountNumber << " not found. Transferal refused." << endl;
    return false;

}

//recursively diplaying account 
//base case: if node is null return meaning nothing to display
// else recursively go left and then right lastly print node 
void BSTree::Display(Node *node) const
{

    if (node == nullptr){
        return;
    }
    Display(node->left);
    Display(node->right);
    Account *X= node->accountObject;
    cout<< X->getLastName() << " " << X->getFirstName() << " Account ID: " << X->getAccountNum() << endl;
    for (int i = 0; i < 10; i++){
        cout << "  " << fundTypes[i] << ": $" << X->fundArray[i].getBalance() << endl;
    }
    cout<< "\n";
    
  
}


