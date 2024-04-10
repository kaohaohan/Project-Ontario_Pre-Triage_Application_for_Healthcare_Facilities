/* Citation and Sources
Final Project Milestone 3
Module: Patients
Filename: Patient.h
Version 1.0
Author   Kao Hao Han
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_PATIENT_H_
#define SENECA_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"
#include <iostream>
namespace seneca {

const int MAX_NAME_LENGTH = 50;

class Patient : public IOAble {
  char *m_PatientName = nullptr;
  int m_ohipNum{};
  Ticket m_ticket;

public:
  void setOHIP(int ohipNum);
  void setName(char *patientName);
  Patient();
  Patient(int t);
  Patient(const Patient &);
  Patient &operator=(const Patient &p);
  virtual ~Patient();
  virtual char type() const = 0;

  bool operator==(const char c) const;
  bool operator==(const Patient &p) const;

  void setArrivalTime();

  Time time() const;
  int number() const;
  operator bool() const;
  operator const char *() const;

  std::ostream &write(std::ostream &os) const;
  std::istream &read(std::istream &is);
};

} // namespace seneca
#endif
