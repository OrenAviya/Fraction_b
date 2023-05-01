#include "doctest.h"
#include "sources/Fraction.hpp"
#include<iostream>
#include <sstream>

using namespace std;

TEST_CASE("checking if constructors are working") {
    Fraction f1(7,4);
    Fraction f2(1,3);

    CHECK(f1.getNumerator() == 7);
    CHECK(f1.getDenominator() == 4);

    CHECK(f2.getNumerator() == 1);
    CHECK(f2.getDenominator() == 3); 
}

TEST_CASE("check operator =="){
    Fraction f1(7,4);
    Fraction f2(1,3);

    CHECK((Fraction(1,2) == Fraction(2,4)));
    CHECK_FALSE(f1 == f2);
    CHECK(0.5 == Fraction(1,2));
}

TEST_CASE("check reduction "){
    Fraction f1(4,8);

    CHECK(f1 == Fraction(1,2)) ;  
}

TEST_CASE("check + operator fraction"){
    Fraction f1(6,4);
    Fraction f2(5,2);

    CHECK((f1+f2) == Fraction(8, 2));

}

TEST_CASE("check  operator - fraction"){
    
    Fraction f1(7,2);
    Fraction f2(5,2);
    CHECK((f1-f2) == Fraction(2,2));
}


TEST_CASE("check the > , >= operators"){
    
    CHECK(Fraction (5,2) >= Fraction (5,2));
    CHECK(Fraction(7,2) > 1.3 );
    CHECK_FALSE(Fraction (5,2)> 2.7);

}

TEST_CASE("check operator - number"){
    Fraction f1(4,8);
    int integ = 1;
    double doub = 0.5;

    CHECK((f1 - integ) == -0.5);
    CHECK((Fraction(4,8)-doub) == 0);
}

TEST_CASE("check getters "){
     Fraction f1(4,8);

    CHECK( f1.getNumerator() ==1)  ;
    CHECK( f1.getDenominator()== 2 )   ;
    
}

TEST_CASE("check setters"){
   Fraction f1(4,8);

    f1.setNumerator(3);
    f1.setDenominator(5);

    CHECK(f1.getNumerator()==3);
    CHECK(f1.getDenominator()==5);
    
}

TEST_CASE(" check operator/ "){
    Fraction f1(4,8);
    Fraction f2(4,8);

    CHECK(f1/f2 == Fraction(1,1));
    
}

TEST_CASE("check  operator* "){
    Fraction f1(4,8);
    Fraction f2(2,6);

    CHECK(f1*f2 == Fraction(8,48));
    
}

TEST_CASE("check the denominator cannot be zero") {
    Fraction f(1,1);
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(f.setDenominator(0));

}

TEST_CASE("check the ++ , ++(int)"){
    Fraction f(1,2);
    f++;
    CHECK( f == Fraction(3,2));
    Fraction f1(1,2);
    CHECK( ++f1 == Fraction(3,2));
}

TEST_CASE("check the -- , --(int) operators"){
    Fraction f(4,5);

    f--;
    CHECK(f == Fraction(-1,5));
    Fraction f1(4,5);
    CHECK( --f1 == Fraction(-1,5));
}

TEST_CASE("testing input >>"){
    // create an std::istringstream and intilaize it with string
    // then use the operator >> to enter a string into it (fraction represented as string)
    std::istringstream iss("8 9");
    Fraction f;
    iss >> f;
    CHECK(f == Fraction(8,9));


}

TEST_CASE("testing output <<"){
     //create an std::ostringstream object oss, and use the << operator to write a formatted string to it.
     std::ostringstream oss;
     Fraction f(4,5);
     oss<< f;
    CHECK (oss.str() == "4/5");

}

TEST_CASE("check <= , < operators"){
    Fraction f1(2,6);
    Fraction f2(3,9);

    CHECK(f1<=f2);
    CHECK_FALSE(f1<f2);
}

TEST_CASE("check operator + with numbers"){
    double num = 2.500;
    Fraction f(3,5);

    CHECK(num+f == Fraction(3.100) );
}

TEST_CASE("check operator / with numbers"){
    double num = 2.000;
    Fraction f(10/5);

    CHECK(num/f == Fraction(1,1) );
}

TEST_CASE("check operator * with numbers"){
    double num = 2.400;
    Fraction f(3,4);

    CHECK( num*f == Fraction(12,5)*f );

}

TEST_CASE("check operators < ,> , <= , >= with numbers"){
    double num = 2.400;
    Fraction f(3,4);

    CHECK_FALSE(f > num);
    CHECK(f < num);
    CHECK_FALSE(f >= num);
    CHECK_FALSE(num < f);
    CHECK(num > f);
    CHECK(num >= f);
    CHECK(f <= num);
}

// student test 1:

