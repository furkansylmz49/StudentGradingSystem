#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int number;
    float grade;

public:
    static int count;

    Student(string, int, float);
    Student();
    Student(const Student&);

    char calculateLetterGrade(float, float);
    static int getCount();
    void displayInfo();

    string getName();
    int getNumber();
    float getGrade();

    void setName(string);
    void setNumber(int);
    void setGrade(float);
};
