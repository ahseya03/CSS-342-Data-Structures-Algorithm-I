//Created by Ayesha Mahmood
// CSS 342 Assigment 4 : SKIPLIST 
// Instructor: Professor Kalmin
// Date: Feb 25, 2023

#include "SkipList.h"
#include <iostream>
#include <climits>
#include <cassert>
#include <cstdlib>
#include <stdexcept>

using namespace std;


SkipList::SkipList(int depth) {
    //first check if depth greater than 0 cause it can't be less than 0
    //if less than 0 than print error message and terminate 
    if(depth<0){
       cout<<"Depth cannot be less than 0"<<endl;
       exit(0);
    }
    // if depth is greater 
    if(depth>0){
        this->depth= depth;
        //creating new SNode*[depth] (i.e array of pointers pointing to the Object Snode) dynamically for the front guards of the levels
        frontGuards = new SNode*[depth];
        //creating new SNode*[depth] (i.e array of pointers pointing to the Object Snode) dynamically for the rear guards of the levels
        rearGuards = new SNode *[depth];
         for (int i = 0; i < depth; i++) {
            frontGuards[i] = new SNode(INT_MIN);
            rearGuards[i] = new SNode(INT_MAX);
            
            frontGuards[i]->next = rearGuards[i];
            frontGuards[i]->prev = nullptr;
            rearGuards[i]->prev = frontGuards[i];
            rearGuards[i]->next = nullptr;
            //they point to each other as w
         }
          // this for loop links all of the front and rear guards to each other
        for (int i = 0; i < depth; i++){
            // linking if we are  base level
            if(i == 0){
            frontGuards[i]->upLevel = frontGuards[i+1];
            rearGuards[i]->upLevel = rearGuards[i+1];
            frontGuards[i]->downLevel = nullptr;
            rearGuards[i]->downLevel = nullptr;
            }
            //linking if we are on top level
            else if(i == depth - 1){
            frontGuards[i]->upLevel = nullptr;
            rearGuards[i]->upLevel = nullptr;
            frontGuards[i]->downLevel = frontGuards[i-1];
            rearGuards[i]->downLevel = rearGuards[i-1];
            }
            //linking we are in middle somewhere
            else {
            frontGuards[i]->upLevel = frontGuards[i+1];
            rearGuards[i]->upLevel = rearGuards[i+1];
            frontGuards[i]->downLevel = frontGuards[i-1];
            rearGuards[i]->downLevel = rearGuards[i-1];
            }

        }
    }

}
// Destructor for Skip list
// deleting individial nodes 
SkipList::~SkipList()
{
    for (int i = 0; i < depth; i++){
        SNode *current = frontGuards[i];

        while(current!=nullptr){
            SNode* temp = current->next;
            delete current;
            current = temp;
        }
    }
    delete[]rearGuards;
    delete[]frontGuards;
    
}


// boolean function that returns true if value is found, false otherwise
bool SkipList::Contains(int data) {

    //we are initializing pointer called current for top level (depth-1) gives the maximum top level
    //so we are basically initializing the current pointer node to point  the front guard of 
    //maximum top level
    //we do not want to search from level 0 since it will be O(n)
    //so Instead we start from top front guard

    //temp node that point to frontGuard of top level
    SNode *temp = frontGuards[depth - 1];
    // initializing number of levels equal to the max number of levels there are
    int numberOflevels = depth-1;
    //iteratinf from numberOfLevels(i.e the top one to search and decrementting by level till we finally find
    //value)
    for (int i = numberOflevels; i >= 0; i--) {
    ///initialize temp to be top levels front guard
        temp = frontGuards[i];
    //while temp not equal to nullptr(meaning there are still nodes)and we haven't reached bottom
    while (temp != nullptr && numberOflevels > -1) {
    // if value of next node in level we on equals value return true
      if (temp->next->data == data) {
        return true;
    //if less keep moving  right toward higher value find
      } else if (temp->next->data< data) {
        temp = temp->next;
      } else {
        //else set temp node to be one level downLevel fron current nosw
        temp = temp->downLevel;
      }
    }
  }//end of the loop that means value is not in the skiplist
  return false;
}

