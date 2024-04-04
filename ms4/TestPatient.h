/* Citation and Sources
Final Project Milestone 4
Module: TestPatient
Filename: TestPatient.h
Version 1.0
Author   Kao Hao Han
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_TESTPATIENT_H_
#define SENECA_TESTPATIENT_H_
#include <iostream>
#include "IOAble.h"
#include "Patient.h"

namespace seneca{
    
    class TestPatient: public Patient{
        public:
        TestPatient();
        ~TestPatient();

        char type()const ;


        std::ostream& write(std::ostream& os=std::cout) const;

    
        std::istream& read(std::istream& is=std::cin);  

    };
}

#endif 
