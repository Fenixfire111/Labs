#include "class_1.h"
#include <iostream>
#ifndef INC_07_LAB__CLASS_2_H_
#define INC_07_LAB__CLASS_2_H_

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
  void Print();
};

#endif //INC_07_LAB__CLASS_2_H_
