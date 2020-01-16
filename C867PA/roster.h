#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <vector>
#include <iostream>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"

class Roster {
private:
	int lastIndex = -1; 
	student* classRosterArray[5];

public:
	Roster();

	void parseThenAdd(string row);
	void add(string sID, string first, string last, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree deg);
	void print_All();
	void remove(string ID);
	void printDaysInCourse();
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);
	void printAverageDaysInCourse(string studentID);
	
	~Roster();
};


