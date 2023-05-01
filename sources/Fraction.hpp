#pragma once
#include <iostream>
namespace ariel {}
class Fraction{
    private:
        int num; //numerator
        int den; //denominator
    
    public:
    //constructors:
        Fraction();

        Fraction(int numerator, int denominator);

        Fraction(double num);

    //getters & setters

        void setNumerator(int);
        void setDenominator(int);

        int getNumerator() const;
        int getDenominator() const;
        
    // operators
     
        Fraction operator+(Fraction frac);
        Fraction operator+(double num);
        // friend const Fraction operator+(double num , const Fraction frac);

        Fraction operator-(Fraction frac);
        Fraction operator-(double num);
        // friend const Fraction operator-(double num , const Fraction frac);

        Fraction operator/(Fraction frac);
        Fraction operator/(double number);
        // friend const Fraction operator/(double num , const Fraction frac);

        Fraction operator*(Fraction frac);
        Fraction operator*(double number);
        // friend const Fraction operator*(double num , const Fraction frac);
        
        Fraction& operator++();
    
        Fraction& operator--();
    
        Fraction operator++(int);
    
        Fraction operator--(int);

        bool operator>=(const Fraction &frac) const;
        bool operator>=(double number) const ;
        
        bool operator <=(const Fraction &frac) const;
        bool operator<=(double number) const ;

        bool operator <(const Fraction &frac) const;
        bool operator < (double number) const;
        
        bool operator >(const Fraction &frac) const;
        bool operator>(float number) const;
       
        bool operator==(const Fraction& other) const;
        bool operator == (double number)const;
        
        int gcd (int one , int two);
        void reduce();


};
//all the "friend" function but we want them "const" and it is imposible so did it out of class...
std::ostream& operator<<(std::ostream& out, const Fraction& fraction);   
std::istream& operator>>(std::istream& input, Fraction& fraction);
 bool operator ==(double num , const Fraction &frac);
 bool operator >(double number , const Fraction &frac);
 bool operator <(double num , const Fraction &frac);
 bool operator<=(double num , const Fraction &frac);
 bool operator>=(double num , const Fraction &frac);
Fraction operator*(double num , const Fraction &frac);
Fraction operator/(double num , const Fraction &frac);
Fraction operator-(double num , const Fraction &frac);
Fraction operator+(double num , const Fraction &frac);

