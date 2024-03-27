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

#define _CRT_SECURE_NO_WARNINGS
#include "IOAble.h"
#include <cstdlib>
using namespace std;

namespace seneca{
    
    std::ostream& operator<<(std::ostream& ostr, const IOAble& ioable){
        ioable.write(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, IOAble& ioable){
        ioable.read(istr);
        return istr;
    }
    
}