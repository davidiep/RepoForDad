#include "date.h"
#include "person.h"
#include "student.h"
#include "professor.h"


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;

size_t Menu();

int main(int argc, char* argv[]) {
	vector<Person*> people; // This is the only vector you need, remember to release the memory
	int userOption;
	while ( (userOption = Menu()) != 15){
		if (userOption == 1){			// Add Person
            string name;
            int year, month, day; //Birth date yyyy mm dd:
            cout << "Name: ";
            cin >> name;
            cout << "Birth date yyyy mm dd: ";
            cin >> year >> month >> day;
            Date birthday(year, month, day);
            people.push_back(new Person(name, birthday));
            cout << "Person inserted in position: " << (people.size() - 1) << endl;
		}else if (userOption == 2){		// Add Student //
            string name, major;
            int year, month, day;
            cout << "Name: ";
            cin  >> name;
            cout << "Birth date yyyy mm dd: ";
            cin  >> year >> month >> day;
            cout << "Major: ";
            cin  >> major;
            //Date birthday(year, month, day);
            people.push_back(new Student(name, Date(year, month, day), major));
            cout << "Student inserted in position: " << (people.size() - 1) << endl;
		}else if (userOption == 3){		// Add Professor
            string name, department;
            int year, month, day, hireYear, hireMonth, hireDay;
            cout << "Name: ";
            cin  >> name;
            cout << "Birth date yyyy mm dd: ";
            cin  >> year >> month >> day;
            cout << "Department: ";
            cin  >> department;
            cout << "Hire date yyyy mm dd: ";
            cin  >> hireYear >> hireMonth >> hireDay;
            people.push_back(new Professor(name, Date(year, month, day), department, Date(hireYear, hireMonth, hireDay)));
            cout << "Professor inserted in position: " << (people.size() - 1) << endl;
		}else if (userOption == 4){		// List All People
            for (size_t i = 0; i < people.size(); ++i) {
                cout << people.at(i)->ToString() << endl;
            }
		}else if (userOption == 5){		// Show Students Report
            for (size_t i = 0; i < people.size(); ++i) {
                Student* studentPtr = dynamic_cast<Student*>(people.at(i));
                if (studentPtr) {
                    cout << studentPtr->ToString() << endl;
                }
            }
        }else if (userOption == 6){		// Show Professor Report
            for (size_t i = 0; i < people.size(); ++i) {
                Professor *profPtr = dynamic_cast<Professor *>(people.at(i));
                if (profPtr) {
                    cout << profPtr->ToString() << endl;
                }
            }
		}else if (userOption == 7){		// Show !Professor !Student
            for (size_t i = 0; i < people.size(); ++i) {
                Professor *profPtr = dynamic_cast<Professor *>(people.at(i));
                Student* studentPtr = dynamic_cast<Student*>(people.at(i));
                if (!profPtr && !studentPtr) {
                    cout << people.at(i)->ToString() << endl;
                }
            }
		}else if (userOption == 8){		// Calculate Average GPA
            float average, total = 0.0;
            size_t index = 0;
            for (size_t i = 0; i < people.size(); ++i) {
                Student* studentPtr = dynamic_cast<Student*>(people.at(i));
                if (studentPtr) {
                    total += studentPtr->GetGPA();
                    ++index;
                }
            }
            if (total == 0) {
                average = 0;
            }
            else {
                average = total / index;
            }
            cout << "The average GPA of the students is: " << average << endl;
		}else if (userOption == 9){		// Calculate Average Salary
            float average, total;
            size_t index = 0;
            for (size_t i = 0; i < people.size(); ++i) {
                Professor* profPtr = dynamic_cast<Professor*>(people.at(i));
                if (profPtr) {
                    total += profPtr->GetSalary();
                    ++index;
                }
            }
            average = total / index;
            cout << "The average salary of the professors are: " << average << endl;
		}else if (userOption == 10){	// Input Grades to Student
            size_t index;
            float grade;
            size_t credits;
            Student* studentPtr;
            for (size_t i = 0; i < people.size(); ++i) {
                studentPtr = dynamic_cast<Student*>(people.at(i));
                if (studentPtr) {
                    cout << i << " " << studentPtr->ToString() << endl;
                }
            }
            cout << "Number of student to input grades to: ";
            cin  >> index;
            while (index < 0 || index > people.size()) {
                cout << "input not in range of array, please try again." << endl;
                cin  >> index;
            }
            studentPtr = dynamic_cast<Student*>(people.at(index));
            while (!studentPtr) {
                cout << "incorrect input, please try again." << endl;
                cin >> index;
                studentPtr = dynamic_cast<Student*>(people.at(index));
            }
            cout << "Grade of the student [0.0 to 4.0 scale]: ";
            cin  >> grade;
            cout << "Credits {1, 2, 3, 4, 5}: ";
            cin  >> credits;
            studentPtr->AddGrade(grade, credits);
		}else if (userOption == 11){	// Promote Professor
            size_t index;
            Professor* profPtr;
            for (size_t i = 0; i < people.size(); ++i) {
                profPtr = dynamic_cast<Professor*>(people.at(i));
                if (profPtr) {
                    cout << i << " " << profPtr->ToString() << endl;
                }
            }
            cout << "Number of professor to promote: ";
            cin  >> index;
            while (index < 0 || index > people.size()) {
                cout << "input not in range of array, please try again." << endl;
                cin  >> index;
            }
            profPtr = dynamic_cast<Professor*>(people.at(index));
            while (!profPtr) {
                cout << "incorrect input, please try again." << endl;
                cin >> index;
                profPtr = dynamic_cast<Professor*>(people.at(index));
            }
            profPtr->Promote();
		}else if (userOption == 12){	// Give Raise to Professor
            size_t index;
            float raise;
            Professor* profPtr;
            for (size_t i = 0; i < people.size(); ++i) {
                profPtr = dynamic_cast<Professor*>(people.at(i));
                if (profPtr) {
                    cout << i << " " << profPtr->ToString() << endl;
                }
            }
            cout << "Number of professor to give raise: ";
            cin  >> index;
            while (index < 0 || index > people.size()) {
                cout << "input not in range of array, please try again." << endl;
                cin  >> index;
            }
            profPtr = dynamic_cast<Professor*>(people.at(index));
            while (!profPtr) {
                cout << "incorrect input, please try again." << endl;
                cin >> index;
                profPtr = dynamic_cast<Professor*>(people.at(index));
            }
            cout << "Raise to the professor [0.0, 50.0] ";
            cin  >> raise;
            profPtr->Raise(raise);
		}else if (userOption == 13){	// Load from File
            string fileName;
            string fileLine;
            std::ifstream file;
            cout << "Input Filename: ";
            cin  >> fileName;
            file.open(fileName);
            if (file.is_open()) {
                while (getline(file, fileLine)) {
                    if (fileLine.empty()) continue;
                    std::stringstream is(fileLine.substr(2)); // Remove the prefix to prepare for reading
                    Person* person = nullptr;

                    if (fileLine.at(0) == 'P') {
                        person = new Person();
                        person->Read(is);
                    } else if (fileLine.at(0) == 'S') {
                        person = new Student();
                        person->Read(is);
                    } else if (fileLine.at(0) == 'R') {
                        person = new Professor();
                        person->Read(is);
                    }

                    if (person) {
                        people.push_back(person);
                    }
                }
                file.close();
            } else {
                cout << "Could not open " << fileName << endl;
            }
		}else if (userOption == 14){	// Write to File
            string fileName;
            std::ofstream file;
            cout << "Output filename: ";
            cin >> fileName;
            file.open(fileName);
            if (file.is_open()) {
                for (size_t i = 0; i < people.size(); ++i) {
                    Student* studentPtr = dynamic_cast<Student*>(people.at(i));
                    Professor* profPtr = dynamic_cast<Professor*>(people.at(i));
                    if (studentPtr) {
                        file << "S ";
                        studentPtr->Write(file);
                    }
                    else if (profPtr) {
                        file << "R ";
                        profPtr->Write(file);
                    }
                    else {
                        file << "P ";
                        people.at(i)->Write(file);
                    }
                    file << endl;
                }
            }
            else {
                cout << "Could not open " << fileName << endl;
            }
		}
	}
	return 0;
}

size_t Menu(){
	int option = 0;
	while(true){
		cout << "-------------------------------------------" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Add a Student" << endl;
		cout << "3. Add a Professor" << endl;
		cout << "4. List all People" << endl;
		cout << "5. Show Students Report" << endl;
		cout << "6. Show Professors Report" << endl;
		cout << "7. Show People (not Professors or Students)" << endl;
		cout << "8. Calculate all Students Average GPA" << endl;
		cout << "9. Calculate all Professors Average Salary" << endl;
		cout << "10. Input Grades to Student" << endl;
		cout << "11. Promote Professor" << endl;
		cout << "12. Give Raise to Professor" << endl;
		cout << "13. Load Data from File" << endl;
		cout << "14. Write Data to File" << endl;
		cout << "15. Exit" << endl;

		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Incorrect input!" << endl;
			continue;
		}
		if (option < 1 || option > 15){
			cerr << "Incorrect menu option!" << endl;
			continue;
		}
		break;
	}
	cout << endl;
	return static_cast<size_t>(option);
}
