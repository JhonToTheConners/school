#include "header.h"



void printEntrant(Entrant ent)
{
  cout << "Name: " << ent.fName << " " << ent.lName << endl;
  cout << "Age: " << ent.age << endl;
  cout << "Occupation: " << ent.occupation << endl;
  cout << "Number of Codemon: " << ent.numberOfCodemon << endl;
}