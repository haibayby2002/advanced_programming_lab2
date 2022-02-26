#pragma once
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>
using namespace std;

class Student
{
public:
	Student();
	Student(char*,double);
	Student(const Student& s);
	~Student();

	void InputStudent();
	void SetName(char*);
	string GetName();
	void SetScore(double);
	double GetScore();
	string GetInfo();
	void PrintInfo();

private:
	char name[100];
	double score;
};

