#include <iostream>
#include "class.h"
#include <array>
double GroupAverageEstimate(Student** student1, int numberGroup, int numberSession){
    double sum=0;
    double count=0;
    if (numberSession==1){
        for (int i=0; i<9;++i){
            if (student1[i]->group==numberGroup && student1[i]->GetStatus()==1){
                sum+=student1[i]->AverageEstimate();
                ++count;
            }
        }
    } else if (numberSession==2){
        for (int i=0; i<9;++i){
            if (student1[i]->group==numberGroup && student1[i]->GetStatus()==2){
                sum+=student1[i]->AverageEstimate();
                ++count;
            }
        }
    }
    return sum/count;
}
double AverageEstimateOfStudents(Student** student1){
    double sum=0;
    for (int i=0; i<9;++i){
        sum+=student1[i]->AverageEstimate();
    }
    return sum/9;
}
int main() {
    Student* student[9];
    student[0]= new Student("Aa",1,1,100);
    student[1]= new Student("Bb",1,2,101);
    student[2]= new Student("Cc",1,3,256);
    student[3]= new StudentAfterFirst("Ddd",1,2,1000,5,5,5,5);
    student[4]= new StudentAfterFirst("Eee",1,4,1001,6,6,6,6);
    student[5]= new StudentAfterFirst("Fff",1,2,3569,10,7,7,7);
    student[6]= new StudentAfterSecond("X1",2,5,11,7,7,7,7,4,4,4,4,4);
    student[7]= new StudentAfterSecond("Y1",3,5,12,5,7,6,7,4,8,4,9,4);
    student[8]= new StudentAfterSecond("Z1",4,5,123,9,0,9,7,5,6,6,7,9);
    std::cout <<GroupAverageEstimate(student,2,1)<<std::endl;
    std::cout <<GroupAverageEstimate(student,5,2)<<std::endl;
    std::cout <<AverageEstimateOfStudents(student)<<std::endl;
    std::cout <<*student[8]<<std::endl;
    return 0;
}
