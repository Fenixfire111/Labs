#include <iostream>
#include "class.h"

int main() {
    Fraction fraction1(1,1),fraction2(1,1);
    fraction1.DataInput();
    fraction2.DataInput();
    Fraction fractionM(1,1),fractionD(1,1),fractionA(1,1);

    fractionM=fraction1.Multiplication(fraction2);
    std::cout<<" Result of Multiplication"<<std::endl;
    fractionM.DataOutput();

    fractionD=fraction1.Division(fraction2);
    std::cout<<" Result of Division"<<std::endl;
    fractionD.DataOutput();

    fractionA=fraction1.Addition(fraction2);
    std::cout<<" Result of Addition"<<std::endl;
    fractionA.DataOutput();
    return 0;
}