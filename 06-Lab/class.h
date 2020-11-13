#include <iostream>

#ifndef INC_06_LAB_CLASS_H
#define INC_06_LAB_CLASS_H
class Fraction{
private:
    void Check();
    void Reduction();
public:
    int numerator;
    int denominator;
    Fraction(int A, int B);
    Fraction (Fraction& x);
    void DataInput();
    int GetNum();
    int GetDen();
    Fraction Multiplication(Fraction factor);
    Fraction Addition(Fraction factor);
    Fraction Division(Fraction factor);
    void DataOutput();
};
#endif
