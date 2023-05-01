#include "Fraction.hpp"
#include <math.h>
using namespace std;
using namespace ariel;

//constructors:
        Fraction:: Fraction (): num(0) , den(1){

        }    

        Fraction:: Fraction(int numerator, int denominator)/*num(numerator) , den(denominator)*/ {
            if ( denominator == 0 && numerator!=0 )
                throw std :: invalid_argument ("This demoninator is illegal");
           
        
            //reduce the fraction
            int gcf = gcd(numerator, denominator); // find greatest common factor
            numerator /= gcf;
            denominator /= gcf;

            //Avoid problems with equals fractions...
            if (denominator < 0 ){
                numerator *=-1;
                denominator *= -1;
            }

            this->num = numerator;
            this->den = denominator;
        }

       Fraction :: Fraction(double num){
        int numerator = static_cast<int>(num * 1000);
        int denominator = 1000;
        
        int gcf = gcd(numerator, denominator); // find greatest common factor
        numerator /= gcf;
        denominator /= gcf;

        //Avoid problems with equals fractions...
            if (denominator < 0 ){
                numerator *=-1;
                denominator *= -1;
            }
            
        this->num = numerator;
        this->den = denominator ;      
        }
        
    //getters & setters

        void Fraction::setNumerator(int n){
            this->num = n;
        }
        void Fraction::setDenominator(int d){
            if (d == 0.0 || d== 0)
                throw std :: invalid_argument ("This demoninator is illegal");
            
            this->den = d;
        }

        int Fraction::getNumerator() const{
            return this->num;
        }
        int Fraction:: getDenominator() const{
            return this->den;
        }
        


        Fraction Fraction:: operator+(Fraction frac){
        int denominator = this->den * frac.getDenominator();
        int numerator ;
        // checking if the operation couses an overflow: 
        if (__builtin_add_overflow((frac.getDenominator() * this->num), (this->den * frac.getNumerator()), &numerator))
        {
            throw std::overflow_error("Overflow error: result is too large");
        }
        Fraction frac1=Fraction(numerator, denominator); //reducing by constructor
        return frac1;
        }

         Fraction operator+(double num , const Fraction &frac){
            Fraction temp(num);
            Fraction frac1= (temp+frac);
            frac1.reduce();
            return (frac1);
        }

        Fraction Fraction:: operator+(double num){
           Fraction temp = Fraction(num);
            Fraction frac=*this+temp;
            frac.reduce();
            return (frac);
        }

        Fraction Fraction:: operator-(Fraction frac){
        
        int denominator = this->den * frac.getDenominator();
        int numerator;
        // checking if the operation couses an overflow
        if (__builtin_sub_overflow((this->num * frac.getDenominator()), (frac.getNumerator() * this->den), &numerator))
        {
        throw std::overflow_error("Overflow error: result is too large");
        }
        Fraction frac1=Fraction(numerator, denominator);
        frac1.reduce();
        return frac1;
        }

        Fraction Fraction:: operator-(double num){
        Fraction frac1 =  Fraction(num);
        frac1 = *this - frac1;
        frac1.reduce();
        return frac1;
        }


         Fraction operator-(double num , const Fraction &frac){
            Fraction temp(num);
            return (temp-frac);
        }

        Fraction Fraction:: operator/(Fraction frac){
            int numerator;
            int denominator;
            // checking if the operation couses an overflow:
            if (__builtin_mul_overflow(this->num ,  frac.getDenominator(), &numerator))
            {
            throw std::overflow_error("Overflow error: result is too large");
            }
            if (__builtin_mul_overflow(this->den ,  frac.getNumerator(), &denominator))
            {
            throw std::overflow_error("Overflow error: result is too large");
            }
            
            if(denominator == 0 )
            {
            throw std :: runtime_error ("cannot dividing by zero");
            }
            
            Fraction frac1 = Fraction(numerator , denominator);
             frac1.reduce();
             return frac1;
        }

         Fraction operator/(double num , const Fraction &frac){
            Fraction temp(num);
            return (temp/frac);
        }

        Fraction Fraction:: operator/(double number) {
            if (number == 0.0){
                throw std :: runtime_error("devision by zero is illegal");
            }
            //make fraction from the number , then use / with two fractions
            Fraction f(number); 
            return *this / f; 

        }
        Fraction Fraction:: operator*(Fraction frac){
            int numerator ;
           int denominator;
           // checking if the operation couses an overflow:
           if (__builtin_mul_overflow(this->num ,  frac.getNumerator(), &numerator))
            {
            throw std::overflow_error("Overflow error: result is too large");
            }
            if (__builtin_mul_overflow(this->den ,  frac.getDenominator(), &denominator))
            {
            throw std::overflow_error("Overflow error: result is too large");
            }

          Fraction frac1 = Fraction(numerator , denominator);
          frac1.reduce();
            return frac1;
        }
         Fraction operator*(double num , const Fraction &frac){
            Fraction frac1 = Fraction(num);
            frac1.reduce();
            return frac1*frac;
        }
        Fraction Fraction:: operator*(double number){
            Fraction temp(number);
            return (*this * temp);
        }

        Fraction& Fraction::operator++(){
            this ->num += this ->den; // add 1 to the fraction
            this->reduce(); //reduce
            return *this;
        }
    
        Fraction& Fraction::operator--(){
            this ->num -= this ->den; // minus 1 to the fraction
            this ->reduce(); // reduce
            return *this;
        }

        Fraction Fraction::operator++(int i){
            Fraction frac = *this; 
            ++(*this);
            return frac;
        }
        Fraction Fraction::operator--(int i){
            Fraction frac = *this; 
            --(*this);
            return frac;
        }


        bool Fraction :: operator>=(const Fraction& frac) const{
            if (*this > frac || *this == frac ){
                return true;
            } 
            return false;
            }
         bool Fraction ::operator>=(double number) const{

            return (*this > number || *this == number );
         }

         bool operator>=(double num , const Fraction &frac){
            Fraction temp(num);
            return (temp >= frac);
        }

        bool Fraction ::operator <=(const Fraction &frac) const{
            return (*this < frac || *this == frac);
                
        }
        bool Fraction ::operator<=(double number) const{
            Fraction temp(number);
            return (*this <= temp);
        }
         bool operator<=(double num , const Fraction &frac){
            Fraction temp(num);
            return (temp <= frac);
        }

        bool Fraction :: operator <(const Fraction &frac) const{
            return ((double)(this->num * frac.getDenominator()) < (double)(frac.getNumerator() * this->den)); 
        }
         bool Fraction :: operator < (double number) const{
            Fraction temp(number);
            return (*this < temp);
         }
          bool operator<(double num , const Fraction &frac){
            Fraction temp(num);
            return (temp < frac);
        }

        bool Fraction:: operator >(float number) const{
            return(this -> num > (number* this->den));
        }
        
        bool Fraction::operator >(const Fraction &frac) const{
             return ((double)(this->num * frac.getDenominator()) > (double)(frac.getNumerator() * this->den));
             
        }

         bool operator >(double number , const Fraction &frac){
            Fraction temp(number);
            return (temp > frac);
        }

        bool Fraction:: operator==(const Fraction& frac) const{
          
             // to be sure they both have only three numbers after point
            double f1 = std :: round ((double)(this->num)/ this->den*1000)/1000.0;
            double f2 = std :: round ((double)(frac.getNumerator()) / frac.getDenominator()*1000)/ 1000.0; 

            return (f1 == f2);
        }

        bool Fraction:: operator == (double number)const{
           return (number == *this);
           
        }
         bool operator ==(double num , const Fraction &frac){
            return (Fraction(num) == frac);
        }

        std::ostream& operator<<(std::ostream& output, const Fraction& frac)
        {
             if(frac.getDenominator()< 0 || frac.getNumerator() < 0) // check if numerator or denominator is negative
    { // to show an union print to all fractions:
        int n = abs(frac.getNumerator()); 
        int d = abs(frac.getDenominator()); 
        output << "-"; // print a minus sign
        output << n << "/" << d;
    }
    else{
        output << frac.getNumerator()<< "/" << frac.getDenominator();
    }
        return output;
        }

        std::istream& operator>>(std::istream& input, Fraction& frac){
        char c ;
        int num , den;
         
        input >> num >> den ;
        
        if (input && den != 0) {
        frac.setNumerator(num);
        frac.setDenominator(den);
    }
     else {
        throw runtime_error("Bad_in");
    }
    return input;
}


   // for reduction     
int Fraction::gcd(int one, int two) { // function to find greatest common divisor
    if (two == 0)
        return one;
    return gcd(two, one % two);
}

void Fraction:: reduce(){
    int gcf = Fraction:: gcd(this->num,this->den); 
            this->num/= gcf;
            this->den /= gcf;
            
}