TEST_CASE("Fraction object initialization & Getters return expected values") {
    Fraction a(1, 2);

    // Check that the type of numerator and denominator are int
    CHECK(typeid(a.getNumerator()).name() == typeid(int).name());
    CHECK(typeid(a.getDenominator()).name() == typeid(int).name());

    // Check that the int constractor's fields are like expected. Also checks the getters
    CHECK(((a.getNumerator() == 1) && (a.getDenominator() == 2)));

    // Check that the float constractor's fields are like expected
    Fraction b(0.3333);
    CHECK(((b.getNumerator() == 333) && (b.getDenominator() == 1000)));

    // Check that a Fraction can't be created if denominator is 0
    CHECK_THROWS(Fraction(1,0));
}

TEST_CASE("Fraction addition test") {
    Fraction a(1, 2), b(1, 4); 
    Fraction c = a + b; // 1/2 + 1/4 = 3/4
    CHECK(((c.getNumerator() == 3) && (c.getDenominator() == 4)));
    CHECK(__gcd (c.getNumerator(), c.getDenominator()) == 1); // Reduced as possible


    Fraction d(1, 5);
    float e = 0.4; // Will be converted to 2/5
    Fraction f = d + e; // 1/5 + 2/5 = 3/5
    CHECK(((f.getNumerator() == 3) && (f.getDenominator() == 5)));
    CHECK(__gcd(f.getNumerator(), f.getDenominator()) == 1);


    Fraction g = e + d;
    CHECK(((g.getNumerator() == 3) && (g.getDenominator() == 5)));
    CHECK(__gcd(g.getNumerator(), g.getDenominator()) == 1);
}

TEST_CASE("Fraction subtraction test") {
    Fraction a(1, 2), b(1, 4);
    Fraction c = a - b;
    CHECK(((c.getNumerator() == 1) && (c.getDenominator() == 4)));
    CHECK(__gcd(c.getNumerator(), c.getDenominator()) == 1);
    
    Fraction d(4, 5);
    float e = 0.4;
    Fraction f = d - e; // 4/5 - 2/5 = 2/5
    CHECK(((f.getNumerator() == 2) && (f.getDenominator() == 5)));
    CHECK(__gcd(f.getNumerator(), f.getDenominator()) == 1);

    Fraction g = e - d; // 2/5 - 4/5 = -2/5
    CHECK(((g.getNumerator() == -2) && (g.getDenominator() == 5)));
    CHECK(__gcd(g.getNumerator(), g.getDenominator()) == 1);
}

TEST_CASE("Fraction multiplication test") {
    Fraction a(1, 2), b(1, 4);
    Fraction c = a * b;
    CHECK(((c.getNumerator() == 1) && (c.getDenominator() == 8)));
    CHECK(__gcd(c.getNumerator(), c.getDenominator()) == 1);
    
    Fraction d(4, 5);
    float e = 0.4;
    Fraction f = d * e; // 4/5 * 2/5 = 8/25
    CHECK(((f.getNumerator() == 8) && (f.getDenominator() == 25)));
    CHECK(__gcd(f.getNumerator(), f.getDenominator()) == 1);

    Fraction g = e * d; // 2/5 * 4/5 = 8/25
    CHECK(((g.getNumerator() == 8) && (g.getDenominator() == 25)));
    CHECK(__gcd(g.getNumerator(), g.getDenominator()) == 1);
}

TEST_CASE("Fraction division test") {
    Fraction a(1, 2), b(1, 4);
    Fraction c = a / b; // 1/2 / 1/4 = 1/2 * 4/1 = 4/2 = 2/1
    CHECK(((c.getNumerator() == 2) && (c.getDenominator() == 1)));
    CHECK(__gcd(c.getNumerator(), c.getDenominator()) == 1);
    
    Fraction d(4, 5);
    float e = 0.4;
    Fraction f = d / e; // 4/5 / 2/5 = 4/5 * 5/2 = 20 / 10 = 2/1
    CHECK(((f.getNumerator() == 2) && (f.getDenominator() == 1)));
    CHECK(__gcd(f.getNumerator(), f.getDenominator()) == 1);

    Fraction g = e / d; // 2/5 / 4/5 = 2/5 * 5/4 = 10 / 20 = 1/2
    CHECK(((g.getNumerator() == 1) && (g.getDenominator() == 2)));
    CHECK(__gcd(g.getNumerator(), g.getDenominator()) == 1);
}

TEST_CASE("Division by zero throws an exception") {
    Fraction a(1, 2);
    CHECK_THROWS(a / 0);
}

// Using CHECK_FALSE during (<,>,<=,>=,==) to avoid things like auto-true
TEST_CASE("Fraction < comparison operator") {
    Fraction a(1, 2);
    Fraction b(1, 4);
    
    CHECK(b < a);
    CHECK_FALSE(b >= a); 
    CHECK(0.3 < a);
    CHECK_FALSE(0.3 >= a);
    CHECK(a < 1);
    CHECK_FALSE(a >= 1);
}

