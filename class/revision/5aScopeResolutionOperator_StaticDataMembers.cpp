#include <iostream>
using namespace std;

class Student
{
    int roll;
    string name;
    double cgpa;

public:
    static string clgname; // it is use to define the values which are same for all objects

    Student(int roll, string name, double cgpa)
    {
        this->roll = roll;
        this->name = name;
        this->cgpa = cgpa;
    }

    void display();
};
void Student ::display() // scope resolution operator also use to define function of a class outside the class
{
    cout << "Roll No. : " << roll << " Name : " << name << " CGPA : " << cgpa << " and clg name" << clgname << endl;
}

string Student ::clgname = "DEI"; // it is have to initialise outside the class

int main()
{
    Student stu1(101, "Karan Sharma", 8.9);
    Student stu2(102, "Karan Sharma", 4.7);
    Student stu3(103, "Karan Sharma", 7.3);

    stu1.display();
    stu2.display();
    stu3.display();

    // cout << Student ::clgname << endl; // we can access static members directly using class name and scope resolution oprater
    return 0;
}

// static member function -> it is use to define static funtion in this fuction we only use static members.