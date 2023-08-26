// TimeSpan Header File (Assigment 2)
// Instructor: Professor Kalmin
// Created by Ayesha Mahmood
// Date: January 23, 2023

// we use ifnded define to avoid including the header file more than once
#ifndef TIMESPAN
#define TIMESPAN
// iostream header is part of the input output library , used to insert data into stream output 
// or extract data from input this header will help support to use ostream overload to insert
// data into stream output.
#include <iostream>
#include <stdio.h>
//means we use the namespace named std. “std” is an abbreviation for standard. 
using namespace std;
// Class Name
class TimeSpan
{
    // declaration of friend function overloaded operator  that returns a reference to the original ostream object
    friend ostream& operator<<(ostream &outStream, const TimeSpan &time);
// private members  
private:
    //initialiation of private variables hours minutes, and seconds
    double hour;
    double minutes;
    double seconds;
    //initialiation of private function simplify that returns reference to object "this"
    TimeSpan& simplifyTime();
    
    
    
    
public:
    //initialization of constructor as default if input is not provided 
    explicit TimeSpan(double hour =0, double minutes =0, double seconds=0);
    
    // method totalTime that returns total time in second. means *this is const inside member function and does not alter
    //hour minutes seconds are this* they don't alter we just have seperate var. totaltime calculates totaltime in seconds using 
    //hour minutes, and seconds without altering and adding to totalSecond variable , return type is int
    int totalTime() const;
    

    // 12 operator overloads 
     //initialization of overloaded addition operation which take creates time Object
     //it will return a new instance of TimeSpan since new instance const at end
     //since current instance not being updated rather new instance created
    TimeSpan operator+(const TimeSpan &time) const;
    //implementation of subtraction operation which take creates time Object
    TimeSpan operator-(const TimeSpan &time) const;
    //function overload the * operator to multiply the Timespan

    TimeSpan operator*(int number) const;

    //initialization of overloaded addition assigment operator which take t reference 
    //which is a const reference to another object
    //no const at end returns the updated TimeSpan the function was called on.
    //since it return updated Timespan that means it being changed so no const at end
    TimeSpan& operator+=(const TimeSpan &time);

    TimeSpan operator=(const TimeSpan &time);
    //initialization of overloaded subtraction assigment operator which take t reference 
    //which is a const reference to another object
    TimeSpan& operator-=(const TimeSpan &time);
    //function to overload the == operator 
    //it checks wheter instance of TimeSpan the function was called on 
    //is equal to the instance of TimeSpan
    // time passed into the parameter of the function
    bool operator==(const TimeSpan &time) const;
    //function to overload the != operator 
    //it checks wheter instance of TimeSpan the function was called on 
    //is unequal to the instance of TimeSpan
    // time passed into the parameter of the function
    bool operator!=(const TimeSpan &time) const;
    //function to overload the == operator 
    //it checks wheter instance of TimeSpan the function was called on 
    //is greater than the instance of TimeSpan
    // time passed into the parameter of the function
    bool operator>(const TimeSpan &time) const;
     //function to overload the == operator 
    //it checks wheter instance of TimeSpan the function was called on 
    //is less than the instance of TimeSpan
    // time passed into the parameter of the function
    bool operator<(const TimeSpan &time) const;
     //function to overload the == operator 
    //it checks wheter instance of TimeSpan the function was called on 
    //is greater or equal to the instance of TimeSpan
    // time passed into the parameter of the function
    bool operator>=(const TimeSpan &time) const;
     //function to overload the == operator 
    //it checks wheter instance of TimeSpan the function was called on 
    //is less or equal to the instance of TimeSpan
    // time passed into the parameter of the function
    bool operator<=(const TimeSpan &time) const;
};//end class with " ; "

#endif