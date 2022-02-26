#define _CRT_SECURE_NO_DEPRECATE
#include "Student.h"

Student::Student()
{
	//this->name = "";
	this->score = 0;
}

Student::Student(char* name, double score)
{
	//this->name = name;
	strcpy(this->name, name);
	this->score = score;
}

Student::Student(const Student& s)
{
	//this->name = s.name;
	strcpy(this->name, s.name);
	this->score = s.score;
}

Student::~Student()
{

}

void Student::InputStudent()
{
	cout << "Input student\'s name: ";
	//getline(cin, this->name);
	gets_s(this->name);
	cout << "Input student\'s score: ";
	cin >> this->score;
	//fflush(stdin);
	cin.ignore();
}

void Student::SetName(char* name)
{
	//this->name = name;
	strcpy(this->name, name);
}

string Student::GetName()
{
	return this->name;
}

void Student::SetScore(double score)
{
	this->score = score;
}

double Student::GetScore()
{
	return this->score;
}

string Student::GetInfo()
{
	//return "Student: " + this->name + "\n Score: " + to_string(this->score);
	return "";
}

void Student::PrintInfo()
{
	cout << "  Student: " << this->name << "\n  Score: " << this->score << endl;
}

