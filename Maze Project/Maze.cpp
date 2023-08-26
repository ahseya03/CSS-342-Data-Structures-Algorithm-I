//Created By Ayesha Mahmood
// Instructor: Professor Kalmin
// Date: February 11, 2023

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Maze.h"
#include <string>
using namespace std;
// this is overloaded ostream operator which will print out mazee
ostream &operator<<(ostream &out, const Maze &maze) {
   //we iterate throught the rows
    for (int row=0; row < maze.heightOfMaze; row++) {
      //we iterate through the columns
        for (int column=0; column < maze.widthOfMaze; column++) {
         // store output in a 2D Array 
            out << maze.Field[row][column];
        }
        //this is to add a new line after each roew
        out << endl;
    }// we print whole thing out to stream
    return out;
}
// Maze Constructor which takes in file name
Maze::Maze(string mazeFile){
//defining input file stream called myFile
   ifstream myFile;
   //open file 
   myFile.open(mazeFile);
   //if file not exist print "file does not exist"
   if(!myFile){
      cout<<"file does not exist"<<endl;
   }
   
      
   // else read in the first 2 widthOfMaze and heightOfMaze and second line's first two i.e the  rowExit and columnExit
   myFile>>widthOfMaze>>heightOfMaze;
   myFile>>rowExit>>columnExit;
   
   
  
   //reading line which is string ""and storing them into line 
   getline(myFile,line);

   //iteratue throw  row and colum 
   for(int row = 0; row<heightOfMaze;row++){
      for(int column =0; column<widthOfMaze; column++){
         //reading in numbers of rows and colums from file and storing it in Size of 2Darray
      myFile.get(Field[row][column]);
   }
      //reading line which is string ""and storing them into line 
   getline(myFile,line);
   
}
   if(Maze::widthOfMaze>101||Maze::heightOfMaze>101||Maze::widthOfMaze<2||Maze::heightOfMaze<2){
      cout<<"No path taken, this is Not a well formed Maze"<<endl;
      
   }

//always good habit to close file
myFile.close();
}

// bool function for IsClear 
//If empty string meaning it's clear
//so return true 
//else false
bool Maze::IsClear(int row, int column) const {
    if(Field[row][column] == ' '){
        return true;
    }
    return false;
}
//bool function for Is Wall

// bool Maze::IsWall(int row, int column)const{
   
//    if (Field[row][column]=='x'||Field[row][column]=='X'||Field[row][column]=='#'||Field[row][column]=='-'){
//       return true;
//    }
//    return false;

// }

// In case maze has any other ASCII characters besides "+" and "*"
bool Maze::IsWall(int row, int column) const {
    if(!IsClear(row, column) && !IsExit(row, column) &&
    !IsPath(row, column) && !IsVisited(row, column)){

        return true;
    }
    return false;
}
//Bool function to check if it is a path denoted with "*"sign
bool Maze::IsPath(int row, int column)const{
   if(Field[row][column]== '*'){
      return true;
   }
   return false;

}
//Bool function to check if it is a path visited denoted with "*"sign
bool Maze::IsVisited(int row, int column)const{
   if(Field[row][column]=='+'){
      return true;
   }
   return false;
}
//void Function to mark As path with "*" sign
void Maze::MarkAsPath(int row, int column){
   Field[row][column]='*';
}
//void Function to mark path as visited with "+" sign
void Maze::MarkAsVisited(int row, int column){
   Field[row][column]='+';
}
//Void function to mark as initial point from where creature starts
// I am using "S" to denote starting point for easier tracking
void Maze::MarkAsInitialPoint(int row, int column){
   Field[row][column]= 'S';
}
// If crreature row and column is equal to rowExit and ColumnExit,
// means creature at destination so return true
//else return false
bool Maze::IsExit(int row, int column) const{
   if(row == rowExit &&  column==columnExit){
      return true;
   }
   return false;
}
// this function is to check if creature is in bounds of maze
//reture true if in bounds else false
bool Maze::CreatureInBounds(int row, int column)const{
   if(row<Maze::heightOfMaze||column<Maze::widthOfMaze||row>0||column>0){
      return true;
   }
   return false;
}










