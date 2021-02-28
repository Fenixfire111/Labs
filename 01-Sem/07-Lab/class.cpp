#include "class.h"
#include <iostream>

Student::Student (char* name1, int course1, int group1, int number1)
                 : name(name1), course(course1), group(group1), number(number1), id(id+1){}

Student::Student (Student& student): name(student.name), course(student.course), group(student.group),
                                     number(student.number), id(id+1){}

int Student::GetId(){
    return id;
}
int Student::GetNumber(){
    return number;
}
char* Student::GetName(){
    return name;
}
int Student::GetCourse(){
    return course;
}
int Student::GetGroup(){
    return group;
}
void Student::SetName(char* name1){
    name = name1;
}
void Student::SetCourse(int course1){
    course = course1;
}
void Student::SetGroup(int group1){
    group = group1;
}

void Student::Print() {
    std::cout << "Name of the Student: " << name << ", his/her id: " << GetId() <<", his/her course number: " << course << "\n";
    std::cout <<", his/her group number: "<< group << ", his/her student number: " << GetNumber()<< "\n";
}

std::ostream & operator<< (std::ostream &out, Student &student){
    student.Print();
    return out;
}

double Student::AverageEstimate() {
    return 0;
}

int Student::GetStatus(){
    return 0;
}



