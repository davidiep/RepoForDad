/*
 * Title:		X X X X X X X X X
 * Purpose:		P P P P P P P P P
 * Author:		Master Shifu
 * Date:		Mmm DD, YYYY
 */

#ifndef SCHOOL_INHERITANCE_PROFESSOR_H
#define SCHOOL_INHERITANCE_PROFESSOR_H

#include "date.h"
enum Rank {ASSISTANT_PROFESSOR, ASSOCIATE_PROFESSOR, PROFESSOR};
class Professor : public Person {
private:
    string _department;
    Date _hireDate;
    Rank _rank;
    float _salary;
public:
    Professor();
    Professor(const string& name, const Date& birthday, const string& department);
    Professor(const string& name, const Date& birthday, const string& department, const Date & hireDate);
    Professor(const string& name, const Date& birthday, const string& department, const Date& hireDate, Rank rank, float salary);
    ~Professor();
    string ToString()const;
    void Read(istream& input);
    void Write(ostream& output)const;
    void Raise(float percentage);
    void Promote();
    Rank GetRank()const;
    float GetSalary()const;
};
#endif
