/* Citation and Sources
Final Project Milestone 4
Module: TestPatient
Filename: TestPatient.cpp
Version 1.0
Author   Kao Hao Han
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "TestPatient.h"
using namespace std;



namespace seneca{
    static int nextTestTicket=1;
    //The default constructor passes the 
    //nextTestTicket global variable to the constructor of the base class Patient
    // and then it will increase the value of nextTestTicket global variable by one.
     TestPatient::TestPatient():Patient(nextTestTicket){
        nextTestTicket++;
     }
    char TestPatient::type()const{
        return 'C';
    }

    std::ostream& TestPatient::write(std::ostream& os) const{
        //make sure cout 
        if(&os==&cout ){
            os<<"Contagion TEST"<< endl;
        }
         Patient::write(os);
        return os;

     }
    
    std::istream& TestPatient::read(std::istream& is){
        Patient::read(is);
        if(&is!=&cin){
            nextTestTicket=number()+1;
        }
        return is;
    }
    TestPatient::~TestPatient(){};
}
