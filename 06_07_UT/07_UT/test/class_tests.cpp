#include <gtest/gtest.h>
#include "class.h"

TEST(FunctionCheckStudent, GetId)
{
    Student A("A",1,2,3);
    EXPECT_EQ(A.GetId(),1);
}

TEST(ConstructorCheckStudent, Fraction1)
{
    Student A("A",1,2,3);
    EXPECT_EQ(A.name,"A");
    EXPECT_EQ(A.course,1);
    EXPECT_EQ(A.group,2);
    EXPECT_EQ(A.GetNumber(),3);
}

TEST(CopyConstructorCheckStudent, Fraction2)
{
    Student A("A",1,2,3);
    Student B(A);
    EXPECT_EQ(B.name,"A");
    EXPECT_EQ(B.course,1);
    EXPECT_EQ(B.group,2);
    EXPECT_EQ(B.GetNumber(),3);
}



TEST(FunctionCheckStudent, GetNumber)
{
    Student A("A",1,2,3);
    EXPECT_EQ(A.GetNumber(),3);
}

TEST(FunctionCheckStudent, GetName)
{
    Student A("A",1,2,3);
    EXPECT_EQ(A.GetName(),"A");
}

TEST(FunctionCheckStudent, GetCourse)
{
    Student A("A",1,2,3);
    EXPECT_EQ(A.GetCourse(),1);
}

TEST(FunctionCheckStudent, GetGroup)
{
    Student A("A",1,2,3);
    EXPECT_EQ(A.GetGroup(),2);
}

TEST(FunctionCheckStudent, SetName)
{
    Student A("A",1,2,3);
    A.SetName("BB");
    EXPECT_EQ(A.GetName(),"BB");
}

TEST(FunctionCheckStudent, SetCourse)
{
    Student A("A",1,2,3);
    A.SetCourse(5);
    EXPECT_EQ(A.GetCourse(),5);
}

TEST(FunctionCheckStudent, SetGroup)
{
    Student A("A",1,2,3);
    A.SetGroup(5);
    EXPECT_EQ(A.GetGroup(),5);
}

TEST(FunctionCheckStudent, AverageEstimate)
{
    Student A("A",1,2,3);
    EXPECT_EQ(A.AverageEstimate(),0);
}

TEST(FunctionCheckStudent, GetStatus)
{
    Student A("A",1,2,3);
    EXPECT_EQ(A.GetStatus(),0);
}


TEST(ConstructorCheckStudent1, Fraction1)
{
    StudentAfterFirst A("B",2,3,4,5,6,7,8);
    EXPECT_EQ(A.name,"B");
    EXPECT_EQ(A.course,2);
    EXPECT_EQ(A.group,3);
    EXPECT_EQ(A.GetNumber(),4);
    EXPECT_EQ(A.firstSession[0],5);
    EXPECT_EQ(A.firstSession[1],6);
    EXPECT_EQ(A.firstSession[2],7);
    EXPECT_EQ(A.firstSession[3],8);
}

TEST(CopyConstructorCheckStudent1, Fraction2)
{
    StudentAfterFirst B("B",2,3,4,5,6,7,8);
    StudentAfterFirst A(B);
    EXPECT_EQ(A.name,"B");
    EXPECT_EQ(A.course,2);
    EXPECT_EQ(A.group,3);
    EXPECT_EQ(A.GetNumber(),4);
    EXPECT_EQ(A.firstSession[0],5);
    EXPECT_EQ(A.firstSession[1],6);
    EXPECT_EQ(A.firstSession[2],7);
    EXPECT_EQ(A.firstSession[3],8);
}

TEST(FunctionCheckStudent1, GetId1)
{
    Student A("A",1,2,3);
    StudentAfterFirst B("B",2,3,4,5,6,7,8);
    EXPECT_NE(B.GetId(),0);
}

TEST(FunctionCheckStudent1, AverageEstimate1)
{
    StudentAfterFirst B("B",2,3,4,5,6,7,8);
    EXPECT_EQ(B.AverageEstimate(),6.5);
}

TEST(FunctionCheckStudent1, GetEstimate)
{
    StudentAfterFirst B("B",2,3,4,5,6,7,8);
    EXPECT_EQ(B.GetEstimate(0),5);
}

TEST(FunctionCheckStudent1, GetStatus1)
{
    StudentAfterFirst B("B",2,3,4,5,6,7,8);
    EXPECT_EQ(B.GetStatus(),1);
}


