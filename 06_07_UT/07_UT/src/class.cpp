#include "class.h"
#include <iostream>
static int count=0;
Student::Student (char* name1, int course1, int group1, int number1){
    name=name1;
    course=course1;
    group=group1;
    number=number1;
    count++;
    id=count;
}

Student::Student (Student& student){
    name=student.name;
    course=student.course;
    group=student.group;
    number=student.number;
    count++;
    id=count;
}

StudentAfterFirst::StudentAfterFirst(char* name1, int course1, int group1, int number1,int a, int b, int c, int d):Student(name1, course1, group1, number1){
    firstSession[0]=a;
    firstSession[1]=b;
    firstSession[2]=c;
    firstSession[3]=d;
}

StudentAfterFirst::StudentAfterFirst(StudentAfterFirst& student):Student( student){
    firstSession[0]=student.firstSession[0];
    firstSession[1]=student.firstSession[1];
    firstSession[2]=student.firstSession[2];
    firstSession[3]=student.firstSession[3];
}

StudentAfterSecond::StudentAfterSecond(char* name1, int course1, int group1, int number1,int a, int b, int c, int d, int a1, int b1, int c1,int d1, int e1):StudentAfterFirst(name1, course1, group1, number1, a, b, c, d){
    secondSession[0]=a1;
    secondSession[1]=b1;
    secondSession[2]=c1;
    secondSession[3]=d1;
    secondSession[4]=e1;
}

StudentAfterSecond::StudentAfterSecond(StudentAfterSecond& student):StudentAfterFirst( student){
        secondSession[0]=student.secondSession[0];
        secondSession[1]=student.secondSession[1];
        secondSession[2]=student.secondSession[2];
        secondSession[3]=student.secondSession[3];
        secondSession[4]=student.secondSession[4];
}


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

void StudentAfterFirst::SetEstimates(int a, int b, int c, int d){
    firstSession[0]=a;
    firstSession[1]=b;
    firstSession[2]=c;
    firstSession[3]=d;

}

void StudentAfterSecond::SetEstimates(int a1, int b1, int c1, int d1, int e1){
    secondSession[0]=a1;
    secondSession[1]=b1;
    secondSession[2]=c1;
    secondSession[3]=d1;
    secondSession[4]=e1;

}

int StudentAfterFirst::GetEstimate(int number){
    return firstSession[number];
}

int StudentAfterSecond::GetEstimate2(int number){
    return secondSession[number];
}


std::string Student::Print() {
    std::cout << "Name of the Student: " << name << ", his/her id: " << GetId() <<", his/her course number: " << course << "\n";
    std::cout <<", his/her group number: "<< group << ", his/her student number: " << GetNumber()<< "\n";
    std::string s = "Name of the Student: ";
    std::string s1 = name;
    s.append(s1);
    s1 = ", his/her id: ";
    s.append(s1);
    s1 = std::to_string(GetId());
    s.append(s1);
    s1 = ", his/her course number: ";
    s.append(s1);
    s1 = std::to_string(course);
    s.append(s1);
    s1 = ", his/her group number: ";
    s.append(s1);
    s1 = std::to_string(group);
    s.append(s1);
    s1 = ", his/her student number: ";
    s.append(s1);
    s1 = std::to_string(GetNumber());
    s.append(s1);
    return s;
}

