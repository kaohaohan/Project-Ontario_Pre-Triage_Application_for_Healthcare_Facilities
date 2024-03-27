/* Citation and Sources
Final Project Milestone 1
Module: IOAble
Filename:IOAble
Version 1.0
Author Hao Han Kao
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECALOABLE_H
#define SENECALOABLE_H
#include <iostream>

namespace seneca{
    class IOAble{
        public: 
            virtual std::ostream& write(std::ostream& ostr= std::cout) const=0;
            virtual std::istream& read(std::istream& istr=std::cin)=0;
            virtual ~IOAble(){};
    };
    
    std::ostream& operator<<(std::ostream& ostr, const IOAble& ioable);
    std::istream& operator>>(std::istream& istr, IOAble& ioable);       
}
#endif