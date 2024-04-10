/* Citation and Sources
Final Project Milestone 4
Module: IOAble
Filename: TriagePatient.h
Version 1.0
Author   Kao Hao Han
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_TRIAGEPATIENT_H_H
#define SENECA_TRIAGEPATIENT_H_H
#include "IOAble.h"
#include "Patient.h"
#include <iostream>
#define MAX_SYMPTOMS_LENGTH 512

namespace seneca {

class TriagePatient : public Patient {
  char *m_symptoms = nullptr;

public:
  TriagePatient();
  ~TriagePatient();
  void setSym(const char *s);
  char type() const;
  std::ostream &write(std::ostream &os = std::cout) const;
  std::istream &read(std::istream &is = std::cin);
};
} // namespace seneca

#endif
