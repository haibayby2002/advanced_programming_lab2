
#pragma once
#include<string>
#include "Student.h"

class Class
{
public:
	Class();
	Class(int);
	~Class();
	void Input();
	void AddNewStudent(char*, double);
	void AddNewStudent(Student);
	void AddNewStudent();
	void ShowClassInfo();
	Student GetStudentByIndext(int);
	int DeleteStudentByName(char *);
	void DeleteStudentByName();
	void SetStudentScore(int, double);
	int GetNumberOfStudents();
	void ShowStudentsBestScore();

private:
	int number_of_students;
	Student* student;
	int capacity;

	//Private method
	void setCapacity(int);
	void ensureCapacity(int);
	void pack();
	void trim();

	void rangeCheck(int);
	void set(int, Student);
	Student get(int);
	void removeAt(int);
	void insertAt(int, Student);
	//void print();

};