bool SkipList::Add(int data)
{   
    // if data is equal to front guard MIN can't add
    if(data==INT_MIN){
        cout<<"Cannot add INT_MIN as value"<<endl;
        return false;
    }
    // if data is equal to front guard MAX can't add
    if(data==INT_MAX){
        cout<<"Cannot add INT_MAX as value"<<endl;
        return false;
    }
    // if data is greater than rear guard cannot add 
    if(data>INT_MAX){
        cout<<"Cannot add value greater than guard: Error exceeded limit"<<endl;
        return false;
    }    
    //if data is less than front guard cannot add
    if(data<INT_MIN){
        cout<<"Cannot add value less than guard"<<endl;
        return false;
    }
    //if data is present cannot add duplicates
    if (Contains(data)){
        return false;
    }
    //setting nextNode to start from level 0  front Guard
    SNode* nextNode = frontGuards[0]->next;
    //as long as nextNode is not null ptr and is is less than data we advant the nexrNode 
    while (nextNode->next != nullptr && nextNode->data < data)
    {
        nextNode = nextNode->next;
    }
    //we create newNode  and give it data 
    SNode* newNode = new SNode(data);
    //calling addBefore() which will take care of connecting nodes together 
    // it will add newNode before the nextNode
    addBefore(newNode, nextNode);
    // intializing level tracker which will keep track of level we on 
    int levelTracker = 0;
    // intializing bool goUpOrNot which whill depend on coin toss
    bool goUpOrNot = alsoHigher();
    // if coin toss true and while we not on top level
    while (goUpOrNot == true && levelTracker<depth-1)
    {
        //create a node called newUpNode give it the data 
        SNode* newUpNode = new SNode(data);
        // linking the UpNode with downLevel and assigning it as newNode
        newUpNode->downLevel = newNode;
        //linking newNode with upLevel and assigning it as newUpNode
        newNode->upLevel = newUpNode;
        //making curNode = to newNode
        SNode* curNode = newNode;
        //finding where we can place curNode in upper level
        while (curNode->prev->upLevel == nullptr && curNode != nullptr)
        {
            curNode = curNode->prev;
        }
        curNode = curNode->prev->upLevel->next;
        //adding it in upper level
        addBefore(newUpNode, curNode);
        newNode = newUpNode;
        //increment level Tracker  after adding in upper level
        levelTracker++;
        //do coing toss agaan to determine if you can go up again 
        goUpOrNot = alsoHigher();
        
    }
    return true;
    
}

void SkipList::addBefore(SNode *newNode, SNode *nextNode)
{
     // this will link to note in front
     newNode->next = nextNode;
    // this will link  prev to node behind
    newNode->prev = nextNode->prev;
    // this will Link node that is  in back to new node if back not nullptr
    if (nextNode->prev != nullptr){
    nextNode->prev->next = newNode;
    }
    // this will link node in front to new node
    nextNode->prev= newNode;
}

bool SkipList::Remove(int data) {
    // if skiplist does not contain data just return false
    if (!Contains(data)){
        return false;
    }
  //intialiazing temp Node
  SNode* temp;
  // this for loops that will iterate from the max level
  // and checks if the next data is greater than the current data then advance pointer 
  for (int i = depth - 1; i >=0; i--){
    SNode* curr = frontGuards[i];
    while(data > curr->next->data){
      curr = curr->next;
    }
    // if the data is == to data to remove we link next pinter and the pointet before to another
    // then we will store one that is in bottom 
    // then we set all pointer to null
    // and finally delete the node
    // then you go to the node below it and repeat til you get to the first level and then it just deletes it  
    // then we go to node below, keep doing till we hit first level and then delete it  
    if (curr->next->data == data){
      curr = curr->next;
      temp = curr->downLevel;
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      curr->next = nullptr;
      curr->prev = nullptr;
      curr->downLevel = nullptr;
      curr->upLevel = nullptr;
      delete curr;
      curr = temp;
    }
    else if (i != 0) {
      curr = curr->downLevel;
    }
    else{
        return false;
    }
  }
  return true; 
}


// Generating random number to determine if we can go up a level
bool SkipList::alsoHigher() const
{ 
    return rand() % 2 == 1;
}

 ostream &operator<<(ostream &out, const SkipList &list)
{
     //iterating through skiplist it in a reverse manner 
    for (int i = list.depth - 1; i > -1; i--)
    {
        //making head point to front guard of top level
        SkipList::SNode *front = list.frontGuards[i];
        //making rear  point to rear guard of top level
        SkipList::SNode *back = list.rearGuards[i];
        // printing level title
       out << "Level " << i<<": " ;
        // going through a level at a time as long as head does not reach rear data 
        //print out  data 
        // and advance head pointer till the end
        while (front->data != back->data)
        {
            out << front->data << ", ";
            front = front->next;
        }
        //printing the last node seperate for each level on same line
        out << back->data<<endl;
    }
    
    return out;
}
