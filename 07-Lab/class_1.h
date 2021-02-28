#include "class.h"
#include <iostream>
#ifndef INC_07_LAB__CLASS_1_H_
#define INC_07_LAB__CLASS_1_H_

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
  virtual void Print();
};

#endif //INC_07_LAB__CLASS_1_H_
