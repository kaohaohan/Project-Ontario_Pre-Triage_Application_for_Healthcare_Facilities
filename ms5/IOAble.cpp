/* Citation and Sources
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author   Kao Hao Han
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "IOAble.h"
#include <iostream>

namespace seneca {
std::ostream &operator<<(std::ostream &os, const IOAble &obj) {
  return obj.write(os);
}

std::istream &operator>>(std::istream &is, IOAble &obj) { return obj.read(is); }

} // namespace seneca
