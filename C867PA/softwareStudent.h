#pragma once
#include "student.h"
#include "degree.h"
#include <iostream>


class softwareStudent :
	public student
{
public:
	softwareStudent();
	softwareStudent(
		string sID,
		string first,
		string last,
		string email,
		int age,
		int* days,
		Degree deg);

	Degree getDegreeProgram();
	void SetDegreeProgram(Degree deg);
	void print();


private:

	Degree softwareDegree = SOFTWARE;
};

