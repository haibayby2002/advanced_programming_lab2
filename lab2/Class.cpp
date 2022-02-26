#include "Class.h"
#include <stdio.h>
#include <conio.h>

Class::Class()
{
	this->capacity = 0;
	this->number_of_students = 0;
	this->student = new Student[capacity];
}

Class::Class(int capacity)
{
	this->capacity = capacity;
	this->number_of_students = 0;
	this->student = new Student[capacity];
}

Class::~Class()
{
	delete[]this->student;
}

void Class::Input()
{
	int n;
	do {
		cout << "Input number of student: ";
		cin >> n;
		if (n <= 0) {
			cout << "The number of students must be greater than 0. Please type agian!\n";
		}
	} while (n <= 0);
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "-----Student " << i + 1 << "-------\n";
		Student s;
		s.InputStudent();
		this->AddNewStudent(s);
		cout << "-----------------------------------\n";
	}
}

void Class::AddNewStudent(char* name, double score)
{
	this->insertAt(this->number_of_students, Student(name, score));
}

void Class::AddNewStudent(Student s)
{
	this->insertAt(this->number_of_students, s);
}

void Class::AddNewStudent()
{
	char name[100];
	double score;
	cout << "------Add student form-------" << endl;
	cout << "Input student'\s name: ";
	gets_s(name);
	cout << "Input student'\s score: ";
	cin >> score;
	this->AddNewStudent(name, score);
	cout << "Inserted " << name << " to the class successfully" << endl;
}

void Class::ShowClassInfo()
{
	cout << "\n\n-------------Class info----------------" << endl;
	cout << "Number of students: " << this->number_of_students << endl;
	for (int i = 0; i < this->number_of_students; i++) {
		cout << "------------Student " << i + 1 << "--------------" << endl;
		this->student[i].PrintInfo();
		cout << "--------------------------------------" << endl;
	}
}

Student Class::GetStudentByIndext(int index)
{
	return this->get(index);
}

int Class::DeleteStudentByName(char* name)
{
	int count = 0;
	for (int i = this->number_of_students - 1; i >= 0; i--) {
		if (this->student[i].GetName() == name) {
			this->removeAt(i);
			count++;
		}
	}
	return count;
}

void Class::DeleteStudentByName()
{
	char name[100];
	cout << "Input student\'s name you want to delete: ";
	//getline(cin, this->name);
	gets_s(name);
	int res = this->DeleteStudentByName(name);
	cout << "Deleted " << res << " students from class!" << endl;
	cout << "------------------------------------" << endl;

}

void Class::SetStudentScore(int index, double new_score)
{
	this->rangeCheck(index);
	this->student[index].SetScore(new_score);
}

int Class::GetNumberOfStudents()
{
	return this->number_of_students;
}

void Class::ShowStudentsBestScore()
{
	if (this->number_of_students == 0) {
		return;
	}
	double max_score = this->student[0].GetScore();
	for (int i = 1; i < this->number_of_students; i++) {
		if (max_score < this->student[i].GetScore()) {
			max_score = this->student[i].GetScore();
		}
	}
	cout << "-----Students with the highest score------- \n";
	for (int i = 0; i < this->number_of_students; i++) {
		if (max_score == this->student[i].GetScore()) {
			this->student[i].PrintInfo();
			cout << endl;
		}
	}
	cout << "-----------------------------------------\n";
}

void Class::setCapacity(int newCapacity)
{
	Student* newStorage = new Student[newCapacity];

	//Get size
	//size_t sum_size = 0;
	//for (int i = 0; i < this->number_of_students; i++) {
	//	sum_size += sizeof(this->student[i]);
	//}

	memcpy(newStorage, this->student, sizeof(Student)*this->number_of_students);
	
	this->capacity = newCapacity;
	delete[]this->student;
	this->student = newStorage;
}

void Class::ensureCapacity(int minCapacity)
{
	if (minCapacity > this->capacity) {
		int newCapacity = (capacity * 3) / 2 + 1;
		if (newCapacity < minCapacity) {
			newCapacity = minCapacity;
		}
		this->setCapacity(newCapacity);
	}
}

void Class::pack()
{
	if (this->number_of_students <= this->capacity / 2) {
		int newCapacity = (this->number_of_students * 3) / 2 + 1;
		this->setCapacity(newCapacity);
	}
}

void Class::trim()
{
	int newCapacity = this->number_of_students;
	this->setCapacity(newCapacity);
}

void Class::rangeCheck(int index)
{
	if (index < 0 || index >= this->number_of_students) {
		throw "Index out of bound";
	}
}

void Class::set(int index, Student value)
{
	this->rangeCheck(index);
	this->student[index] = value;
}

Student Class::get(int index)
{
	this->rangeCheck(index);
	return this->student[index];
}

void Class::removeAt(int index)
{
	rangeCheck(index);
	int moveCount = this->number_of_students - index - 1;
	if (moveCount > 0) {
		memmove(this->student + index, this->student + (index + 1), sizeof(Student) * moveCount);
	}
	this->number_of_students--;
	this->pack();
}

void Class::insertAt(int index, Student value)
{
	if (index < 0 || index > this->number_of_students) {
		throw "Index out of bound";
	}
	this->ensureCapacity(this->number_of_students + 1);
	int moveCount = this->number_of_students - index;
	if (moveCount != 0) {
		memmove(this->student + index + 1, this->student + index, sizeof(Student) * moveCount);
	}
	this->student[index] = value;
	this->number_of_students++;
}
