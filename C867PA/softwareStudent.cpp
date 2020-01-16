#include "softwareStudent.h"



softwareStudent::softwareStudent() {

	SetDegreeProgram(SOFTWARE);

}
softwareStudent::softwareStudent(string sID, string first, string last, string email, int age, int* days, Degree deg) : student(sID, first, last, email, age, days, deg)
{
	SetDegreeProgram(SOFTWARE);
}

Degree softwareStudent::getDegreeProgram() {

	return SOFTWARE;
}

void softwareStudent::SetDegreeProgram(Degree deg) {

	this->degreeType = SOFTWARE;
}

void softwareStudent::print() {

	this->student::print();
		cout << "SOFTWARE" << endl;
}




