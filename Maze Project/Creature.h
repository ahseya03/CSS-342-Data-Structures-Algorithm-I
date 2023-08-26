//Created By Ayesha Mahmood
// Instructor: Professor Kalmin
// Date: February 11, 2023

#ifndef CREATURE_H
#define CREATURE_H
#include <iostream> 
#include "Maze.h" 
using namespace std;
//class definition
class Creature {
  //friend stream operator that takes in creature object that will help us print out the paths creature taken
friend ostream &operator<<(ostream &out, const Creature &creature);
// public methods and variables
public:
    //This is the creature constructor that will take in the rows and columms
    Creature(int row, int column);
    //This is bool functions that return sucess as true or false and will recursively go to North if sucess true else try other directions if fails backtrack to orginal location and remove it from path( more detail in cpp!)
    bool goNorth(Maze &maze, string &path);
     //This is bool functions that return sucess as true or false and will recursively go to East  if sucess true else try other directions if fails backtrack to orginal location and remove it from path
    bool goEast(Maze &maze, string &path); 
    //This is bool functions that return sucess as true or false and will recursively go to West if sucess true else try other directions if fails backtrack to orginal location and remove it from path
    bool goWest(Maze &maze, string &path); 
    
    //This is bool functions that return sucess as true or false and will recursively go to South if sucess true else try other directions if fails backtrack to orginal location and remove it from path
    bool goSouth(Maze &maze, string &path);
    //mmain part of program that will take maze object and help in solving  maze if sucess true else try other directions if fails backtrack to orginal location and remove it from path
    string Solve(Maze &maze);
    //integer variables for row, and column
    int row, column;
// private methods and variables
private:
    //string variable to append different paths
    string path;
    
 };
#endif