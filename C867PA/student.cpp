#pragma once
#include "student.h"
#include <string>
#include <iostream>
#include <array>
#include<iomanip>
using namespace std;

student::student() {
	this->studentID = "null";
	this->firstName = "null";
	this->lastName = "null";
	this->studentEmail = "null";
	this->studentAge = 0;
	this->daysToComplete = new int[dayArraySize];
	for (int i = 0; i < dayArraySize; i++) this->daysToComplete[i] = 0;
}
//FIX ME - Why is it not calling constructor w/parameters?


student::student(string sID, string first, string last, string email, int age, int days[], Degree deg) {
	this->studentID = sID;
	this->firstName = first;
	this->lastName = last;
	this->studentEmail = email;
	this->studentAge = age;
	this->daysToComplete = new int[dayArraySize];
	for (int i = 0; i < dayArraySize; i++) daysToComplete[i] = days[i];

}


student::~student() {
	cout << "Deleting student" << endl;
	return;
}


void student::SetStudentID(string id) {
	studentID = id;
}

void student::SetFirstName(string name) {
	firstName = name;
}

void student::SetLastName(string lName) {
	lastName = lName;
}

void student::SetStudentEmail(string email) {
	studentEmail = email;
}

void student::SetStudentAge(int age) {
	studentAge = age;
}


string  student::GetStudentID() {
	return studentID;
}

string student::GetFirstName() {
	return firstName;
}

string student::GetLastName() {
	return lastName;
}

string student::GetStudentEmail() {
	return studentEmail;
}

int student::GetStudentAge() {
	return studentAge;
}

int* student::GetDaysToComplete() {
	return daysToComplete;
}

void student::SetDaysToComplete(int daysToComplete[])
{
	if (this->daysToComplete != nullptr) {
		delete[] this->daysToComplete;
		this->daysToComplete = nullptr;
	}
	this->daysToComplete = new int[dayArraySize];
	for (int i = 0; i < 3; i++)
		this->daysToComplete[i] = daysToComplete[i];
}

void student::print()
{
	cout << left << setw(10) << studentID;
	cout << left << setw(10) << firstName;
	cout << left << setw(10) << lastName;
	cout << left << setw(30) << studentEmail;
	cout << left << setw(10) << studentAge;
	cout << left << setw(10) << daysToComplete[0];
	cout << left << setw(10) << daysToComplete[1];
	cout << left << setw(10) << daysToComplete[2];
}
