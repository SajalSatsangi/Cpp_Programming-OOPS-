#include <iostream>
using namespace std;

class student
{
    string name;
    int roll;
    double cgpa;

public:
    static string clgname;

    student(int roll, string name, double cgpa)
    {
        this->roll = roll;
        this->name = name;
        this->cgpa = cgpa;
    }

    void display();

    // static void display();

    static void Display()
    {
        cout << "ClgName : " << clgname << endl;
    }
};
void student::display()
{
    cout << "roll number: " << roll << "name: " << name << "cgpa" << cgpa << endl;
}

string student::clgname = "DEI";

int main()
{
    student stu1(101, "rashmi", 8.9);
    student stu2(102, "rashmi", 8.9);
    student stu3(102, "rashmi", 8.9);
   
  
    student::Display();
    stu1.display();
    student::Display();
    stu2.display();
    student::Display();
    stu3.display();
}