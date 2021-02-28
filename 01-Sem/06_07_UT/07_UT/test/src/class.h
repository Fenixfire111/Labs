#pragma once
#include <iostream>
#ifndef INC_07_LAB_CLASS_H
#define INC_07_LAB_CLASS_H

class Student{
private:
    int id;
    int number;
public:
    char* name;
    int course;
    int group;
    Student(char* name1, int course1, int group1, int number1);
    Student (Student& student);
    int GetId();
    int GetNumber();
    char* GetName();
    int GetCourse();
    int GetGroup();
    void SetName(char* name1);
    void SetCourse(int course1);
    void SetGroup(int group1);
    friend std::ostream & operator<< (std::ostream &out, Student &student);
    virtual std::string Print();
    virtual double AverageEstimate();
    virtual int GetStatus();
};

class StudentAfterFirst: public Student{
private:

public:
    int firstSession[4];
    StudentAfterFirst(char* name1, int course1, int group1, int number1,int a, int b, int c, int d);
    StudentAfterFirst (StudentAfterFirst& student);
    void SetEstimates(int a, int b, int c, int d);
    int GetEstimate(int number);
    friend std::ostream & operator<< (std::ostream &out, StudentAfterFirst &student);
    virtual double AverageEstimate();
    virtual int GetStatus();
    virtual std::string Print();
};

class StudentAfterSecond: public StudentAfterFirst{
private:

public:
    StudentAfterSecond(char* name1, int course1, int group1, int number1,int a, int b, int c, int d, int a1, int b1, int c1,int d1, int e1);
    StudentAfterSecond(StudentAfterSecond& student);
    void SetEstimates(int a1, int b1, int c1, int d1, int e1);
    int secondSession[5];
    int GetEstimate2(int number);
    friend std::ostream & operator<< (std::ostream &out, StudentAfterSecond &student);
    double AverageEstimate();
    int GetStatus();
    std::string Print();
};

double GroupAverageEstimate(Student** student1, int numberGroup, int numberSession);
double AverageEstimateOfStudents(Student** student1);
void CleanMemory(Student** cont);

#endif //INC_07_LAB_CLASS_H
