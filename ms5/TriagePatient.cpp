/* Citation and Sources
Final Project Milestone 4
Module: IOAble
Filename: TriagePatient.cpp
Version 1.0
Author   Kao Hao Han
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca {
static int nextTriageTicket = 1;

TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
  nextTriageTicket++;
}

void TriagePatient::setSym(const char *s) {
  delete[] m_symptoms;
  m_symptoms = nullptr;
  size_t lens = strlen(s);
  if (lens > MAX_SYMPTOMS_LENGTH) {
    lens = MAX_SYMPTOMS_LENGTH;
  }
  m_symptoms = new char[lens + 1];
  strncpy(m_symptoms, s, lens);
  m_symptoms[lens] = '\0';
}

TriagePatient::~TriagePatient() {
  delete[] m_symptoms;
  m_symptoms = nullptr;
}

char TriagePatient::type() const { return 'T'; }

std::ostream &TriagePatient::write(std::ostream &os) const {
  if (&os == &cout) {
    os << "TRIAGE" << endl;
    Patient::write(os);
    os << "Symptoms: " << m_symptoms << endl;
  } else if (&os != &clog) {
    Patient::write(os);
    os << "," << m_symptoms;
  } else {
    Patient::write(os);
  }
  return os;
}

std::istream &TriagePatient::read(std::istream &is) {
  Patient::read(is);
  char tempSym[MAX_SYMPTOMS_LENGTH + 1];

  if (&is != &cin) {
    is.ignore(1, ',');
  } else {
    cout << "Symptoms: ";
  }

  is.getline(tempSym, MAX_SYMPTOMS_LENGTH + 1, '\n');
  if (is) {
    setSym(tempSym);
    nextTriageTicket = number() + 1;
  } else {
    delete[] m_symptoms;
    m_symptoms = nullptr;
  }

  return is;
}

} // namespace seneca
