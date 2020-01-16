#pragma once
#ifndef student_H
#define student_H
#include <string>
#include <array>
#include "degree.h"
using namespace std;

class student {

public:

	student(string sID, string first, string last, string email, int age, int days[], Degree deg);
	student();
   ~student();

    const static int dayArraySize = 3;

	void SetStudentID(string id);
	void SetFirstName(string name);
	void SetLastName(string lName);
	void SetStudentEmail(string email);
	void SetStudentAge(int age);
	void SetDaysToComplete(int* daysToComplete);
	virtual void SetDegreeProgram(Degree deg) = 0;

	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetStudentEmail();
	int GetStudentAge();
	int* GetDaysToComplete();

	virtual Degree getDegreeProgram() = 0;
	virtual void print() = 0;

protected:
	string studentID;
	string firstName;
	string lastName;
	string studentEmail;
	int studentAge;
	int* daysToComplete;
	Degree degreeType;
};

#endif
