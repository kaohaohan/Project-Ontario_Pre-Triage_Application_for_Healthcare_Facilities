/* Citation and Sources
Final Project Milestone 3
Module: Patient
Filename: Patient.cpp
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
#include <iostream>
#include <cstring>
#include "Patient.h"
using namespace std;



namespace seneca {
    void Patient::setOHIP(int ohipNum){
        if(ohipNum>=100000000 && ohipNum<=999999999){
            m_ohipNum=ohipNum;
        }
    }
    void  Patient::setName(char* patientName){
        //char xx[] 處理DMA應該是!='\0'
        delete[] m_PatientName;
        if(patientName!=nullptr){
             //the m_PatientName makes a New one !!
             //very very important concept
             // +1 for null terminator
            m_PatientName = new char[strlen(patientName)+1];
            strcpy(m_PatientName, patientName);
        }else{
            m_PatientName=nullptr;
        }
    }

    Patient:: Patient(){};
    Patient::Patient(int num): m_ticket(num) {};
    Patient::Patient(const Patient &p){
        setName(p.m_PatientName);
        m_ohipNum = p.m_ohipNum;
        m_ticket = p.m_ticket;
    };

    // encalupslation Classes-and-Resources review it 
    Patient& Patient::operator=(const Patient& p){
        if (this != &p){
            setName(p.m_PatientName);
            setOHIP(p.m_ohipNum);
            m_ticket = p.m_ticket;
         }
        return *this;

    }

    Patient::~Patient() {
        delete[] m_PatientName; 
        m_PatientName=nullptr;
    }

    bool Patient::operator==(const char c)const{
        char result =type();
        if(result==c){
            return true;
        }else{
            return false;
        }
    }

    bool Patient::operator==(const Patient& p)const {
        char result =type();
        if(result==p.type()){
            return true;
        }else{
            return false;
        }
    }
    void Patient::setArrivalTime(){
        m_ticket.resetTime();
    }

    Time Patient::time()const{
        return  m_ticket.time();
    }
    
    //Establish a query method named number that returns the number associated with the patient's ticket.
    int Patient::number()const{
        return m_ticket.number();
    }


    Patient::operator bool() const{
        if(m_PatientName!=nullptr &&m_ohipNum>=100000000 && m_ohipNum<=999999999){
            return true; 
        }
        return false;
    }


    Patient::operator const char*() const{
        return m_PatientName;
    }

    std::ostream& Patient::write(std::ostream& os) const{
        if(&os== &clog){
            if(!(*this)){
            os <<"Invalid Patient Record" <<endl;
            }else{
            os.setf(std::ios::left);
            os.width(53);
            os.fill('.');
            os << m_PatientName;
            os << m_ohipNum;
            os.setf(std::ios::right);
            os.width(5);
            os.fill(' ');
            os << m_ticket.number();
            os << ' ' << m_ticket.time();
            //deal with ..................................................bbb234234234    2 12:37
            //dont know why 
            os.unsetf(std::ios::right);
        }
        }else if(&os==&cout){
            if(!(*this)){
            os <<"Invalid Patient Record" <<endl;
           
            }else{
                m_ticket.write(os)<<endl;
                os <<m_PatientName<<", OHIP: "<< m_ohipNum <<endl;

            }
        }else{
            os << type() << ',' << m_PatientName << ',' << m_ohipNum << ',';
             //then insert the ticket.
            m_ticket.write(os);
        }
        return os;
    }

std::istream &Patient::read(std::istream &is) {
  if (&is == &std::cin) {
      is.ignore(10000,
                  '\n');
    char tempName[MAX_NAME_LENGTH + 1];
    std::cout << "Name: ";
    is.getline(tempName, MAX_NAME_LENGTH + 1, '\n');
    if (!is) {
      setName(nullptr);
      return is;
    }
    setName(tempName);


    std::cout << "OHIP: ";
    int ohip, valid=0;
    do {
      is >> ohip;
      if (is.fail()) {
        is.clear();
        std::cout << "Bad integer value, try again: ";
      } else if (ohip < 100000000 || ohip > 999999999) {
        std::cout
            << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
      } else {
        valid = 1;
      }
      is.ignore(10000,
                  '\n'); 
    } while (!valid);
    m_ohipNum = ohip; 
  } else {
    char tempName[MAX_NAME_LENGTH + 1]; 
    is.get(tempName, MAX_NAME_LENGTH + 1,
             ','); 
    setName(tempName);
    is.ignore(10000, ',');
    is >> m_ohipNum;
    is.ignore(10000, ',');
    m_ticket.read(is);
  }

  return is;
}
}