#include "class_1.h"
#include <iostream>

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

void StudentAfterFirst::SetEstimates(int a, int b, int c, int d){
  firstSession[0]=a;
  firstSession[1]=b;
  firstSession[2]=c;
  firstSession[3]=d;

}

int StudentAfterFirst::GetEstimate(int number){
  return firstSession[number];
}

void StudentAfterFirst::Print() {
  std::cout << "Name of the Student: " << name << ", his/her id: " << GetId() <<", his/her course number: " << course << "\n";
  std::cout <<", his/her group number: "<< group << ", his/her student number: " << GetNumber()<< "\n";
  std::cout <<"Estimates for the first semester:"<< "\n";
  for (int i=0; i<4;++i){
    std::cout << firstSession[i] << "\n";
  }
}

double StudentAfterFirst::AverageEstimate() {
  return (double)(firstSession[0]+firstSession[1]+firstSession[2]+firstSession[3])/4;
}

int StudentAfterFirst::GetStatus(){
  return 1;
}



