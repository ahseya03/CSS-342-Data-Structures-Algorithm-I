//Created By Ayesha Mahmood
// Instructor: Professor Kalmin
// Date: February 11, 2023

//including header file
#include "Creature.h"
//Declaration of variable name creature. this is type of object which we will use in program 
//we also declaring ostream which will aid in print the output using overloaded stream operator.
ostream &operator<<(ostream &out, const Creature &creature) {
    out <<"Creature row:" <<creature.row<< "Creature Column"<< creature.column ;
    return out;
}
// Here we have creature object which will be used to pass its row and column values
Creature::Creature(int row, int column) {
    this->row= row;
    this->column = column;
    
   
    
}
string Creature::Solve(Maze &maze)
{   

    // the the maze has to be well formed can't be over 100 and less than 2 else it won't be a well formed maze so we need to take that into account as well

    
    // we first start by checking if the creature is not within bounds 
    // if it is not within bounds we just return X because it can't go anywhere 
    if (!maze.CreatureInBounds(row, column))
    {
        return "X";
    }
    // // Next we check to see if creature is at wall if it is at wall we simply return X cause creature can't be at wall
    if (maze.IsWall(row, column))
    {
        return "X";
    }
    //now we can sucessfully mark it as initial point with "S" to denote starting point
    maze.MarkAsInitialPoint(row,column);
    // if current location is  Exit return creature is at exit
    if(maze.IsExit(row, column)){
        return "Creature is already at his final destination";
    }
   
    //After this checks and if everything is good 
    
    // Then we try to go recursively in all for directions, North, East , South, and West
    goNorth(maze,path);
    goEast(maze,path);
    goSouth(maze,path);
    goWest(maze,path);
    // If the creature is at exit, and path is empty meaning it took 
    // no path that means it's already at its exit so do nothing
    if (maze.IsExit(row, column))
    { 
        if (path == "")
        {
            
        }
        // this is the case where it is at exit but path is not empty so you mark it as a path 
        maze.MarkAsPath(row, column);
        return path;
    }
    // This is else case where creature hasn't reached its destination so we mark currrent positions as visit 
    maze.MarkAsVisited(row, column);
    return "X";
}
//This idea was inspired by Carrano Book Pseusocode Chapter on


bool Creature::goNorth(Maze &maze, string &path) {
   // we start by declaring success as bool
    bool success;
    //if row-1 meaning the top one (i.e North is clear)
    if(maze.IsClear(row - 1, column)){
        // we move into north location
        row--;
        //mark it as path
        maze.MarkAsPath(row, column);
        //Add north to our path 
        path = path + "N";
        // If we are at exit now we return success as true 
        if(maze.IsExit(row, column)){
            success = true;
        }else{
            // If we have not succesfully reached we keep going and try in all 3 direction unless success
            //we try going north west and east but not south because you'll end up back into same spot
            //Call go north
            success = goNorth(maze,path);
            //If not sucessful
            if(!success){
                //Call go West
                success = goWest(maze,path);
                //If that is not succesful
                if(!success){
                    //call go East
                    success = goEast(maze,path);
                    // if nothing succesfull 
                    if(!success){
                        //mark as visited 
                       maze.MarkAsVisited(row, column);
                       //back track  to south
                        row++;
                        //after backtracking we remove the path from our path because it didnot give us path so it only goes
                        //in the visited not printed since it's not path
                        path.pop_back();
                    }
                }
            }
        }
    }else{ 
        //if north location is not clear then sucess is set  to false
        success = false;
    }
    //succesful
   return success;
}

bool Creature::goEast(Maze &maze,string &path) {

    // we start by declaring sucess as bool
    bool success;
    
    //if column+1 meaning the right one (i.e east is clear)
    if(maze.IsClear(row, column + 1)){
        //move to east
        column++;
        //mark east as path
        maze.MarkAsPath(row, column);
        //Add East to path
        path = path + "E";
        // If we are at exit now we return success as true
        if(maze.IsExit(row, column)){
            success = true;
        }else{
        // If we have not succesfully reached we keep going and try in all 3 direction unless success
         //we try going east,north,south but not west because you'll end up back into same spot
        
            success = goEast(maze,path);
            if(!success){
                success = goNorth(maze,path);
                if(!success){
                    success = goSouth(maze,path);
                    if(!success){
                        maze.MarkAsVisited(row, column);
                        column--;
                        //after backtracking we remove the path from our path because it didnot give us path so it only goes
                        //in the visited not printed since it's not path
                        path.pop_back();
                    }
                }
            }
        }
    }else{
        success = false;
    }
    return success;
}

bool Creature::goSouth(Maze &maze,string &path) {
    // we start by declaring success as bool
    bool success;
    //if row+1 meaning the down one (i.e south is clear)
    if(maze.IsClear(row+ 1, column)){
        //move to south
        row++;
        //mark as path
        maze.MarkAsPath(row, column);
        //Add South to Path
        path = path + "S";
        // if at exit make  success true
        if(maze.IsExit(row, column)){
            success = true;
        }else{
            // If we have not succesfully reached we keep going and try in all 3 direction unless success
         //we try going south, west, east but not north because you'll end up back into same spot
            success = goSouth(maze,path);
            if(!success){
                success = goWest(maze,path);
                if(!success){
                    success = goEast(maze,path);
                    // if nothing succesfull 
                    if(!success){
                        //mark as visited
                        maze.MarkAsVisited(row, column);
                        //backtrack to south again
                        row--;
                        //after backtracking we remove the path from our path because it didnot give us path so it only goes
                        //in the visited not printed since it's not path
                        path.pop_back();
                    }
                }
            }
        }
    }else{
        success = false;
    }
    return success;
}

bool Creature::goWest(Maze &maze,string &path) {
    // we start by declaring success as bool
    bool success;
    //if column-1 meaning the left one (i.e west is clear)
    if(maze.IsClear(row, column - 1)){
        //go west
        column--;
        //mark it as path
        maze.MarkAsPath(row, column);
        //add it to path string
        path = path + "W";
        // if at exist make success true
        
        if(maze.IsExit(row, column)){
            success = true;
        }else{
         // If we have not succesfully reached we keep going and try in all 3 direction unless success
         //we try going west, north, south but not eastbecause you'll end up back into same spot
            success = goWest(maze,path);
            if(!success){
                success = goNorth(maze,path);
                if(!success){
                    success = goSouth(maze,path);
                    // if nothing works then mark as visited
                    if(!success){
                        maze.MarkAsVisited(row, column);
                        //back track to west again
                        column++;
                        //after backtracking we remove the path from our path because it didnot give us path so it only goes
                        //in the visited not printed since it's not path
                        path.pop_back();
                    }
                }
            }
        }
    }else{
        success = false;
    }
    return success;
}