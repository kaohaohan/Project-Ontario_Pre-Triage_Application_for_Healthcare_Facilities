
#ifndef SENECA_TICKET_H_
#define SENECA_TICKET_H_
#include "IOAble.h"
#include "Time.h"
#include <iostream>
namespace seneca {
class Ticket : public IOAble {
  Time m_time;
  int m_number;

public:
  Ticket();
  Ticket(int number);
  Time time() const;
  int number() const;
  void resetTime();
  std::ostream &write(std::ostream &ostr) const;
  std::istream &read(std::istream &istr);
};
} // namespace seneca
#endif // !SENECA_TICKET_H_
