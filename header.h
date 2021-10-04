#ifndef HEADER_H
#define HEADER_H

#include "main.cpp"
#include "header.cpp"
#include <iostream>
#include <string>

using namespace std;

struct Entrant
{
  string fName;
  string lName;
  int age;
  string occupation;
  int numberOfCodemon;
  bool spy;
};

void printEntrant(Entrant ent);




#endif