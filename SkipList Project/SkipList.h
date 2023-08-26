
//Created by Ayesha Mahmood
// CSS 342 Assigment 4 : SKIPLIST 
// Instructor: Professor Kalmin
// Date: Feb 25, 2023


#ifndef HW4_SKIPLIST_H
#define HW4_SKIPLIST_H

#include <iostream>


using namespace std;


class SkipList {
public:

    //explicit Skiplist constructor with default 1 depth 
    explicit SkipList(int depth = 1);
    //virtual destructor 
    virtual ~SkipList();
    // bool function for adding to skip list
    bool Add(int data);
    //bool function for removing data from skip list 
    bool Remove(int data);
    // bool function that check if data in list 
    bool Contains(int data);
    

    
   // declaring friend function operating which will help to print out list 
    friend ostream &operator<<(ostream &out, const SkipList &list);
    //private methods and data
private:

    //Node class with its public memeber 
    //has SNode pointer for previous , next node, up node, and down node 
    class SNode{
    public:
        int data;
        SNode *next;
        SNode *prev;
        SNode *upLevel;
        SNode *downLevel;

       //explicit constteuctors have one parameters
       // SNODE takes in the data 
        explicit SNode(int data){
            // intializing data name to be data
            this->data = data;
            //assigning next node to be null ptr
            next = nullptr;
            //assigning prev node to be null ptr
            prev = nullptr;
            //assigning upLevel node to be null ptr
            upLevel= nullptr;
            //assigning downLevel node to be null ptr 
            downLevel = nullptr;
        }
    };
    
    //intializing depth for skiplist data structor as int 
    int depth;
    // pointer for Front Guards
    SNode **frontGuards;
    //pointer to rear Guards
    SNode **rearGuards;

    //void function that takes in newNOde and adds before nextNode
    void addBefore(SNode *newNode, SNode *nextNode);
    //bool function that does coin toss and checks if you can go higher level up
    bool alsoHigher() const;
    //clear function
    void clear();
};


#endif //HW4_SKIPLIST_H
//coin toss