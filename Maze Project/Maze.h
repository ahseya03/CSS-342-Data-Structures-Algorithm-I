//Created By Ayesha Mahmood
// Instructor: Professor Kalmin
// Date: February 11, 2023

#ifndef MAZE_H 
#define MAZE_H

#include <iostream> 
using namespace std; 
//Class Definition
class Maze {
//friend stream operator that takes in maze object and enable to print out the maze
friend ostream &operator<<(ostream &out, const Maze &maze);

//public functions and variables
public:
   //Maze constructor that will take in file name 
    explicit Maze(string mazeFile = "");
   //  This is a boolean function that takes in  give row, and column and sees if it is clear
    bool IsClear(int row, int column) const;
    // This is a boolean function that takes in row and column and see if there is a wall
    bool IsWall(int row, int column) const;
    //boolean function to check if it is a path 
    bool IsPath(int row, int column) const; 
    //boolean function to check if given row and column is visited
    bool IsVisited(int row, int column) const; 
    // boolean function to check if you are at exit
    bool IsExit(int row, int column) const;
    // void function that marks as path using "*"
    void MarkAsPath(int row, int column);
    //Additional check I added marking first point of creature as "S" meaning start point to trace easily how creature
    // is gonig in the output
    void MarkAsInitialPoint(int row, int column);
    //Void fucntion that marks as visited with the charateer " + " those are not your final path only ones you have visited and backtracked from
    void MarkAsVisited(int row, int column);
    // This is to checkk if creature is within the bounds of maze 
    bool CreatureInBounds(int row, int column) const;
   
    // variable for width and height of maze 
    int widthOfMaze, heightOfMaze;

//private
 private:
   // exit row and exit column number position
    int rowExit, columnExit; 
    //setting Maximum Number we can have in  Array 
    const static int MAX_SIZE =100;
    // 2D Array that can be 100 by 100
    char Field[MAX_SIZE][MAX_SIZE];
    // this string line 
    string line; 
    };
#endif