TEST_CASE("Fraction <= comparison operator") {
    Fraction a(1, 2);
    Fraction b(1, 4);
    
    CHECK(b <= a);
    CHECK_FALSE(b > a);
    CHECK(0.5 <= a);
    CHECK_FALSE(0.5 > a);
    CHECK(a <= 1);
    CHECK_FALSE(a > 1);
}

TEST_CASE("Fraction > comparison operator") {
    Fraction a(1, 2), b(1, 4);
    
    CHECK(a > b);
    CHECK_FALSE(a <= b);
    CHECK(a > 0.3);
    CHECK_FALSE(a <= 0.3);
    CHECK(1 > a);
    CHECK_FALSE(1 <= a);

}

TEST_CASE("Fraction >= comparison operator") {
    Fraction a(1, 2);
    Fraction b(1, 4);
    
    CHECK(a >= b);
    CHECK_FALSE(a < b);
    CHECK(a >= 0.3);
    CHECK_FALSE(a < 0.3);
    CHECK(1 >= a);
    CHECK_FALSE(1 < a);
}

TEST_CASE("Fraction == comparison operator") {
    Fraction a(1, 2);
    Fraction b(1, 4);
    Fraction c(2, 4); // Equivalent to 1/2
    Fraction d(1, 4);

    CHECK(b == d); // Pure equality
    CHECK(a == c); // Reduced equality
    CHECK_FALSE(a == b);
    CHECK(a == 0.5);
    CHECK_FALSE(a == 0.3);
    CHECK(0.5 == a);
    CHECK_FALSE(0.3 == a);
    CHECK(b == d);
}

TEST_CASE("Prefix and postfix increment operators on Fraction class") {
    Fraction a(1, 2);

    // Use prefix increment operator on Fraction object
    Fraction b = ++a;
    // Check that the value of a has been incremented to 3/2
    CHECK(a.getNumerator() == 3);
    CHECK(a.getDenominator() == 2);
    // Check that the value of b is also 3/2
    CHECK(b.getNumerator() == 3);
    CHECK(b.getDenominator() == 2);

    a = Fraction(1, 2); // Reset

    // Use postfix increment operator on Fraction object
    Fraction c = a++;
    // Check that the value of a has been incremented to 3/2
    CHECK(a.getNumerator() == 3);
    CHECK(a.getDenominator() == 2);
    // Check that the value of c is still 1/2
    CHECK(c.getNumerator() == 1);
    CHECK(c.getDenominator() == 2);
}

TEST_CASE("Prefix and postfix decrement operators on Fraction class") {
    Fraction a(3, 2);

    // Use prefix decrement operator on Fraction object
    Fraction b = --a;
    // Check that the value of a has been decremented to 1/2
    CHECK(a.getNumerator() == 1);
    CHECK(a.getDenominator() == 2);
    // Check that the value of b is also 1/2
    CHECK(b.getNumerator() == 1);
    CHECK(b.getDenominator() == 2);

    a = Fraction(3, 2); // Reset

    // Use postfix decrement operator on Fraction object
    Fraction c = a--;
    // Check that the value of a has been decremented to 1/2
    CHECK(a.getNumerator() == 1);
    CHECK(a.getDenominator() == 2);
    // Check that the value of c is still 3/2
    CHECK(c.getNumerator() == 3);
    CHECK(c.getDenominator() == 2);
}

TEST_CASE("Output and Input Stream Operators") {
    Fraction a(1, 2), b(3, 4);
    ostringstream os;

    // Test operator<<
    CHECK_NOTHROW(os << a); // Not thrwoing error
    CHECK(os.str() == "1/2"); // Prints well

    istringstream is("5 6"); // Could also be "5,6" for ex
    istringstream bad_is("7");

    // Test operator>>
    CHECK_NOTHROW(is >> b);
    CHECK(b.getNumerator() == 5);
    CHECK(b.getDenominator() == 6);
    CHECK_THROWS(bad_is >> b); // Throws cuz the input is one number
}

TEST_CASE("Rounding of float numbers during arithmetic operations with Fractions") {
    Fraction a(2, 5);
    float b = 0.2001; // During the "+" operation it'll became 0.200, which is 1/5
    Fraction c = a + b; // 2/5 + 1/5 = 3/5
    CHECK(((c.getNumerator() == 3) && (c.getDenominator() == 5)));

    b = 0.2001;
    c = a - b; // 1/5
    CHECK(((c.getNumerator() == 1) && (c.getDenominator() == 5)));

    b = 0.2001;
    c = a * b; // 2/25
    CHECK(((c.getNumerator() == 2) && (c.getDenominator() == 25)));

    b = 0.2001;
    c = a / b; // 2/1
    CHECK(((c.getNumerator() == 2) && (c.getDenominator() == 1)));
}