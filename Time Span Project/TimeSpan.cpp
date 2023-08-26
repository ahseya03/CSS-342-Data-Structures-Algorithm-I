// TimeSpan Assigment 2
// Instructor: Professor Kalmin
// Created by Ayesha Mahmood
// Date: January 23, 2023

// iostream header is part of the input output library , used to insert data into stream output 
// or extract data from input this header will help support to use ostream overload to insert
// data into stream output.
#include <iostream>

// Iomanip library helps manipulate the output od c++ programs. For this program we will use setw() &
//setfill() manipulators
#include <iomanip>

// including the TimeSpan.h header file that has definitions  to TimeSpan.cpp which has implentations
#include "TimeSpan.h"

//means we use the namespace named std. “std” is an abbreviation for standard. 
using namespace std;

// this method converts hours, minutes and seconds all into second 
// first we use convert hour into seconds i.e (hour*3600) , minutes into second i.e. (minutes * 60) , and we have our second
// now we add all together and we distributes   to hour, minutes, and seconds using the formula:
// hour would be total Seconds divided by 3600 as dividing by 3600 is ratio for seconds to hour
//then I create tempHour which will hold left over remider after dividing the hour 
// minutes will be the remainder left from hours divided by 60
//then seconds will be remainder of what is remained after diving tempHour by 60 for minutes 
//In other word tempHour modulus 60
//then returns reference to object "this"


TimeSpan& TimeSpan::simplifyTime() {

    int totalSeconds = (hour * 3600) + (minutes * 60) + seconds;
    hour = int(totalSeconds / 3600);
    int tempHour = totalSeconds % 3600;
    minutes =  tempHour / 60;
    seconds = tempHour % 60;
           

    return *this;

   
}

// function that converts hour minutes and seconds to seconds then
// adds and  calculates total time in seconds 
int TimeSpan::totalTime() const{

    return seconds + (minutes*60) +(hour*3600);
}
// Initialization of paramaterized Constructor
//takes in hour minutes and secconds as double
// calling simplifyTime to make time in acceptable range
TimeSpan::TimeSpan(double hour, double minutes, double seconds){
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;

    simplifyTime();
    

}

 //implementation of overloaded addition assigment operator which take t reference which is a const reference to another object
 //adds to member variable
 //then simplifes and then returns ref to the object using this*
TimeSpan& TimeSpan :: operator += (const TimeSpan &t)
{
    
    hour += t.hour;
    minutes += t.minutes;
    seconds += t.seconds;
    simplifyTime();
    return *this;
}
 //implementation of overloaded addition operation which take creates time Object
 //supports addition with member variable
 //then simplifes and then returns object
TimeSpan TimeSpan :: operator + (const TimeSpan &t) const
{
    TimeSpan time;
    time.hour = hour+ t.hour;
    time.minutes = minutes + t.minutes;
    time.seconds = seconds + t.seconds;
    time.simplifyTime();
    return time;
}
 //implementation of overloaded subtraction assigment operator which take t reference which is a const reference to another object
 //subtracts to member variable
 //then simplifes and then returns ref to the object using this*
TimeSpan& TimeSpan :: operator -= (const TimeSpan &t)
{
    hour -= t.hour;
    minutes -= t.minutes;
    seconds -= t.seconds;
    simplifyTime();
    return *this;
}
 //implementation of subtraction operation which take creates time Object
 //supports subtraction with member variable
 //then simplifes and then returns object


TimeSpan TimeSpan :: operator -(const TimeSpan &t) const
{
    TimeSpan time;
    time.hour= hour - t.hour;
    time.minutes = minutes - t.minutes;
    time.seconds = seconds - t.seconds;
    time.simplifyTime();
    return time;
}
//creates time object. t.hour , t.minute. time.seconds are  referred to as "this" 
//upon which the multiplication is done by  number is passed in
//supports multiplication of number passed in with the hour minutes and seconds 
//calls simplify time to simplify
//then returns the time object
TimeSpan TimeSpan :: operator*(int number) const {
    TimeSpan time;
    time.hour = hour * number;
    time.minutes = minutes * number;
    time.seconds = seconds * number;
    
    time.simplifyTime();
    return time;
    
}
//we are getting this total time in second of "this" along with the corresponding member variables of t object input total time in seconds.
//if they equal return true else false
bool TimeSpan::operator==(const TimeSpan &t) const {
    
    if(this->totalTime()==t.totalTime()){
        return true;
    }
    else{
        return false;
    }
}
//we are getting this total time in second of "this" along with the corresponding member variables of t object input total time in seconds.
//if they  not equal return true else false
bool TimeSpan::operator!=(const TimeSpan &t) const {
      if(this->totalTime()!=t.totalTime()){
        return true;
    }
    else{
        return false;
    }
}
//we are getting this total time in second of "this" along with the corresponding member variables of t object input total time in seconds.
//if this greater return true else false
bool TimeSpan::operator>(const TimeSpan &t) const {
    if(this->totalTime()>t.totalTime()){
        return true;
    }
    else{
        return false;
    }
}

//we are getting this total time in second of "this" along with the corresponding member variables of t object input total time in seconds.
//if this less return true else false

bool TimeSpan::operator<(const TimeSpan &t) const {
    if(this->totalTime()<t.totalTime()){
        return true;
    }
    else{
        return false;
    }
}

//we are getting this total time in second of "this" along with the corresponding member variables of t object input total time in seconds.
//if this greater or equal return true else false
bool TimeSpan::operator>=(const TimeSpan &t) const {
    if(this->totalTime()>=t.totalTime()){
        return true;
    }
    else{
        return false;
    }
}
//we are getting this total time in second of "this" along with the corresponding member variables of t object input total time in seconds.
//if this less or equal return true else false
bool TimeSpan::operator<=(const TimeSpan &t) const {
    if(this->totalTime()<=t.totalTime()){
        return true;
    }
    else{
        return false;
    }
}

 // this ostream operator will format using setw and setfill from library iomanip we imported,
 //if either hour minute or second is negative we will do absolute value for all and print - before hour
 //if seconds or minutes negative then absolute value of  second and minute we will print and print - before hour
 //else case if it's postive we leave it as it is
 // this is done for formatting
 //set w() setfill() - setw ensures width always 2 and set fills fills it with 0's
 //The overloaded operator returns a reference to the original ostream object, which means you can combine insertions
 
 ostream& operator<<(ostream &outStream, const TimeSpan &t) {
     if(t.hour < 0 || t.minutes < 0 || t.seconds < 0) 
     {
         outStream << "-" << abs(t.hour) << ":" << setw(2) << setfill('0') <<
         abs(t.minutes) << ":" << setw(2) << setfill('0') << abs(t.seconds);
         return outStream;
    }
    else if(t.seconds < 0 || t.minutes < 0) 
    {
        outStream << "-" << t.hour << ":" << setw(2) << setfill('0') <<
        abs(t.minutes) << ":" << setw(2) << setfill('0') << abs(t.seconds);
        return outStream;
    }
    else{
        outStream << t.hour << ":" << setw(2) << setfill('0') <<
        t.minutes << ":" << setw(2) << setfill('0') << t.seconds;
        return outStream;
    }
 }