#include "header.h"

int main()
{
  bool more_students = true;
  string fName;
  string lName;
  int age;
  string occupation;
  int numberOfCodemon;
  bool correctOccupation;
  bool spyAmongUs;
  char more_students_entree;

  cout << "---Now booting up Codemon Academy security system---" << endl;
  while (more_students)
  {
    spyAmongUs = false;
    Entrant entrantArray[5];
    for (int i = 0; i < 5; i++)
    {
      do {
        cout << "Please input name, age, occupation, and the number of Codemon for entrant: " << i+1 << endl;
        cin >> fName >> lName >> age >> occupation >> numberOfCodemon;
        correctOccupation = (occupation == "Student" || occupation == "Faculty" || occupation == "Staff");

      } while (age > 100 || age < 5 || !correctOccupation || numberOfCodemon < 0 || numberOfCodemon > 100);
      entrantArray[i].fName = fName;
      entrantArray[i].lName = lName;
      entrantArray[i].age = age;
      entrantArray[i].occupation = occupation;
      entrantArray[i].numberOfCodemon = numberOfCodemon;
      if (occupation == "Studnet" && age >= 30)
      {
        entrantArray[i].spy = true;
      }
      else if (numberOfCodemon > 6)
      {
        entrantArray[i].spy = true;
      }
      else
      {
        entrantArray[i].spy = false;
      }
    }
    for (int i = 0; i < 5; i++)
    {
      if (entrantArray[i].spy)
        spyAmongUs = true;
    }
    if (spyAmongUs)
    {
      cout << "The following entrants have been denied due to suspicions of Team Picket affiliations" << endl;
      for (int i = 0; i < 5; i++)
      {
        if (entrantArray[i].spy)
          printEntrant(entrantArray[i]);
      }
    }
    else
    {
      cout << "None of the entrants were suspected of spycraft, all were allowed to enter." << endl;
    }
    do
    {
      cout << "Are there more people waiting to enter the academy?" << endl;
      cin >> more_students_entree;

    } while (more_students_entree != 'n' && more_students_entree != 'N' || more_students_entree != 'y' || more_students_entree != 'Y');
    if (more_students_entree == 'n' || more_students_entree == 'N')
    {
      more_students = false;
    }
  }
}