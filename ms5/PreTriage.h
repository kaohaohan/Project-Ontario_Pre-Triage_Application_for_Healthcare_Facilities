/* Citation and Sources
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.h
Version 1.0
Author   Kao Hao Han
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef PRETRIAGEPATIENT_H
#define PRETRIAGEPATIENT_H
#include <iostream>
#include "Time.h"
#include "Patient.h"

#define MAX_PATIENT_LENGTH 100


namespace seneca{
    class PreTriage{
        Time m_waitTimeForContaigenTest;
        Time m_waitTimeForTriagePatients;
        //array pointer 
        Patient* m_patientLineup[MAX_PATIENT_LENGTH]{};
        //不確定
        char *m_dataFilename{};
        int m_numPatientLineup{};

        int getWaitTime(const Patient &patient)const;
        void setAverageWaitTime(Patient& patient);
        int indexOfFirstInLine(const char type)const;
        void save()const;
        void load();
        void registerPatient();
        void admit();
        void lineup() const;
        public:
        //instantiated and initializes are different meaning 
        
        PreTriage(const char* dataName);
        ~PreTriage();
        void run();
        
    };
   
}

#endif