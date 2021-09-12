/*
Programmer: Andrew Lazarski
Date: 9/10/2021
File: HW2-AndrewLazarski.cpp
Assignment: HW2
Purpose: Manage the onboarding process of future Codemon Academy students
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;



/*Function: isAdmitted()
* Purpose: Takes in tournaments won, codemon owned, and donation percentage to give back a rating for each 
* potential student. Function is overloaded to accomodate a case where there is no codemon owned
* Returns: float of the rating of the student
*/
float isAdmitted(int tournaments_won, int codemon_owned, float donation_percentage);
float isAdmitted(int tournaments_won, float donation_percentage);


/*Function: calculateDonationProbability()
* Purpose: Applies the many conditional statements which contribute to the students donation percent.
* Returns: A summation of all the increases in donation chance after moving through all the conditionals.
*/
float calculateDonationProbability(bool has_parents_in_show, float household_income, float bribe_money);


/*Function: calculateTuition()
* Purpose: Generates a random tuition from 50k-1m, then adds tuition increases and subtracts scholarships. 
* then returns the final tuition cost (3.5 if the tuition ends up being negative)
* Returns: Final tuition cost
*/
double calculateTuition(int is_admitted_total, int tournaments_won, bool parents_in_show, float family_income);

int main()
{
	bool more_students = true;
	int tournaments_won = 0;
	int codemon_owned = 0;
	float household_income = 0;
	int parents_in_show_int = 0;
	bool parents_in_show = false;
	float bribe_money = 0;
	int another_student_in_line_question;
	float admission_score = 0;

	while (more_students)
	{
		cout << "Hello student!" << endl;
		//User Inputs
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
		//If household income is above 30k, continue with admission, else: move onto next student
		if (household_income > 30000)
		{
			//continue with inputs
			do {
				cout << "Do you have parents that were in the show Brimful Residence? (1 - Yes, 2 - No)" << endl;
				cin >> parents_in_show_int;
			} while (parents_in_show_int != 1 && parents_in_show_int != 2);
			do {
				cout << "How much money will you donate to the athletic director?" << endl;
				cin >> bribe_money;
			} while (bribe_money < 100);
			if (household_income < 200000)
			{
				parents_in_show = false;
			}
			//start calculating admission score and tuition
			admission_score = isAdmitted(tournaments_won, codemon_owned, calculateDonationProbability(parents_in_show, household_income, bribe_money));
			//if admission score >= 30, accepted. Else: Did not get accepted
			if (admission_score >= 30)
			{
				cout << "You are admitted!" << endl;
				cout.setf(ios::fixed);
				cout.setf(ios::showpoint);
				cout.precision(2);
				cout << "Your tuition is $" << calculateTuition(admission_score, tournaments_won, parents_in_show, household_income) << endl;
				do {
					cout << "Is there another student in line? (1 - Yes, 2 - No)" << endl;
					cin >> another_student_in_line_question;
				} while (another_student_in_line_question != 1 && another_student_in_line_question != 2);
				if (another_student_in_line_question == 1)
				{
					more_students = true;
				}
				else
				{
					more_students = false;
				}
			}
			//Else statement for not being admitted.
			else
			{
				cout << "You did not get admitted" << endl;
					do {
						cout << "Is there another student in line? (1 - Yes, 2 - No)" << endl;
						cin >> another_student_in_line_question;
					} while (another_student_in_line_question != 1 && another_student_in_line_question != 2);
					if (another_student_in_line_question == 1)
					{
						more_students = true;
					}
					else
					{
						more_students = false;
					}
			}
		}
		//This is the else case for income being < 30k
		else {
			cout << "We will not consider you.";
			do {
				cout << "Is there another student in line? (1 - Yes, 2 - No)" << endl;
				cin >> another_student_in_line_question;
			} while (another_student_in_line_question != 1 && another_student_in_line_question != 2);
			if (another_student_in_line_question == 1)
			{
				more_students = true;
			}
			else
			{
				more_students = false;
			}

		}
	}
}


float isAdmitted(int tournaments_won, int codemon_owned, float donation_percentage)
{
	float total_points = 0;
	total_points = 10 * tournaments_won + 2 * codemon_owned;
	total_points = total_points + (total_points * donation_percentage);
	return total_points;
}

float isAdmitted(int tournaments_won, float donation_percentage)
{
	float total_points = 0;
	total_points = 10 * tournaments_won;
	total_points = total_points + (total_points * donation_percentage);
	return total_points;
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

double calculateTuition(int is_admitted_total, int tournaments_won, bool parents_in_show, float family_income)
{
	double random_float;
	float tuition;
	float scholarships;
	int parents_in_show_multiplier;
	int tuition_increase;
	random_float = ((rand() % (95000100)) + 5000000) / 100.00;
	if (parents_in_show)
	{
		parents_in_show_multiplier = 1;
	}
	else
	{
		parents_in_show_multiplier = 0;
	}
	scholarships = 100 * is_admitted_total + 5000*tournaments_won + 20000*parents_in_show_multiplier;
	tuition_increase = static_cast<int>(family_income / 100000);
	tuition_increase = tuition_increase * 20000;
	tuition = random_float + tuition_increase - scholarships;
	if (tuition < 0)
	{
		return 3.50;
	}
	else
	{
		return tuition;
	}
}
