#include <gtest/gtest.h>
#include "class.h"

TEST(CopyConstructorCheck, Fraction1)
{
    Fraction a(2,2);
    Fraction b(a);
    EXPECT_EQ(a.numerator,b.numerator);
    EXPECT_EQ(a.denominator,b.denominator);
}

TEST(ConstructorCheck, Fraction2)
{
    Fraction a(3,2);
    EXPECT_EQ(a.numerator,3);
    EXPECT_EQ(a.denominator,2);
}

TEST(FunctionCheck, Reduction)
{
    Fraction a(2,2);
    EXPECT_EQ(a.numerator,1);
    EXPECT_EQ(a.denominator,1);
}

TEST(FunctionCheck, GetNum)
{
    Fraction a(1,2);
    EXPECT_EQ(a.GetNum(),1);
}

TEST(FunctionCheck, GetDen)
{
    Fraction a(1,2);
    EXPECT_EQ(a.GetDen(),2);
}

TEST(FunctionCheck, Multiplication1)
{
    Fraction a(1,3);
    Fraction b(-2,3);
    Fraction m(1,1);
    m=a.Multiplication(b);
    EXPECT_EQ(m.numerator,-2);
    EXPECT_EQ(m.denominator,9);
}

TEST(FunctionCheck, Multiplication2)
{
    Fraction a(0,3);
    Fraction b(-2,3);
    Fraction m(1,2);
    m=a.Multiplication(b);
    EXPECT_EQ(m.numerator,0);
    EXPECT_EQ(m.denominator,1);
}

TEST(FunctionCheck, Addition)
{
    Fraction a(1,3);
    Fraction b(2,3);
    Fraction m(1,1);
    m=a.Addition(b);
    EXPECT_EQ(m.numerator,1);
    EXPECT_EQ(m.denominator,1);
}

TEST(FunctionCheck, Addition1)
{
    Fraction a(1,3);
    Fraction b(-2,3);
    Fraction m(1,1);
    m=a.Addition(b);
    EXPECT_EQ(m.numerator,-1);
    EXPECT_EQ(m.denominator,3);
}

TEST(FunctionCheck, Addition2)
{
    Fraction a(2,-3);
    Fraction b(2,3);
    Fraction m(1,1);
    m=a.Addition(b);
    EXPECT_EQ(m.numerator,0);
    EXPECT_EQ(m.denominator,1);
}

TEST(FunctionCheck, Division)
{
    Fraction a(1,3);
    Fraction b(2,3);
    Fraction m(1,1);
    m=a.Division(b);
    EXPECT_EQ(m.numerator,1);
    EXPECT_EQ(m.denominator,2);
}

TEST(FunctionCheck, Division1)
{
    Fraction a(0,3);
    Fraction b(2,3);
    Fraction m(1,2);
    m=a.Division(b);
    EXPECT_EQ(m.numerator,0);
    EXPECT_EQ(m.denominator,1);
}

TEST(FunctionCheck, Division2)
{
    Fraction a(1,3);
    Fraction b(2,-3);
    Fraction m(1,2);
    m=a.Division(b);
    EXPECT_EQ(m.numerator,-1);
    EXPECT_EQ(m.denominator,2);
}

TEST(DivisionByZeroCheck, Fraction)
{
    EXPECT_THROW(Fraction a(2,0),std::invalid_argument);
}

TEST(DivisionByZeroCheck, Division)
{
    Fraction a(1,3);
    Fraction b(0,3);
    EXPECT_THROW(a.Division(b),std::invalid_argument);
}

TEST(FunctionCheck, DataOutput)
{
    Fraction a(1,2);
    EXPECT_EQ(a.DataOutput(),0.5);
}

