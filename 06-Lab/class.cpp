#include <iostream>
#include "class.h"
    void Fraction::Check(){
        if (!denominator){
            std::cout<<"Denominator is 0"<<std::endl;
            exit(0);
        }
    }
    void Fraction::Reduction(){
        int a(numerator), b(denominator);
        if(a<0){
            a=-a;
        }
        if(b<0){
            b=-b;
        }
        while(a!=0 && b!=0){
            if(a>b){
                a=a%b;
            }
            else{
                b=b%a;
            }
        }
        int nod;
        nod=a+b;
        numerator=numerator/nod;
        denominator=denominator/nod;
        if(denominator<0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
Fraction::Fraction(int A, int B){
        if(B){
            numerator = A;
            denominator = B;
            Reduction();
        }
    }
Fraction::Fraction (Fraction& x){
        numerator=x.numerator;
        denominator=x.denominator;
    }
    void Fraction::DataInput() {
        std::cout << "Enter numerator: ";
        std::cin >> numerator;
        std::cout << "Enter denominator: ";
        std::cin >> denominator;
        Check();
        Reduction();
    }
    int Fraction::GetNum(){
        return numerator;
    }

    int Fraction::GetDen(){
        return denominator;
    }
    Fraction Fraction::Multiplication(Fraction factor){
        Fraction composition(1,1);
        composition.numerator=numerator*factor.numerator;
        composition.denominator=denominator*factor.denominator;
        composition.Reduction();
        return composition;
    }
    Fraction Fraction::Addition(Fraction factor){
        Fraction sum(1,1);
        sum.numerator=numerator*factor.denominator+factor.numerator*denominator;
        sum.denominator=denominator*factor.denominator;
        sum.Reduction();
        return sum;
    }
    Fraction Fraction::Division(Fraction factor){
        Fraction quotient(1,1);
        quotient.numerator=numerator*factor.denominator;
        quotient.denominator=denominator*factor.numerator;
        quotient.Reduction();
        return quotient;
    }
    void Fraction::DataOutput() {
        int integer=(numerator/denominator);
        if((abs(numerator) >= abs(denominator)) || (numerator==0)){
            std::cout<<integer;
            std::cout<<' ';
        }
        if((numerator-integer*denominator)!=0){
            std::cout << (numerator-integer*denominator) << '/' << denominator;
        }
        std::cout<< std::endl;
    }
