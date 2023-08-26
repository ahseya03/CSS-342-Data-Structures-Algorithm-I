#include <iostream>
#include "SkipList.h"
#include <cassert>
#include <climits>

using namespace std;


//Testing with constructor
void T1() {
    
    
    SkipList skip(3);
    for (int i = 0; i < 10; ++i) {
        int number = rand() % 2;
        skip.Add(number);
        cout << "After adding " << number << endl;
        cout << skip << endl;
    }
}
//Printing out empty guards
void T2(){
    
    SkipList skip(2);
    cout<<skip<<endl;
}
// Addition to List
void T3() {
    
    
    SkipList skip(3);
    
    
    skip.Add(1);
    skip.Add(2);
    skip.Add(-2);
    skip.Add(0);
    skip.Add(33);
    skip.Add(20);
    skip.Add(-88);
    skip.Add(29);
    skip.Add(21);
    cout<<skip<<endl;

    

    assert(skip.Contains(1));
    assert(skip.Contains(2));
    assert(skip.Contains(29));
    assert(skip.Contains(33));
    assert(!skip.Contains(91));

}

//Addition and Removal to List 
void T4() {
    
    SkipList skip(2);
    skip.Add(1);
    skip.Add(2);
    skip.Add(0);
    skip.Add(11);
    skip.Add(22);
    skip.Add(30);
    skip.Add(-8);
    skip.Add(-2);
    cout<<skip<<endl;
    skip.Remove(-2);
    cout<<"After removal of -2"<<endl;
    cout<<skip<<endl;
    
    
    
    assert(skip.Contains(2));
    assert(!skip.Contains(199));
    assert(skip.Contains(2));
    assert(!skip.Contains(392));
    
   
    
}
// Testing Addition of duplicates
void T5(){
    SkipList skip(1);
    skip.Add(4);
    skip.Add(4);
    skip.Add(4);
    cout<<skip<<endl;
}

// Edge case: Addition of INT_MAX and INT_MIN
void T6(){
    SkipList skip(3);
    skip.Add(INT_MAX);
    skip.Add(INT_MIN);
    cout<<skip<<endl;
}

//Test for negative level
void T7(){
    SkipList skip(-1);
    cout<<skip<<endl;
}

int main() {
    T1();
    T2();
    T3();
    T4();
    T5();
    T6();
    T7();
    

    return 0;
}