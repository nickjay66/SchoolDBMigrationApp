#pragma once
#include "student.h"
#include "degree.h"
#include <string>
#include <array>
#include <iostream>

using namespace std;

class networkStudent :
	public student
{
public:
	networkStudent();
	networkStudent(
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

	Degree networkDegree = NETWORKING;
};

