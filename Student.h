#pragma once

#include "Degree.h"

using namespace std;

/*
D.  For the Student class, do the following:
	1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
		•  student ID
		•  first name
		•   last name
		•  email address
		•  age
		•  array of number of days to complete each course
		•  degree program
	2.  Create each of the following functions in the Student class:
		a.  an accessor (i.e., getter) for each instance variable from part D1
		b.  a mutator (i.e., setter) for each instance variable from part D1
		c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
		d.  constructor using all of the input parameters provided in the table
		e.  print() to print specific student data
*/

class Student
{
public:
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* courseDays, DegreeProgram degreeProgram);
	~Student();
	string getStudentID();
	void setStudentID(string newStudentID);
	string getFirstName();
	void setFirstName(string newFirstName);
	string getLastName();
	void setLastName(string newLastName);
	string getEmailAddress();
	void setEmailAddress(string newEmailAddress);
	int validateEmailAddress();
	int getAge();
	void setAge(int newAge);
	int* getDaysInCourse();
	void setDaysInCourse(int* daysInCourseVal);
	void setDaysInCourse(int index, int days);
	DegreeProgram getDegreeProgram();
	string getDegreeProgram(string str);
	void setDegreeProgram(DegreeProgram newDegProg);
	void print();
	float getAverageDaysInCourses();


private:
	const int MAX_COURSES = 3;
//	const int FIELDS = 9;
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3] = { 189, 189, 189 };
	DegreeProgram degreeProgram;
};
