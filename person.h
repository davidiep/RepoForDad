/*
 * Title:		X X X X X X X X X
 * Purpose:		P P P P P P P P P
 * Author:		David Diepersloot
 * Date:		Mmm DD, YYYY
 */

#ifndef SCHOOL_INHERITANCE_PERSON_H
#define SCHOOL_INHERITANCE_PERSON_H

#include "date.h"

class Person {
protected:
    string _name;           // Represents the name of the person (no spaces to simplify Read operation)
    Date _birthday;         // The birthday of the person
public:
    Person(const string& name, const Date& birthday);
    Person(const string& name, size_t year, size_t month, size_t day);
    Person();
    ~Person();
    virtual string ToString()const;	//Returns a string representation of the Person in JSON-like format: {name: XXXXX, birthday: {year: 9999, month: 9, day: 9}}
    virtual void Read(istream& input);	//Reads a person from the input stream, each field is separated by whitespace (space, tab or enter)
    void Write(ostream& output)const;	//Writes the person data to the output stream. It writes each member separated by space.
    string GetName()const; //	Returns the name of the person.
    size_t GetAge()const;	// Returns the age in years of the person.
};


#endif