std::string StudentAfterFirst::Print() {
    std::cout << "Name of the Student: " << name << ", his/her id: " << GetId() <<", his/her course number: " << course << "\n";
    std::cout <<", his/her group number: "<< group << ", his/her student number: " << GetNumber()<< "\n";
    std::cout <<"Estimates for the first semester:"<< "\n";
    for (int i=0; i<4;++i){
        std::cout << firstSession[i] << "\n";
    }
    std::string s = "Name of the Student: ";
    std::string s1 = name;
    s.append(s1);
    s1 = ", his/her id: ";
    s.append(s1);
    s1 = std::to_string(GetId());
    s.append(s1);
    s1 = ", his/her course number: ";
    s.append(s1);
    s1 = std::to_string(course);
    s.append(s1);
    s1 = ", his/her group number: ";
    s.append(s1);
    s1 = std::to_string(group);
    s.append(s1);
    s1 = ", his/her student number: ";
    s.append(s1);
    s1 = std::to_string(GetNumber());
    s.append(s1);
    s1 = "Estimates for the first semester:";
    s.append(s1);
    s1 = std::to_string(firstSession[0]);
    s.append(s1);
    s1 = " ";
    s.append(s1);
    s1 = std::to_string(firstSession[1]);
    s.append(s1);
    s1 = " ";
    s.append(s1);
    s1 = std::to_string(firstSession[2]);
    s.append(s1);
    s1 = " ";
    s.append(s1);
    s1 = std::to_string(firstSession[3]);
    s.append(s1);
    return s;
}

std::string StudentAfterSecond::Print() {
    std::cout << "Name of the Student: " << name << ", his/her id: " << GetId() <<", his/her course number: " << course << "\n";
    std::cout <<", his/her group number: "<< group << ", his/her student number: " << GetNumber()<< "\n";
    std::cout <<"Estimates for the first semester:"<< "\n";
    for (int i=0; i<4;++i){
        std::cout << firstSession[i] << "\n";
    }
    std::cout <<"Estimates for the second semester:"<< "\n";
    for (int i=0; i<5;++i){
        std::cout << secondSession[i] << "\n";
    }
    std::string s = "Name of the Student: ";
    std::string s1 = name;
    s.append(s1);
    s1 = ", his/her id: ";
    s.append(s1);
    s1 = std::to_string(GetId());
    s.append(s1);
    s1 = ", his/her course number: ";
    s.append(s1);
    s1 = std::to_string(course);
    s.append(s1);
    s1 = ", his/her group number: ";
    s.append(s1);
    s1 = std::to_string(group);
    s.append(s1);
    s1 = ", his/her student number: ";
    s.append(s1);
    s1 = std::to_string(GetNumber());
    s.append(s1);
    s1 = "Estimates for the first semester:";
    s.append(s1);
    s1 = std::to_string(firstSession[0]);
    s.append(s1);
    s1 = " ";
    s.append(s1);
    s1 = std::to_string(firstSession[1]);
    s.append(s1);
    s1 = " ";
    s.append(s1);
    s1 = std::to_string(firstSession[2]);
    s.append(s1);
    s1 = " ";
    s.append(s1);
    s1 = std::to_string(firstSession[3]);
    s.append(s1);
    s1 = " ";
    s.append(s1);
    s1 = std::to_string(secondSession[0]);
    s.append(s1);
    s1 = " ";
    s.append(s1);
    s1 = std::to_string(secondSession[1]);
    s.append(s1);
    s1 = " ";
    s.append(s1);
    s1 = std::to_string(secondSession[2]);
    s.append(s1);
    s1 = " ";
    s.append(s1);
    s1 = std::to_string(secondSession[3]);
    s.append(s1);
    s1 = " ";
    s.append(s1);
    s1 = std::to_string(secondSession[4]);
    s.append(s1);
    return s;
}


std::string & operator<< (std::ostream &out, Student &student){
    std::string s=student.Print();
    return s;
}


double Student::AverageEstimate() {
    return 0;
}

double StudentAfterFirst::AverageEstimate() {
    return (double)(firstSession[0]+firstSession[1]+firstSession[2]+firstSession[3])/4;
}

double StudentAfterSecond::AverageEstimate() {
    return (double)(secondSession[0]+secondSession[1]+secondSession[2]+secondSession[3]+secondSession[4]+
            firstSession[0]+firstSession[1]+firstSession[2]+firstSession[3])/9;
}


int Student::GetStatus(){
    return 0;
}
int StudentAfterFirst::GetStatus(){
    return 1;
}
int StudentAfterSecond::GetStatus(){
    return 2;
}


