#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include "Class.h"
using namespace std;

enum Command
{
	EXIT = 0,
	INPUT = 1,
	INSERT = 2,
	DELETE = 3,
	SHOW = 4,
	BEST_SCORE = 5,
	UPDATE_SCORE = 6
};



int main() {
	Class c;
	c.Input();
	
	int opt;
	while (true) {
		cout << "\n-----------------------Choose what to do next. -------------------------" << endl;
		if (c.GetNumberOfStudents() == 0) {
			cout << "0. Exit " << endl;
			cout << "1. Input class" << endl;
			cout << "2. Insert student to class" << endl;
		}
		else {
			cout << "0. Exit" << endl;
			cout << "2. Insert student to class" << endl;
			cout << "3. Delete student from class" << endl;
			cout << "4. Show class information" << endl;
			cout << "5. Show all students have the greatest score" << endl;
		}
		cout << "What is your option: ";
		cin >> opt;
		cin.ignore();
		switch (opt)
		{
		case Command::EXIT:
			break;
		case Command::INPUT:
			c.Input();
			break;
		case Command::INSERT:
			c.AddNewStudent();
			break;
		case Command::DELETE:
			c.DeleteStudentByName();
			break;
		case Command::SHOW:
			c.ShowClassInfo();
			break;
		case Command::BEST_SCORE:
			c.ShowStudentsBestScore();
			break;
		default:
			cout << "Option not clear, try again!\n";
			break;
		}
		if (opt == 0) break;
	}
	
	return 0;
}