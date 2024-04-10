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
Time &Time::reset() {
  int mins = U.getTime();
  m_mins = mins;
  return *this;
}
Time::Time(unsigned int min) { m_mins = min; }

std::ostream &Time::write(std::ostream &ostr) const {
  int hours = m_mins / 60;
  int mins = m_mins % 60;

  ostr.width(2);
  ostr.fill('0');
  ostr << hours << ':';
  ostr.width(2);
  ostr << mins;
  return ostr;
}

std::istream &Time::read(std::istream &istr) {
  int hours;
  istr >> hours;
  int mins;
  bool readSuccessful = false;
  if (istr) {
    if (istr.peek() == ':') {
      istr.get();
      istr >> mins;
      if (istr) {
        m_mins = hours * 60 + mins;
        readSuccessful = true;
      }
    }
  }
  if (!readSuccessful) {
    istr.setstate(ios::failbit);
  }
  return istr;
}

Time::operator unsigned int() const { return m_mins; }
Time &Time::operator*=(int val) {
  m_mins *= val;
  return *this;
}

Time &Time::operator-=(const Time &D) {
  int result = m_mins - D.m_mins;
  if (result < 0) {
    result += 24 * 60;
  }
  m_mins = result;
  return *this;
}

Time Time::operator-(const Time &T) const {
  int result = m_mins - T.m_mins;

  if (result < 0) {
    result += 24 * 60;
  }

  return Time(result);
}
std::ostream &operator<<(std::ostream &ostr, const Time &t) {
  return t.write(ostr);
}

std::istream &operator>>(std::istream &istr, Time &t) { return t.read(istr); }

} // namespace seneca