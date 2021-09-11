/*
Programmer: Andrew Lazarski
Date: 9/10/2021
File: 
Assignment: HW2
Purpose: Manage the onboarding process of future Codemon Academy students
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


double calculateTuition();
/*
int main()
{
	bool more_students = true;
	int tournaments_won = 0;
	int codemon_owned = 0;
	float household_income = 0;
	int parents_in_show_int = 0;
	bool parents_in_show = false;
	float bribe_money = 0;


	while (more_students)
	{


		cout << "Hello student!" << endl;
		do {
			cout << "How many tournaments have you won? (0-50)" << endl;
			cin >> tournaments_won;
		} while (tournaments_won < 0 || tournaments_won > 50);


		do {
			cout << "How many codemon do you own? (0-30, -1 if you prefer not to answer" << endl;
			cin >> codemon_owned;

		} while (codemon_owned < -1 || codemon_owned > 30);


		do {
			cout << "What is your household income?" << endl;
			cin >> household_income;
		} while (household_income < 0);


		if (household_income > 30000)
		{
			do {
				cout << "Do you have parents that were in the show Brimful Residence? (1 - Yes, 2 - No)" << endl;
				cin >> parents_in_show_int;

			} while (parents_in_show_int != 1 && parents_in_show_int != 2);
			do {
				cout << "How much money will you donate to the athletic director?" << endl;
				cin >> bribe_money;

			} while (bribe_money < 100);
			// 
		}


		else {
			cout << endl << endl << endl;
		}

	}
} 
*/
int main()
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  float x;
  srand(time(NULL));
  for (int i=0; i<100; i++)
{
  x = calculateTuition();
  cout << x << endl;
}

}

bool isAdmitted(int tournaments_won, int codemon_owned, float donation_percentage)
{
	float total_points = 0;
	total_points = 10 * tournaments_won + 2 * codemon_owned;
	total_points = total_points + (total_points * donation_percentage);
	if (total_points >= 30)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isAdmitted(int tournaments_won, float donation_percentage)
{
	float total_points = 0;
	total_points = 10 * tournaments_won;
	total_points = total_points + (total_points * donation_percentage);
	if (total_points >= 30)
	{
		return true;
	}
	else
	{
		return false;
	}
}
float calculateDonationProbability(bool has_parents_in_show, float household_income, float bribe_money)
{
	float donation_chance = 0.01;
	if (household_income < 200000)
	{
		has_parents_in_show = false;
	}
	if (has_parents_in_show)
	{
		donation_chance += 0.1;
	}
	if (household_income >= 200000)
	{
		donation_chance += 0.1;
	}
	if (household_income >= 500000)
	{
		donation_chance += 0.1;
	}
	if (bribe_money >= 10000)
	{
		donation_chance += 0.05;
	}
	if (bribe_money >= 100000)
	{
		donation_chance += 0.05;
	}
	return donation_chance;
}
double calculateTuition()
{
	double random_float;
	random_float = ((rand()%(95000100))+5000000)/100.00;
	return random_float;
}
