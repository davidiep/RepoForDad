/*
 * Title:		X X X X X X X X X
 * Purpose:		P P P P P P P P P
 * Author:		Master Shifu
 * Date:		Mmm DD, YYYY
 */

#include "date.h"
#include "person.h"
#include "professor.h"
#include <sstream>
using std::stringstream;

/**
 * default constructor
 * sets rank to assistant prof,
 * sets salary to 60,000,
 * sets department to unknown
 */
Professor::Professor() {
    _rank = ASSISTANT_PROFESSOR;
    _salary = 60000.0;
    _department = "Unknown";
}

/**
 * custom constructor for name, birthday, and department
 * sets rank to assistant and salary to 60000.0
 * @param name
 * @param birthday
 * @param department
 */
Professor::Professor(const string& name, const Date& birthday, const string& department): Person(name, birthday), _department(department) {
    _rank = Rank(0);
    _salary = 60000.0;
}

/**
 * custom constructor for all needed params but rank and salary
 * uses hire date to determine rank and salary
 * @param name
 * @param birthday
 * @param department
 * @param hireDate
 */
Professor::Professor(const string& name, const Date& birthday, const string& department, const Date & hireDate): Person(name, birthday), _department(department), _hireDate(hireDate) {
    Date().Now;
    //Date(hireDate).Difference(Date().Now);
    Date Now = Date().Now();
    int difference = Now.Difference(_hireDate);
    double years = difference / 365;

    if (years < 5) {
        _rank = ASSISTANT_PROFESSOR;
        _salary = 60000.0;
    } else if (years < 10) {
        _rank = ASSOCIATE_PROFESSOR;
        _salary = 70000.0;
    } else {
        _rank = PROFESSOR;
        _salary = 75000.0;
    }

}

/**
 * custom constructor for all needed params
 * @param name
 * @param birthday
 * @param department
 * @param hireDate
 * @param rank
 * @param salary
 */
Professor::Professor(const string& name, const Date& birthday, const string& department, const Date& hireDate, Rank rank, float salary): Person(name, birthday), _department(department), _hireDate(hireDate), _rank(rank), _salary(salary) {

}

/**
 * default destructor
 */
Professor::~Professor() {

}

/**
 * takes in person data, converts into json formatted line
 * @return string in format {Person: {name: XXX, birthday: {year: 9999, month: 9, day: 9}}, department: XXX, rank: 9, hire-date: {year: 9999, month: 9, day: 9}, salary: 999.99}
 */
string Professor::ToString()const {
    stringstream ss;
    ss << "{Person: " << Person::ToString();  //{name: XXXXX, birthday: {year: 9999, month: 9, day: 9}} // {year: " << _year << ", month: " << _month << ", day: " << _day << "}
    ss << ", department: " << _department << ", rank: " << _rank << ", hire-date: " << _hireDate.ToString() << ", salary: " << _salary << "}";
    return ss.str();
}

/**
 * reads a professor from the input stream
 * Daphne 1995 9 4 BIO 2018 9 1 1 62100
 * @param input
 */
void Professor::Read(istream& input) {
string name, department;
size_t year, month, day, hireYear, hireMonth, hireDay, rank;
Rank assignedRank;
float salary;
input >> name >> year >> month >> day >> department >> hireYear >> hireMonth >> hireDay >> rank >> salary;
if (rank == 1) {
    assignedRank = ASSOCIATE_PROFESSOR;
}
else if (rank == 2) {
    assignedRank = PROFESSOR;
}
else {
    assignedRank = ASSISTANT_PROFESSOR;
}
_name = name;
_birthday = Date(year, month, day);
_department = department;
_hireDate = Date(hireYear, hireMonth, hireDay);
_rank = assignedRank;
_salary = salary;
}

/**
 *Uses person::output, then adds on professor information
 * @param output Daphne 1995 9 4 BIO 2018 9 1 1 62100
 */
void Professor::Write(ostream& output)const {
//    output << "R ";
    Person::Write(output);
    output << " " << _department << " " << _hireDate.GetYear() << " " << _hireDate.GetMonth() << " " << _hireDate.GetDay() << " " << _rank << " " << _salary;

}

/**
 * increases the salary of the professor by the given percentage.
 * If the increase is 15% then the parameter value should be 0.15
 * @param percentage
 */
void Professor::Raise(float percentage) {
 percentage += 1.0;
 _salary *= percentage;
}

/**
 *promotes the professor to the next rank, unless the professor is already at the highest rank
 */
void Professor::Promote() {
    if (_rank == ASSISTANT_PROFESSOR) {
        _rank = ASSOCIATE_PROFESSOR;
        _salary = 70000;
    }
    else if (_rank == ASSOCIATE_PROFESSOR) {
        _rank = PROFESSOR;
        _salary = 75000;
    }
}

/**
 *
 * @return Professor Rank
 */
Rank Professor::GetRank()const {
    return _rank;
}

/**
 *
 * @return Professor Salary
 */
float Professor::GetSalary()const {
    return _salary;
}