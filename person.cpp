/*
 * Title:		Person.cpp
 * Purpose:		P P P P P P P P P
 * Author:		David Diepersloot
 * Date:		06/20/2024
 */
#include "person.h"
#include "date.h"
#include <sstream>
using std::stringstream;
/**
 *  default constructor
 */
Person::Person() {
}

/**
 * custom constructor for taking string name and date date
 * @param name
 * @param birthday
 */
Person::Person(const string& name, const Date& birthday): _name(name), _birthday(birthday) {

}

/**
 * custom constructor for string name and date info
 * @param name
 * @param year
 * @param month
 * @param day
 */
Person::Person(const string& name, size_t year, size_t month, size_t day): _name(name), _birthday(Date(year,month,day)) {

}

/**
 * default destructor
 */
Person::~Person() {

}

/**
 * takes in person data, converts into json formatted line
 * @return  string representation of the Person in JSON-like format: {name: XXXXX, birthday: {year: 9999, month: 9, day: 9}}
 */
string Person::ToString()const {    //Returns a string representation of the Person in JSON-like format: {name: XXXXX, birthday: {year: 9999, month: 9, day: 9}}
    stringstream ss;
    ss << "{name: " << _name << ", birthday: {year: " << this->_birthday.GetYear() << ", month: " << this->_birthday.GetMonth() << ", day: " << this->_birthday.GetDay() << "}}";
    return ss.str();
}

/**
 * Reads a person from the input stream, each field is separated by whitespace (space, tab or enter)
 * uses data read to populate person data
 * @param istream& input
 */
void Person::Read(istream& input) {
    string name;
    size_t year, month, day;
    input >> name >> year >> month >> day;
    //Person(name, Date(year, month, day));
    _name = name;
    _birthday = Date(year, month, day);
}

/**
 * writes the person data to the output stream.
 * writes each member separated by space. (name year month day)
 * @param output
 */
void Person::Write(ostream& output)const {
//    output << "P ";
    output << this->_name << " ";
    output << this->_birthday.GetYear() << " ";
    output << this->_birthday.GetMonth() << " ";
    output << this->_birthday.GetDay();
}

/**
 * name getter
 * @return string _name
 */
string Person::GetName()const {    //	Returns the name of the person.
    return _name;
}

/**
 * age getter
 * @return size_t age
 */
size_t Person::GetAge()const {     // Returns the age in years of the person.
    return _birthday.Difference(_birthday.Now());
}



