/* Citation and Sources
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author  Hao Han Kao
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECAMENU_H
#define SENECAMENU_H
#include <iostream>
#include <string>
#include <vector>

#define MAX_OPTION_NUM 10

namespace seneca {
class Menu {
    //A constant char pointer to hold the content of the menu to be displayed
    char *m_content;
    //An Integer to hold the number of options in the menu
    int m_optionsNum;
    //An integer to hold the number of indetation tabs
    int m_tabs;
    
    void deallocated();
    void setEmpty();
    public:
        Menu();
        Menu(const char* menuContent, int numberOfTabs = 0);
        ~Menu();
        //Email(const Email& e )=delete;
        Menu(const Menu& m)=delete;
        void display();
        void printTabs();

        int& operator>>(int& Selection);

        
};
} // namespace seneca
#endif


