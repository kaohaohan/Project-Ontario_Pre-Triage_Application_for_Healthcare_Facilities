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
  char *m_content;
  int m_optionsNum;
  int m_tabs;

  void deallocated();
  void setEmpty();

public:
  Menu();
  Menu(const char *menuContent, int numberOfTabs = 0);
  ~Menu();
  Menu(const Menu &m) = delete;
  void display();
  void printTabs();

  int &operator>>(int &Selection);
};
} // namespace seneca
#endif
