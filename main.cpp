#include <iostream>
#include <string>
#include <cmath>
#include "student.h"
using namespace std;

int main() {
    Student students[100];
    string name;
    int number, searchNumber, choice, gradeQueryNumber;
    const int max = 100;
    bool found;
    float grade, average, total = 0, stdDev = 0;

    do {
        cout << "----- GRADE TRACKING SYSTEM -----" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. List All Students" << endl;
        cout << "3. Search Student by Number" << endl;
        cout << "4. Calculate Letter Grades Based on Standard Deviation" << endl;
        cout << "5. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Welcome to the Add Student Menu." << endl;

                if (Student::getCount() >= max) {
                    cout << "Maximum number of students reached." << endl;
                } else {
                    cout << "Please enter student details." << endl;
                    cout << "Name: ";
                    cin >> name;
                    cout << "Number: ";
                    cin >> number;
                    cout << "Grade: ";
                    cin >> grade;

                    students[Student::getCount()-1] = Student(name, number, grade);

                    cout << "Student successfully added to the system." << endl;
                }
                break;

            case 2:
                cout << "Welcome to the List Students Menu." << endl;
                for (int i = 0; i < Student::getCount(); i++) {
                    cout << i + 1 << ". Student -> " << students[i].getName() << endl;
                    cout << "----------------" << endl;
                }
                cout << "Listing completed successfully." << endl;
                break;

            case 3:
                cout << "Welcome to the Student Search Menu." << endl;
                cout << "Enter the number of the student you're searching for: ";
                cin >> searchNumber;

                found = false;

                for (int i = 0; i < Student::getCount(); i++) {
                    if (searchNumber == students[i].getNumber()) {
                        cout << searchNumber << " -> Student Name: " << students[i].getName() << endl;
                        found = true;
                    }
                }

                if (!found) {
                    cout << "No student found with the given number." << endl;
                }

                cout << "Search completed." << endl;
                break;

            case 4:
                cout << "Welcome to the Letter Grade Menu." << endl;
                cout << "Enter the student number to see their letter grade: ";
                cin >> gradeQueryNumber;

                total = 0;
                for (int i = 0; i < Student::getCount(); i++) {
                    total += students[i].getGrade();
                }

                average = total / Student::getCount();

                stdDev = 0;
                for (int i = 0; i < Student::getCount(); i++) {
                    stdDev += pow((students[i].getGrade() - average), 2);
                }
                stdDev = sqrt(stdDev);

                for (int i = 0; i < Student::getCount(); i++) {
                    if (gradeQueryNumber == students[i].getNumber()) {
                        cout << gradeQueryNumber << " -> Letter Grade: "
                             << students[i].calculateLetterGrade(average, stdDev) << endl;
                    }
                }

                cout << "Letter grade calculation completed." << endl;
                break;

            default:
                if (choice != 5)
                    cout << "Invalid selection. Please enter a number between 1 and 5." << endl;
        }

    } while (choice != 5);

    return 0;
}
