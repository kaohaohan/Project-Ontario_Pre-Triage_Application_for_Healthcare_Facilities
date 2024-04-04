/* Citation and Sources
Final Project Milestone 1
Module: Time
Filename: Time.cpp
Version 1.0
Author Hao Han Kao
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include "Utils.h"
#include <cstdlib>
using namespace std;

namespace seneca {
    Time& Time::reset(){
        int mins= U.getTime();
        m_mins =mins;
        return *this;
    }
    Time::Time(unsigned int min){
       m_mins =min;

    }
    //This method writes the time into ostream in the HH:MM format. 
    //If the hours or minutes are single-digit numbers, it pads them with a leading zero.
    // For example, it formats the times as 03:02, 16:55, and 234:06
    std::ostream& Time::write(std::ostream& ostr) const{
        
        int hours =m_mins/60;
        //find reminder...
        int mins =m_mins% 60;
        //display
        ostr.width(2);
        ostr.fill('0');
        ostr<< hours << ':';
        ostr.width(2);
        ostr<< mins;
        return ostr;
    }

    std::istream& Time::read(std::istream& istr ){
        //Reads the integer for the hours using istream.
        //Check the next character and verifies if it is : and discards is. 
        //If it is not, it sets the istream object to a failure state by executing the method: istr.setstate(ios::failbit);.
        //Reads the integer for the minutes using istream.
        int hours;
        istr >> hours;
        int mins;
        bool readSuccessful=false;
        //判斷讀hours 
        if (istr){
            // next character is : 
            if (istr.peek()==':'){
                istr.get();
                istr >> mins;
                if (istr){
                    m_mins =hours*60+mins;
                    readSuccessful=true;
                }
            }
        }
        if(!readSuccessful){
            istr.setstate(ios::failbit);
        }
        return istr;
    }
    
    Time::operator unsigned int()const{
        //This operator overloads the cast to unsigned int for the Time class. 
        //If a Time object is cast to an unsigned integer, 
        //it will return the number of minutes held in the object.
        return m_mins;
    }
     Time& Time::operator*= (int val){
        //This operator overloads the multiplication assignment *= for the Time class. It multiplies the number of minutes held in the Time object by val, 
        //then returns a reference to the current object.
        m_mins *=val;
        return *this;
     }
     Time& Time::operator-= (const Time& D){
        int result =m_mins-D.m_mins;
        if (result<0){
            result+=24*60;
            
        }
        m_mins =result;
        return *this;
     }

     Time Time::operator-(const Time& T)const{
        int result =m_mins-T.m_mins;

        if (result<0){
            result+=24*60;
            
        }

        return Time(result);
     
     }
    std::ostream &operator<<(std::ostream &ostr, const Time &t){
        return t.write(ostr);
     }

    std::istream &operator>>(std::istream &istr, Time &t){
        return t.read(istr);
    }
    
} 