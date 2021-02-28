#include "class_2.h"
#include <iostream>

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

void StudentAfterSecond::SetEstimates(int a1, int b1, int c1, int d1, int e1){
  secondSession[0]=a1;
  secondSession[1]=b1;
  secondSession[2]=c1;
  secondSession[3]=d1;
  secondSession[4]=e1;

}

int StudentAfterSecond::GetEstimate2(int number){
  return secondSession[number];
}

void StudentAfterSecond::Print() {
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

}

double StudentAfterSecond::AverageEstimate() {
  return (double)(secondSession[0]+secondSession[1]+secondSession[2]+secondSession[3]+secondSession[4]+
      firstSession[0]+firstSession[1]+firstSession[2]+firstSession[3])/9;
}

int StudentAfterSecond::GetStatus(){
  return 2;
}



