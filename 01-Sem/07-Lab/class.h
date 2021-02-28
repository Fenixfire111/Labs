#include <iostream>
#ifndef INC_07_LAB_CLASS_H
#define INC_07_LAB_CLASS_H
class Student{
private:
    const int id = 0;
    const int number;
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
    virtual void Print();
    virtual double AverageEstimate();
    virtual int GetStatus();
};
#endif //INC_07_LAB_CLASS_H
