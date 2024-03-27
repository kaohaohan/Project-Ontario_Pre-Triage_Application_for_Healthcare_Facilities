/* Citation and Sources
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author  Hao Han Kao
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
/***********************************************************************
// OOP244 Project
//
// File  Utils.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
namespace seneca {
     void Menu::deallocated(){
        if(m_content!=nullptr){
            delete[] m_content;
            m_content =nullptr;
        }
     }
    Menu::Menu(){
        setEmpty();
    }
    void Menu::setEmpty(){
        m_content = nullptr;
        m_optionsNum =0;
        m_tabs =0;
    }
    Menu::Menu(const char* menuContent, int numberOfTabs){
        setEmpty();
        if(menuContent!=nullptr ){
            m_content = new char[strlen(menuContent)+1];
            strcpy(m_content,menuContent);
            m_tabs =numberOfTabs;
            //This part is contributed by Tzu Han Chao
            //I can figure it out by myself..
            //I will note this part in reflection!!!
            for(const char *c =menuContent; *c !='\0';c++){
                if(*c=='\n'){
                    m_optionsNum+=1;
                }
            }
        }
        
        
    }
    Menu::~Menu(){
        delete[] m_content;
        setEmpty();
    }
    

    // deal with tab!!!
    void Menu::printTabs(){
        for (int i=0;i<m_tabs;i++){
            cout << "   ";  
        }
    }

    void Menu::display(){
        // Menu m("Tester Options menu:\n1- Option one\n2- Option two");
        string oneLine{}; 
        for(const char *c =m_content; *c!='\0';c++){
            //tab
            if(*c!='\n'){
                oneLine+=*c;
            }else{
                printTabs();
                 
                cout<< oneLine<<endl;
                oneLine.clear();
            }
        }
        //deal with last line becaue *c!='\n' 
        //logic can't print last line so I want to check whether the the line is empty?
        //if is not empty print it.  
        if(!oneLine.empty()){
            printTabs();
            cout << oneLine <<endl;
        }
        printTabs();
        cout << "0- Exit"<<endl;
    }

    int& Menu::operator>>(int& selection){
        display();
        bool vaild =false;
        // return userSelection;
        printTabs();
        //如果不vaild要繼續驗證
        cout << "> ";
        while(!vaild){
            cin>>selection;
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Bad integer value, try again: ";
            }else{
                if(cin.peek()!='\n'){
                    cout << "Only enter an integer, try again: ";
                }else{
                    if (!(0<=selection && selection<=m_optionsNum)){
                        cout << "Invalid value enterd, retry[0 <= value <= "<<m_optionsNum <<"]: ";
                    }else{
                        vaild =true;
                    }
                }
            }
        }
        return selection;

    }
}

// namespace seneca
