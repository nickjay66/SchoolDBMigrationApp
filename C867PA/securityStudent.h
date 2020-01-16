#pragma once
#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

class securityStudent :
	public student
{
public:
	securityStudent();
	securityStudent(
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

	Degree securityDegree = SECURITY;
};

