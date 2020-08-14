#include <iostream>
//#include <cctype>
//#include <vector>
#include <string>

#include "Student.h"
using namespace std;

/* Requirement D
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

Student::Student(string XstudentID, string XfirstName, string XlastName, string XemailAddress, int Xage,
	int XdaysInCourse[3], DegreeProgram XdegreeProgram)
{
	//setStudentID(XstudentID);
	//setFirstName(XfirstName);
	//setLastName(XlastName);
	//setEmailAddress(XemailAddress);
	//setAge(Xage);
	//setDaysInCourse(XdaysInCourse);
	//setDegreeProgram(XdegreeProgram);

	studentID = XstudentID;
	firstName = XfirstName;
	lastName = XlastName;
	emailAddress = XemailAddress;
	age = Xage;
	// daysInCourse = XdaysInCourse;
	for (int i = 0; i < 3; i++) {
		daysInCourse[i] = XdaysInCourse[i];
	}
	degreeProgram = XdegreeProgram;
}

Student::~Student()
{
}

string Student::getStudentID()
{
	return studentID;
}

void Student::setStudentID(string newStudentID)
{
	studentID = newStudentID;
}

string Student::getFirstName()
{
	return firstName;
}

void Student::setFirstName(string newFirstName)
{
	firstName = newFirstName;
}

string Student::getLastName()
{
	return lastName;
}

void Student::setLastName(string newLastName)
{
	lastName = newLastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

void Student::setEmailAddress(string newEmailAddress)
{
	emailAddress = newEmailAddress;
}

int Student::validateEmailAddress()
{
	/*
	For this assignment:
	"Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ')."
	according to that, I suppose the period could be before the at symbol but the ...
	*/

	if (emailAddress.find("@") == string::npos) { // no "@" found
		return 1;
	}
	if (emailAddress.find(".") == string::npos) { // no "." found
		return 1;
	}
	if (emailAddress.find(" ") != string::npos) { // found a space " "
		return 1;
	}
	return 0;
}

int Student::getAge()
{
	return age;
}

void Student::setAge(int newAge)
{
	age = newAge;
}

int* Student::getDaysInCourse()
{
	return daysInCourse;
}

void Student::setDaysInCourse(int* XdaysInCourse)
{
	//daysInCourse = daysInCourse;
	for (int i = 0; i < 3; i++) {
		daysInCourse[i] = XdaysInCourse[i];
	}

}

void Student::setDaysInCourse(int index, int days)
{
	daysInCourse[index] = days;
}

DegreeProgram Student::getDegreeProgram()
{
	return degreeProgram;
}

string Student::getDegreeProgram(string str)
{
	if (degreeProgram == SECURITY) {
		return "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		return "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		return "SOFTWARE";
	}
	else { // didn't match anything else, set it UNDECLARED
		return "UNDECLARED";
	}
}

void Student::setDegreeProgram(DegreeProgram newDegProg)
{
	degreeProgram = newDegProg;
}

void Student::print() // student data in tab seperated format //don't use get/set use direct access
//c. public void printAll() that prints a complete tab-separated list of student data in the provided
//   format:
//   A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]
//   daysInCourse: {35, 40, 55} Degree Program: Security.
{
	int i = 0;
	string foo = "foo";

	cout << studentID << "\t" <<
		"First Name: " << firstName << "\t" <<
		"Last Name: " << lastName << "\t" <<
		"Age: " << age << "\t" <<
		"daysInCourse: {" << "\t";
	cout << daysInCourse[i];
	for (int i = 1; i < MAX_COURSES; i++) {
		cout << ", " << daysInCourse[i];
	}
	cout << "}\tDegree Program: " << getDegreeProgram(foo) << "." << endl;
}

float Student::getAverageDaysInCourses()
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < MAX_COURSES; i++) {
		sum = sum + daysInCourse[i];
	}
	return static_cast<float>(sum) / static_cast<float>(MAX_COURSES);
}
