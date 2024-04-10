/* Citation and Sources
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
Version 1.0
Author   Kao Hao Han
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_IOABLE_H_
#define SENECA_IOABLE_H_

#include <iostream>

namespace seneca {
class IOAble {
public:
  virtual std::ostream &write(std::ostream &os) const = 0;
  virtual std::istream &read(std::istream &is) = 0;
  friend std::ostream &operator<<(std::ostream &os, const IOAble &obj);
  friend std::istream &operator>>(std::istream &is, IOAble &obj);
};

} // namespace seneca

#endif