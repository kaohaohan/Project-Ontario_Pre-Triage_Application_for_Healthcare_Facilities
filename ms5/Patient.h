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
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
namespace seneca {

   const int MAX_NAME_LENGTH = 50;

   class Patient:public IOAble{
        //A dynamically allocated C-string, 
        //represented by a character pointer variable
      char* m_PatientName=nullptr;
      int m_ohipNum{};
      Ticket m_ticket;
      public:
      //empty constructor 

      void setOHIP(int ohipNum); // Setter for OHIP number
      void setName(char* patientName);
      //Instantiate a Patient object by providing a ticket number (an integer)
      Patient();
      Patient(int t);
      //copy assignment
      Patient(const Patient &);
      Patient& operator=(const Patient& p);
      virtual ~Patient();
      //char type()
      virtual char type()const =0 ;
      
      //Patient Comparison to a Characterx
      bool operator==(const char c) const;
     // Comparing to Another Patient
     bool operator==(const Patient& p)const ; //seems to add const?????!!!!

    //Setting the Patient's Arrival Time
     void setArrivalTime();

     ///Getting the Patient's Arrival TIme
     Time time() const;
     //Patient's Ticket Number
     int number() const;
    //cast Boolean
    // refer WS5xwx
    operator bool() const;
    //Const Character Pointer
    operator const char*() const; //why should i have add const ?

    std::ostream& write(std::ostream& os) const;

    
    std::istream& read(std::istream& is);  

   };


}
#endif 
