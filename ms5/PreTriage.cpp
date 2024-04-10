/* Citation and Sources
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
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
#include "PreTriage.h"
#include "Menu.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Utils.h"
#include "fstream"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca {

PreTriage::PreTriage(const char *dataName)
    : m_waitTimeForContaigenTest(15), m_waitTimeForTriagePatients(5) {
  if (dataName != nullptr) {
    m_dataFilename = new char[strlen(dataName) + 1];
    strcpy(m_dataFilename, dataName);
    load();
  } else {
    m_dataFilename = nullptr;
  }
}
PreTriage::~PreTriage() {
  save();
  for (int i = 0; i < m_numPatientLineup; i++) {
    delete m_patientLineup[i];
    m_patientLineup[i] = nullptr;
  }
  delete[] m_dataFilename;
  m_dataFilename = nullptr;
}

int PreTriage::getWaitTime(const Patient &patient) const {
  int count = 0;
  char pType = patient.type();
  for (int i = 0; i < m_numPatientLineup; i++) {
    if (m_patientLineup[i]->type() == pType) {
      count++;
    }
  }
  if (pType == 'T') {
    return m_waitTimeForTriagePatients * count;
  } else {
    return m_waitTimeForContaigenTest * count;
  }
}

void PreTriage::setAverageWaitTime(Patient &patient) {
  int currentTime = U.getTime();
  int patientTicketTime = patient.time();
  int averageWaitTime = 0;
  int patientTicketNum = patient.number();

  if (patient.type() == 'T') {
    averageWaitTime = m_waitTimeForTriagePatients;
  } else {
    averageWaitTime = m_waitTimeForContaigenTest;
  }
  int result = ((currentTime - patientTicketTime) +
                (averageWaitTime * (patientTicketNum - 1))) /
               patientTicketNum;
  if (patient.type() == 'T') {
    m_waitTimeForTriagePatients = result;
  } else {
    m_waitTimeForContaigenTest = result;
  }
}

int PreTriage::indexOfFirstInLine(const char type) const {
  for (int i = 0; i < m_numPatientLineup; i++) {
    if (*m_patientLineup[i] == type) {
      return i;
    }
  }
  return -1;
}
void PreTriage::load() {
  cout << "Loading data..." << endl;
  ifstream file(m_dataFilename);

  if (!file) {
    cout << "No data or bad data file!" << endl << endl;
    return;
  }

  file >> m_waitTimeForContaigenTest;
  file.ignore(10000, ',');
  file >> m_waitTimeForTriagePatients;
  file.ignore(10000, '\n');

  int count = 0;
  for (int i = 0; i < MAX_PATIENT_LENGTH && file.good(); i++) {
    Patient *pPointer{};
    char patientChar{};
    file >> patientChar;
    file.ignore(10000, ',');

    if (patientChar == 'C') {
      pPointer = new TestPatient;
    } else if (patientChar == 'T') {
      pPointer = new TriagePatient;
    }
    if (pPointer != nullptr) {
      file >> *pPointer;
      m_patientLineup[i] = pPointer;
      m_numPatientLineup++;
      count++;
    }
  }

  if (file.peek() != EOF) {
    cout << "Warning: number of records exceeded " << MAX_PATIENT_LENGTH
         << endl;
  }
  if (count == 0) {
    cout << "No data or bad data file!" << endl << endl;
  } else {
    cout << count << " Records imported..." << endl << endl;
  }

  file.close();
}
void PreTriage::save() const {
  // Opens the data file for output.
  cout << "Saving lineup..." << endl;
  ofstream file(m_dataFilename);
  int tCount = 0, cCount = 0;

  if (!file) {
    cout << "Error opening file for saving." << endl;
    return;
  }
  file << m_waitTimeForContaigenTest << ',' << m_waitTimeForTriagePatients
       << endl;
  for (int i = 0; i < m_numPatientLineup; i++) {
    file << *m_patientLineup[i] << endl;
    if (m_patientLineup[i]->type() == 'T') {
      tCount++;
    } else {
      cCount++;
    }
  }
  cout << cCount << " Contagion Tests and " << tCount
       << " Triage records were saved!" << endl;
}

void PreTriage::registerPatient() {
  Menu m("Select Type of Registration:\n1- Contagion Test\n2- Triage", 1);
  int selection;
  if (m_numPatientLineup == MAX_PATIENT_LENGTH) {
    cout << "Line up full!" << endl;
    return;
  }
  m >> selection;
  Patient *p{};
  if (selection == 1) {
    // next available lineup pointer instantiate a Contagion Test Patient
    p = new TestPatient;
  } else if (selection == 2) {
    p = new TriagePatient;
  } else if (selection == 0) {
    return;
  }

  if (p != nullptr) {
    int time = getWaitTime(*p);
    Time t(time);
    p->setArrivalTime();
    cout << "Please enter patient information: " << endl;
    cin >> *p;
    cout << endl;
    // ticket
    cout << "******************************************" << endl;
    cout << *p;
    cout << "Estimated Wait Time: " << t << endl;
    cout << "******************************************" << endl << endl;

    m_patientLineup[m_numPatientLineup] = p;
    m_numPatientLineup++;
  }
}

void PreTriage::admit() {
  Menu m("Select Type of Admittance:\n1- Contagion Test\n2- Triage", 1);
  int selection;
  m >> selection;
  char type;

  if (selection == 1) {
    type = 'C';

  } else if (selection == 2) {
    type = 'T';
  } else if (selection == 0) {
    return;
  }
  int nextPatientIndex = indexOfFirstInLine(type);
  // if no patient is found, print "Lineup is empty!\n" and terminate the
  // function
  if (nextPatientIndex == -1) {
    cout << "Lineup is empty!" << endl;
    return;
  }
  cout << endl;
  cout << "******************************************" << endl;
  int min = U.getTime();
  Time t(min);
  cout << "Call time: [" << t << "]" << endl;
  cout << "Calling at for ";
  Patient *patient = m_patientLineup[nextPatientIndex];
  cout << *patient;
  cout << "******************************************" << endl << endl;
  // set the average wait time for the patient (using setAverageWaitTime method)
  setAverageWaitTime(*patient);

  removeDynamicElement(m_patientLineup, nextPatientIndex, m_numPatientLineup);
}

void PreTriage::lineup() const {
  Menu m("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);
  int selection;
  m >> selection;
  char type;
  if (selection == 1) {
    type = 'C';
  } else if (selection == 2) {
    type = 'T';
  } else if (selection == 0) {
    return;
  }
  cout << "Row - Patient name                                          OHIP  "
          "   Tk #  Time"
       << endl;
  // 可能有錯
  cout << "--------------------------------------------------------------------"
          "-----------"
       << endl;
  if (m_numPatientLineup == 0) {
    cout << "Line up is empty!\n" << endl;
  }

  int count = 1;
  for (int i = 0; i < m_numPatientLineup; i++) {
    if (m_patientLineup[i]->type() == type) {
      clog << count << "   - " << *m_patientLineup[i] << endl;
      count++;
    }
  }
  cout << "--------------------------------------------------------------------"
          "-----------"
       << endl;
}

void PreTriage::run() {
  Menu m("General Healthcare Facility Pre-Triage Application\n1- Register\n2- "
         "Admit\n3- View Lineup");

  // And get the user's selection.

  // display the menu and get the selection
  // if the selection is 0, quit the method
  // if the selection is 1 call the register method
  // if the selection is 2 call the admit method
  // if the selection is 3 call the lineup method
  // go back to 1
  int selection;
  while (m >> selection) {
    switch (selection) {
    case 1:
      registerPatient();
      break;
    case 2:
      admit();
      break;
    case 3:
      lineup();
      break;
    case 0:
      break;
    default:
      break;
    }
  }
}
} // namespace seneca