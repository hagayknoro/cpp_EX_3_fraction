#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <math.h>
#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;
using namespace ariel;

    // Constructor for creating a Fraction object from integer values
    Fraction::Fraction(int num, int den)
    {
        //check if denominator if 0
        if (den > 0 && num > 0)
        {
        this->numerator = num;
        this->denominator = den;
        reduce();
        }
        else if (den == 0 && num < 0)
        {
            throw std::invalid_argument("you can't create a Fraction with zero in the deominator");
        }
        else if (den == 0 && num > 0)
        {
            throw std::invalid_argument("you can't create a Fraction with zero in the deominator");
        }

        else if(den < 0 && num <0)
        {
        this->numerator = (-1)*num;
        this->denominator = (-1)*den;
        reduce();
        }
        else if(den > 0 && num <0)
        {
        this->numerator = num;
        this->denominator = den;
        reduce();
        }
        else if(den < 0 && num >0)
        {
        this->numerator = (-1)*num;
        this->denominator = (-1)*den;
        reduce();
        }
        else if(den != 0 && num == 0)
        {
        this->numerator = 0;
        this->denominator = 1;
        reduce();
        }
        

    }

    // Constructor for creating a Fraction object from a double value
    Fraction::Fraction(float num)
    {
        if (num == 0)
        {
        this->numerator = 0;
        this->denominator = 1;
        }
        this->numerator = (int)(num*1000);
        this->denominator = 1000;
        reduce();
    }

    // Empty Constructor
    Fraction::Fraction()
    {
    this->numerator = 1;
    this->denominator = 1;  
    }


    // Returns the numerator of the fraction
    int Fraction::getNumerator() const
    {
        return this->numerator;
    }

    // Returns the denominator of the fraction
    int Fraction::getDenominator() const
    {
        return this->denominator;
    }

    // Overloading the + operator for two fractions
    Fraction Fraction::operator+(const Fraction &other)
    {
        long long num = (long long)numerator * (long long)other.denominator + (long long)other.numerator * (long long)denominator;
        long long den = (long long)denominator * (long long)other.denominator;
        //check fo overflow
        if (num > INT_MAX || num < INT_MIN || den > INT_MAX || den > INT_MAX)
        {
            throw overflow_error("operator + is couse overflow");
        }
        
        return Fraction((int)num, (int)den);
    }

    // Overloading the + operator for a fraction and a float
    Fraction Fraction::operator+(float other)
    {
        return *this + Fraction(other);
    }


    // Overloading the - operator for two fractions
    Fraction Fraction::operator-(const Fraction &other)
    {
        long long num = (long long)numerator * (long long)other.denominator - (long long)other.numerator * (long long)denominator;
        long long den = (long long)denominator * (long long)other.denominator;
        //check fo overflow
        if (num > INT_MAX || num < INT_MIN || den > INT_MAX || den > INT_MAX)
        {
            throw overflow_error("operator - is couse overflow");
        }
        return Fraction((int)(num), (int)den);
    }

    // Overloading the - operator for a fraction and a float
    Fraction Fraction::operator-(float other)
    {
        return *this - Fraction(other);
    }

    // Overloading the * operator for two fractions
    Fraction Fraction::operator*(const Fraction &other)
    {
        long long num = (long long)numerator * (long long)other.numerator;
        long long den = (long long)denominator * (long long)other.denominator;
        if (num > INT_MAX || num < INT_MIN || den > INT_MAX || den > INT_MAX)
        {
            throw overflow_error("operator * is couse overflow");
        }
        return Fraction((int)num, (int)den);
    }

    // Overloading the * operator for a fraction and a float
    Fraction Fraction::operator*(const float other)
    {
        return *this * Fraction(other);
    }


    // Overloading the / operator for two fractions
    Fraction Fraction::operator/(const Fraction &other)
    {
        if (other == 0)
        {
            throw std::runtime_error("you can't devide with zero");
        }
        
        long long num = (long long)numerator * (long long)other.denominator;
        long long den = (long long)denominator * (long long)other.numerator;
        if (num > INT_MAX || num < INT_MIN || den > INT_MAX || den > INT_MAX)
        {
            throw overflow_error("operator / is couse overflow");
        }
        return Fraction((int)num, (int)den);
    }

    // Overloading the / operator for a fraction and a float
    Fraction Fraction::operator/(const float other)
    {
        if (other == 0)
        {
            throw std::runtime_error("you can't devide with zero");
        }
        return *this / Fraction(other);
    }

    // Overloadingthe == operator for two fractions
    bool Fraction::operator==(const Fraction &other) const
    {
    double res1 = (double)(this->numerator) / (double)(this->denominator);
    double res2 = (double)(other.numerator) / (double)(other.denominator);
    double epsilon = 0.0001; // set a small epsilon value
    
    if (compareTo(other) == 0)
    {
        return true;
    }
    else if (fabs(res1 - res2) < epsilon)
    {
        return true;
    }
    return false;
    }

    // Overloading the == operator for fraction and float
    bool Fraction::operator==(float other)
    {
        Fraction frac = Fraction(other);
        if (compareTo(frac) == 0)
        {
            return true;
        }
        return false;
        
    }

    // Overloading the == operator for a float and a fraction
    bool operator==(const float lhs, const Fraction &rhs)
    {
        Fraction frac = Fraction(lhs);
        if (frac == rhs)
        {
            return true;
        }
        return false;
    }
    
    // Overloading the > operator for two fractions
    bool Fraction::operator>(const Fraction &other) const
    {
    double result1 = (double)(this->numerator) / (double)(this->denominator);
    double result2 = (double)(other.numerator) / (double)(other.denominator);
    double tolerance = 0.0001; // set a tolerance level

    if (compareTo(other) == 1)
    {
        return true;
    }
    else if (fabs(result1 - result2) < tolerance && compareTo(other) != 0)
    {
        return true;
    }
    return false;
    }



    // Overloading the > operator for fraction and float
    bool Fraction::operator>(float other)
    {
        Fraction frac = Fraction(other);
        if (compareTo(frac) == 1)
        {
            return true;
        }
        return false;
    }

    // Overloading the > operator for a float and a fraction
    bool operator>(const float lhs, const Fraction &rhs)
    {
    Fraction frac = Fraction(lhs);
    if (frac > rhs)
    {
        return true;
    }
    return false;
    }



    // Overloading the < operator for two fractions
    bool Fraction::operator<(const Fraction &other) const   
    {
    double result1 = (double)(this->numerator) / (double)(this->denominator);
    double result2 = (double)(other.numerator) / (double)(other.denominator);
    double tolerance = 0.0001; // set a tolerance level

    if (compareTo(other) == -1)
    {
        return true;
    }
    else if (fabs(result1 - result2) < tolerance && compareTo(other) != 0)
    {
        return true;
    }
    return false;
    }


    // Overloading the < operator for fraction and float
    bool Fraction::operator<(float other)
    {
        Fraction frac = Fraction(other);
        if (compareTo(frac) == -1)
        {
            return true;
        }
        return false;
    }

    // Overloading the < operator for a float and a fraction
    bool operator<(const float lhs, const Fraction &rhs)
    {
    Fraction frac = Fraction(lhs);
    if (frac < rhs)
    {
        return true;
    }
    return false;
    }

    // Overloading the >= operator for two fractions
    bool Fraction::operator>=(const Fraction &other) const
    {
    float res1 = (float)(this->numerator) / (float)(this->denominator);
    float res2 = (float)(other.numerator) / (float)(other.denominator);
    float r_res1 = roundf(res1 * 1000.0f) / 1000.0f;
    float r_res2 = roundf(res2 * 1000.0f) / 1000.0f;

    if (compareTo(other) == 1)
    {
        return true;
    }
    else if (compareTo(other) == 0)
    {
        return true;
    }
    else if (r_res1 > r_res2)
    {
        return true;
    }
    else if (r_res1 == r_res2)
    {
        return true;
    }
    return false;
    }
            
    // Overloading the >= operator for fraction and float
    bool Fraction::operator>=(float other)
    {
    Fraction frac = Fraction(other);
    if (compareTo(frac) == 1)
    {
        return true;
    }
    else if (compareTo(frac) == 0)
    {
        return true;
    }
        return false;  
    }

    // Overloading the >= operator for a float and a fraction
    bool operator>=(const float lhs, const Fraction &rhs)
    {
    Fraction frac = Fraction(lhs);
    if (frac > rhs)
    {
        return true;
    }
    else if (frac == rhs)
    {
        return true;
    }
    return false;
    }

    // Overloading the <= operator for two fractions
    bool Fraction::operator<=(const Fraction &other) const
    {
    float res1 = (float)(this->numerator) / (float)(this->denominator);
    float res2 = (float)(other.numerator) / (float)(other.denominator);
    float r_res1 = roundf(res1 * 1000.0f) / 1000.0f;
    float r_res2 = roundf(res2 * 1000.0f) / 1000.0f;

    if (compareTo(other) == -1)
    {
        return true;
    }
    else if (compareTo(other) == 0)
    {
        return true;
    }
    else if (r_res1 < r_res2)
    {
        return true;
    }
    else if (r_res1 == r_res2)
    {
        return true;
    }
    return false;
    }

    // Overloading the <= operator for fraction and float
    bool Fraction::operator<=(float other)
    {
    Fraction frac = Fraction(other);
    if (compareTo(frac) == -1)
    {
        return true;
    }
    else if (compareTo(frac) == 0)
    {
        return true;
    }
        return false;  
    }

    // Overloading the <= operator for a float and a fraction
    bool operator<=(const float lhs, const Fraction &rhs)
    {
    Fraction frac = Fraction(lhs);
    if (frac < rhs)
    {
        return true;
    }
    else if (frac == rhs)
    {
        return true;
    }
    return false;
    }

    // Overloading the pre-fix ++ operator for a fraction
    Fraction &Fraction::operator++()
    {
    this->numerator += this->denominator;
    if (this->numerator > INT_MAX)
    {
        throw overflow_error("operator ++ is couse overflow");
    }
    reduce();
    return *this;
    }

    // Overloading the post-fix ++ operator for a fraction
    Fraction Fraction::operator++(int)
    {
    Fraction temp = *this;
    this->numerator += this->denominator;
    reduce();
    return temp;
    }

    // Overloading the pre-fix -- operator for a fraction
    Fraction &Fraction::operator--()
    {
    this->numerator -= this->denominator;
    if (this->numerator < INT_MIN)
    {
        throw overflow_error("operator -- is couse the number be under INT_MIN");
    }
    reduce();
    return *this;
    }

    // Overloading the post-fix -- operator for a fraction
    Fraction Fraction::operator--(int)
    {
    Fraction temp = *this;
    this->numerator -= this->denominator;
    reduce();
    return temp;
    }

    // Overloading comperTo operator for two fractions
    int Fraction::compareTo(const Fraction &other) const
    {
        int common_lcm = lcm(denominator, other.denominator);
        int lefrc = numerator * (common_lcm / denominator);
        int rhfrc = other.numerator * (common_lcm / other.denominator);

        if (lefrc > rhfrc)
        {
            return 1;
        }
        else if (lefrc < rhfrc)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    void Fraction::reduce()
    {
    int gcdVal = std::gcd(numerator, denominator);
    numerator /= gcdVal;
    denominator /= gcdVal;
    }


