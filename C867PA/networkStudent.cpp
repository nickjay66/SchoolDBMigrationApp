#pragma once
#include "networkStudent.h"


networkStudent::networkStudent() {

	SetDegreeProgram(NETWORKING);

}
networkStudent::networkStudent(string sID, string first, string last, string email, int age, int* days, Degree deg) : student(sID, first, last, email, age, days, deg)
{
	SetDegreeProgram(NETWORKING);
}

Degree networkStudent::getDegreeProgram() {

	return NETWORKING;
}

void networkStudent::SetDegreeProgram(Degree deg) {

	this->degreeType= NETWORKING;
}

void networkStudent::print() {

	this->student::print();
		cout << "NETWORKING" << endl;
}