TEST(ConstructorCheckStudent2, Fraction1)
{
    StudentAfterSecond A("B",2,3,4,5,6,7,8,9,10,10,10,10);
    EXPECT_EQ(A.name,"B");
    EXPECT_EQ(A.course,2);
    EXPECT_EQ(A.group,3);
    EXPECT_EQ(A.GetNumber(),4);
    EXPECT_EQ(A.firstSession[0],5);
    EXPECT_EQ(A.firstSession[1],6);
    EXPECT_EQ(A.firstSession[2],7);
    EXPECT_EQ(A.firstSession[3],8);
    EXPECT_EQ(A.secondSession[0],9);
    EXPECT_EQ(A.secondSession[1],10);
    EXPECT_EQ(A.secondSession[2],10);
    EXPECT_EQ(A.secondSession[3],10);
    EXPECT_EQ(A.secondSession[4],10);
}

TEST(CopyConstructorCheckStudent2, Fraction2)
{
    StudentAfterSecond B("B",2,3,4,5,6,7,8,9,10,10,10,10);
    StudentAfterSecond A(B);
    EXPECT_EQ(A.name,"B");
    EXPECT_EQ(A.course,2);
    EXPECT_EQ(A.group,3);
    EXPECT_EQ(A.GetNumber(),4);
    EXPECT_EQ(A.firstSession[0],5);
    EXPECT_EQ(A.firstSession[1],6);
    EXPECT_EQ(A.firstSession[2],7);
    EXPECT_EQ(A.firstSession[3],8);
    EXPECT_EQ(A.secondSession[0],9);
    EXPECT_EQ(A.secondSession[1],10);
    EXPECT_EQ(A.secondSession[2],10);
    EXPECT_EQ(A.secondSession[3],10);
    EXPECT_EQ(A.secondSession[4],10);
}

TEST(FunctionCheckStudent2, GetNumber1)
{
    StudentAfterSecond B("B",2,3,4,5,6,7,8,9,10,10,10,10);
    EXPECT_EQ(B.GetNumber(),4);
}

TEST(FunctionCheckStudent2, GetEstimate2)
{
    StudentAfterSecond B("B",2,3,4,5,6,7,8,9,10,10,10,10);
    EXPECT_EQ(B.GetEstimate2(0),9);
}

TEST(FunctionCheckStudent2, AverageEstimate2)
{
    StudentAfterSecond B("B",2,3,4,5,6,10,10,10,10,10,10,10);
    EXPECT_EQ(B.AverageEstimate(),9);
}

TEST(FunctionCheckStudent2, GetStatus2)
{
    StudentAfterSecond B("B",2,3,4,5,6,10,10,10,10,10,10,10);
    EXPECT_EQ(B.GetStatus(),2);
}

TEST(FunctionCheckStudent, Print)
{
    Student A("A",1,2,3);
    EXPECT_EQ(A.Print(),"Name of the Student: A, his/her id: 11, his/her course number: 1, his/her group number: 2, his/her student number: 3");
}

TEST(OperatorCheckStudent, Operat)
{
    Student A("A",1,2,3);
    std::stringstream out;
    std::string a;
    std::string b;
    out<<A;
    while (out>>b){
        a = a  + b + " ";
    }
    EXPECT_EQ(a,"Name of the Student: A, his/her id: 30, his/her course number: 1, his/her group number: 2, his/her student number: 3 ");
}

<<<<<<< HEAD
TEST (Function1, GroupAverageEstimate) {
  Student* student[6];
  student[0]= new Student("Aa",1,1,100);
  student[1]= new Student("Bb",1,2,101);
  student[2]= new StudentAfterFirst("Ddd",1,2,1000,5,5,5,5);
  student[3]= new StudentAfterFirst("Eee",1,4,1001,6,6,6,6);
  student[4]= new StudentAfterSecond("X1",2,5,11,7,7,8,9,4,7,7,8,6);
  student[5]= new StudentAfterSecond("Y1",3,5,12,5,7,6,7,4,8,4,9,4);
  double average1 = GroupAverageEstimate(student, 2,1);
  double average2 = GroupAverageEstimate(student, 5,2);
  EXPECT_EQ(average1, 5);
  EXPECT_EQ(average2, 6.5);
  CleanMemory(student);
}

TEST (Function2, AverageEstimateOfStudents) {
  Student* student[6];
  student[0]= new Student("Aa",1,1,100);
  student[1]= new Student("Bb",1,2,101);
  student[2]= new StudentAfterFirst("Ddd",1,2,1000,10,10,10,10);
  student[3]= new StudentAfterFirst("Eee",1,4,1001,10,10,10,10);
  student[4]= new StudentAfterSecond("X1",2,5,11,10,10,10,10,10,10,10,5,6);
  student[5]= new StudentAfterSecond("Y1",3,5,12,10,10,10,10,10,10,10,10,10);
  double average = AverageEstimateOfStudents(student);
  std::cout <<average<<std::endl;
  EXPECT_EQ(average, 6.5);
  CleanMemory(student);
}


=======
>>>>>>> UT(06)_UT(07)


