#pragma once
#include "securityStudent.h"



securityStudent::securityStudent() {

	SetDegreeProgram(SECURITY);

}
securityStudent::securityStudent(string sID, string first, string last, string email, int age, int* days, Degree deg) : student(sID, first, last, email, age, days, deg)
{
	securityDegree = deg;
}

Degree securityStudent::getDegreeProgram() {

	return SECURITY;
}

void securityStudent::SetDegreeProgram(Degree deg) {

	this->degreeType = SECURITY;
}

void securityStudent::print() {
	
	this->student::print();
		cout << "SECURITY" << endl;
}

