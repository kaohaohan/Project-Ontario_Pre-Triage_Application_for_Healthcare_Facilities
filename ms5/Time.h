/* Citation and Sources
Final Project Milestone 1
Module: Time
Filename: Time.h
Version 1.0
Author Hao Han Kao
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECATIME_H
#define SENECATIME_H
#include <iostream>
namespace seneca {
class Time {
  int m_mins;

public:
  Time &reset();
  Time(unsigned int min = 0u);

  operator unsigned int() const;
  Time &operator*=(int val);
  Time &operator-=(const Time &D);
  Time operator-(const Time &T) const;

  std::ostream &write(std::ostream &ostr = std::cout) const;
  std::istream &read(std::istream &istr = std::cin);
  friend std::ostream &operator<<(std::ostream &ostr, const Time &t);
  friend std::istream &operator>>(std::istream &istr, Time &t);
};

} // namespace seneca
#endif