/*
 * Title:		X X X X X X X X X
 * Purpose:		P P P P P P P P P
 * Author:		Master Shifu
 * Date:		Mmm DD, YYYY
 */

#ifndef SCHOOL_INHERITANCE_STUDENT_H
#define SCHOOL_INHERITANCE_STUDENT_H

#include "date.h"

class Student : public Person {
private:
    string _major;
    size_t _credits;
    float _gpa;
public:
    Student();
    Student(const string& name, const Date& birthday);
    Student(const string& name, const Date& birthday, const string& major);
    ~Student();
    string ToString()const override;
    void Read(istream& input) ;
    void Write(ostream& output)const;
    void AddGrade(float grade, size_t credits);
    float GetGPA()const;
    size_t GetCredits()const;

};

#endif
