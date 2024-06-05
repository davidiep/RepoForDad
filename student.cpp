/*
 * Title:		X X X X X X X X X
 * Purpose:		P P P P P P P P P
 * Author:		David Diepersloot
 * Date:		Mmm DD, YYYY
 */

#include <sstream>
#include "date.h"
#include "person.h"
#include "student.h"
using std::stringstream;

/**
 * default constructor
 */
Student::Student() {

}

/**
 * custom constructor, takes name and birthday
 * sets uninitialized params _credits and _gpa to 0, and _major to "Undecided"
 * @param name
 * @param birthday
 */
Student::Student(const string& name, const Date& birthday): Person(name, birthday) {
    _credits = 0;
    _gpa = 0.0;
    _major = "Undecided";
}

/**
 * custom constructor, takes name, birthday and major
 * sets uninitialized params _credits and _gpa to 0
 * @param name
 * @param birthday
 * @param major
 */
Student::Student(const string& name, const Date& birthday, const string& major): Person(name, birthday), _major(major) {
    _credits = 0;
    _gpa = 0.0;
}

/**
 * default destructor
 */
Student::~Student() {

}

/**
 * takes in student data, converts into json formatted line
 * uses person::tostring for person line
 * @return String of student info in form of {Person: {name: XXX, birthday: {year: 9999, month: 9, day: 9}}, major: XXX, credits: 9, gpa: 3.9}
 */
string Student::ToString()const {
    stringstream ss;
    ss << "{Person: " << Person::ToString();  //{name: XXXXX, birthday: {year: 9999, month: 9, day: 9}}
    ss << ", major: " << _major << ", gpa: " << _gpa << ", credits: " << _credits << "}";
    return ss.str();
}

/**
 * reads istream input and populates all student params
 * @param input formatted Ann 2000 3 19 BUS 8 3.59375
 */
void Student::Read(istream& input) {
    string name, major;
    int year, month, day, credits;
    double gpa;
    input >> name >> year >> month >> day >> major >> credits >> gpa;
    _name = name;
    _birthday = Date(year, month, day);
    _major = major;
    _credits = credits;
    _gpa = gpa;
}

/**
 * Uses person::output, then adds on student information
 * @param output in format Ann 2000 3 19 BUS 8 3.59375
 */
void Student::Write(ostream& output)const {
//    output << "S ";
    Person::Write(output);
    output << " " << _major << " " << _credits << " " << _gpa;
}

/**
 *  Takes new grade and credits, and updates gpa accordingly
 * @param grade
 * @param credits
 */
void Student::AddGrade(float grade, size_t credits) {
    double totalPoints = (_gpa * _credits) + (grade * credits);
    _credits += credits;
    _gpa = totalPoints / _credits;

}

/**
 * gpa getter
 * @return total student gpa
 */
float Student::GetGPA()const {
    return _gpa;
}

/**
 * credits getter
 * @return total student credits
 */
size_t Student::GetCredits()const {
    return _credits;
}