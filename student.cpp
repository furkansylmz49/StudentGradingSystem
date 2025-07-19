#include <iostream>
#include <string>
#include "student.h"
using namespace std;

int Student::count = 0;

Student::Student(string name, int number, float grade) {
    this->name = name;
    this->number = number;
    this->grade = grade;
    Student::count++;
}

Student::Student() {
    this->name = "Unknown";
    this->number = 0;
    this->grade = 0;
}

Student::Student(const Student& other) {
    name = other.name;
    number = other.number;
    grade = other.grade;
    Student::count++;
}

void Student::displayInfo() {
    cout << "Name: " << name << endl;
    cout << "Student Number: " << number << endl;
    cout << "Grade: " << grade << endl;
}

char Student::calculateLetterGrade(float average, float stdDev) {
    if (grade <= average - (3 * stdDev) / 2) return 'F';
    else if (grade <= average - stdDev / 2) return 'D';
    else if (grade <= average + stdDev / 2) return 'C';
    else if (grade <= average + (3 * stdDev) / 2) return 'B';
    else return 'A';
}

int Student::getCount() { return Student::count; }
string Student::getName() { return name; }
int Student::getNumber() { return number; }
float Student::getGrade() { return grade; }

void Student::setName(string name) { this->name = name; }
void Student::setNumber(int number) { this->number = number; }
void Student::setGrade(float grade) { this->grade = grade; }
