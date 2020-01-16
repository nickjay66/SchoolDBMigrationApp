// C867PA.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma
#include "roster.h"
#include <cstring>

Roster::Roster() {
	
}

Roster::~Roster() {

}

void Roster::parseThenAdd(string row) {
	if (lastIndex < 5) {
		lastIndex++;
		Degree deg;
		if (row.back() == 'Y')
		{
			deg = SECURITY;
		}
		else if (row.back() == 'K') {
			deg = NETWORKING;
		}
		else 
		{
			deg = SOFTWARE;
		}
	
		//read student ID
		int rhs = row.find(",");
		string sID = row.substr(0, rhs);

		//read student firts name
		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string first = row.substr(lhs, rhs - lhs);

		//read student last name
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string last = row.substr(lhs, rhs - lhs);

		//read student email
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string email = row.substr(lhs, rhs - lhs);

		//read student age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int age = stoi(row.substr(lhs, rhs - lhs));

		//read daysInCourse1
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

		//read daysInCourse2
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

		//read daysInCourse3
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

		//call add function

		add(sID, first, last, email, age, daysInCourse1, daysInCourse2, daysInCourse3, deg);
		
	   }

	}


void Roster::add(string sID, string first, string last, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree deg) {
	
	//This makes an array of the int days

	int days[3];
	days[0] = daysInCourse1;
	days[1] = daysInCourse2;
	days[2] = daysInCourse3;
	if (deg == SECURITY) classRosterArray[lastIndex] = new securityStudent(sID, first, last, email, age, days, deg);
	else if (deg == NETWORKING) classRosterArray[lastIndex] = new networkStudent(sID, first, last, email, age, days, deg);
	else classRosterArray[lastIndex] = new softwareStudent(sID, first, last, email, age, days, deg);
	
}

void Roster::print_All()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

void Roster::remove(string ID)
{
	int counter = 0;;
	for (int i = 0; i <= lastIndex; i++) {
		string str = this->classRosterArray[i]->GetStudentID();
		if (str == ID) {
			counter = counter + 1;
		}
	}
	if (counter == 0) {
		cout << "Student with this ID was not found" << endl;
	}


		for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetStudentID() == ID) 
		{
		
			delete this->classRosterArray[i];
			

			this->classRosterArray[i] = this->classRosterArray[lastIndex];
		    lastIndex--;
		}
		
	}

}

void Roster::printInvalidEmails() {
	
	string str;
	for (int i = 0; i <= lastIndex; i++) {
		str = this->classRosterArray[i]->GetStudentEmail();
		if (str.find(' ') != string::npos || str.find('@') == string::npos || str.find(".") == string::npos) {
			cout << "Invalid email address: " << str << "." << endl;
		}
	}
}

void Roster::printByDegreeProgram(int degreeProgram) {
	string degy;
	if (degreeProgram == SECURITY) {
		degy = "security";
	}
	else if (degreeProgram == NETWORKING) {
		degy = "network";
	}
	else {
		degy = "software";
	}
	cout << "Students in the " << degy << " program:" << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			this->classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			int* newArray = classRosterArray[i]->GetDaysToComplete();
			cout << "Average days to complete a course for " << studentID << " is " <<((newArray[0] + newArray[1] + newArray[2]) / 3) << "." << endl;
		}
	}
}


int main() {
	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Nicholas,Jerrems,njerrem@wgu.edu,30,20,25,35,SOFTWARE" };
	Roster classRoster;

	cout << "Course Title: Scripting and programming. Language used: C++. Student ID: 000931363. Student name: Nicholas Jerrems" << endl;
	cout << endl;

	cout << "Parsing student data" << endl;

	for (int i = 0; i < 5; ++i) {
	   classRoster.parseThenAdd(studentData[i]);
 }

	classRoster.print_All();
	cout << endl;
	classRoster.printInvalidEmails();
	cout << endl;
	classRoster.printAverageDaysInCourse("A3");
	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;
	classRoster.remove("A3");
	cout << endl;
	classRoster.remove("A3");//FIX ME - still working correctly
	cout << endl;
	classRoster.~Roster();//call deconstructor
	


	}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


