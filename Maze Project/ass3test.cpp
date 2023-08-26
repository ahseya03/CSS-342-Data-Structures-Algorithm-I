
#include <iostream>
#include <fstream>

#include "Maze.h"
#include "Creature.h"
using namespace std;
void test1() {
    
    Maze M1("maze1.txt");
    Creature C1(4, 4);
    cout<< "File name: "<<"maze1.txt"<<endl;
    
    cout << "Path taken: " << C1.Solve(M1) << endl;
    cout << M1 << endl;

    Maze M2("maze1.txt");
    Creature C2(1, 18);
    cout << "Path taken: " << C2.Solve(M2) << endl;
    cout << M2 << endl;

    Maze M3("maze0.txt");
    Creature C3(5, 20);
    cout<< "File name: "<<"maze0.txt"<<endl;
    cout << "Path taken: " << C3.Solve(M3) << endl;
    cout << M3 << endl;

    Maze M4("maze4.txt");
    Creature C4(1, 1);
    cout<< "File name: "<<"maze4.txt"<<endl;
    cout << "Path taken: " << C4.Solve(M4) << endl;
    cout << M4 << endl;

    Maze M5("maze4.txt");
    Creature C5(3, 5);
    
    cout << "Path taken: " << C5.Solve(M5) << endl;
    cout << M5 << endl;
    Maze M6("maze5.txt");
    Creature C6(7, 19);
    cout<< "File name: "<<"maze5.txt"<<endl;
    cout << "Path taken: " << C6.Solve(M6) << endl;
    cout << M6 << endl;
    Maze M7("maze5.txt");
    Creature C7(20, 1);
    cout << "Path taken: " << C7.Solve(M7) << endl;
    cout << M7 << endl;
    // File does not Exist test
    Maze M8("maze88.txt");
    Creature C8(20, 1);
    
    cout<< "File name: "<<"maze8.txt"<<endl;
    cout << "Path taken: " << C8.Solve(M8) << endl;
    cout << M8 << endl;
    Maze M9("maze7.txt");
    Creature C9(1, 2);
    cout<< "File name: "<<"maze7.txt"<<endl;
    cout << "Path taken: " << C9.Solve(M9) << endl;
    cout << M9 << endl;
    Maze M10("maze7.txt");
   
    Creature C10(1, 3);
    cout << "Path taken: " << C10.Solve(M10) << endl;
    cout << M10 << endl;
    // testing extremely large maze
    Maze M11("maze8.txt");
    Creature C11(1, 3);
    cout<< "File name: "<<"maze8.txt"<<endl;
    cout << "Path taken: " << C11.Solve(M11) << endl;
    cout << M11<< endl;
   
    
    

    

}
int main() {
    test1();
    cout << "Congratulations, You have successfully completed Level 1 of this Maze!!!" << endl;
    return 0;
}

