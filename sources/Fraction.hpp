#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <math.h>
#include <numeric>
#pragma once

namespace ariel
{
};
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // Constructor for creating a Fraction object from integer values
    Fraction(int num = 0, int den = 1);

    // Constructor for creating a Fraction object from a double value
    Fraction(float);

    // Empty Constructor
    Fraction();

    // Returns the numerator of the fraction
    int getNumerator() const;

    // Returns the denominator of the fraction
    int getDenominator() const;

    // Overloading the + operator for two fractions
    Fraction operator+(const Fraction &other);

    // Overloading the + operator for a fraction and a double
    Fraction operator+(float other);

    // Overloading the + operator for a float and a fraction
    friend Fraction operator+(float lhs, const Fraction &rhs)
    {
        Fraction frac = Fraction(lhs);
        Fraction res = frac + rhs;
        return res;
    }

    // Overloading the - operator for two fractions
    Fraction operator-(const Fraction &other);

    // Overloading the - operator for a fraction and a double
    Fraction operator-(float other);

    // Overloading the - operator for a double and a fraction
    friend Fraction operator-(float lhs, const Fraction &rhs)
    {
        Fraction frac = Fraction(lhs);
        Fraction res = frac - rhs;
        return res;
    }

    // Overloading the * operator for two fractions
    Fraction operator*(const Fraction &other);

    // Overloading the * operator for a fraction and a float
    Fraction operator*(float other);

    // Overloading the * operator for a double and a fraction
    friend Fraction operator*(const float lhs, const Fraction &rhs)
    {
        Fraction frac = Fraction(lhs);
        Fraction res = frac * rhs;
        return res;
    }

    // Overloading the / operator for two fractions
    Fraction operator/(const Fraction &other);

    // Overloading the / operator for a fraction and a double
    Fraction operator/(float other);

    // Overloading the / operator for a float and a fraction
    friend Fraction operator/(const float lhs, const Fraction &rhs)
    {
        if (rhs.numerator == 0)
        {
            throw std::invalid_argument("you can't devide with zero");
        }
    return Fraction(lhs) / rhs ;
    }

    // Overloading the == operator for two fractions
    bool operator==(const Fraction &other) const;

    // Overloading the == operator for fraction and float
    bool operator==(float other);

    // Overloading the == operator for a float and a fraction
    friend bool operator==(float , const Fraction &rhs);

    // Overloading the > operator for two fractions
    bool operator>(const Fraction &other) const;

    // Overloading the > operator for fraction and float
    bool operator>(float other);
            
    // Overloading the > operator for a float and a fraction
    friend bool operator>(float , const Fraction &rhs);

    // Overloading the < operator for two fractions
    bool operator<(const Fraction &other) const;

    // Overloading the < operator for fraction and float
    bool operator<(float other);
            
    // Overloading the < operator for a float and a fraction
    friend bool operator<(float , const Fraction &rhs);

    // Overloading the >= operator for two fractions
    bool operator>=(const Fraction &other) const;

    // Overloading the >= operator for fraction and float
    bool operator>=(float other);
            
    // Overloading the >= operator for a float and a fraction
    friend bool operator>=(float , const Fraction &rhs);

    // Overloading the <= operator for two fractions
    bool operator<=(const Fraction &other) const;

    // Overloading the <= operator for fraction and float
    bool operator<=(float other);
            
    // Overloading the <= operator for a float and a fraction
    friend bool operator<=(float , const Fraction &rhs);

    // Overloading the pre-fix ++ operator for a fraction
    Fraction &operator++();

    // Overloading the post-fix ++ operator for a fraction
    Fraction operator++(int);

    // Overloading the pre-fix -- operator for a fraction
    Fraction &operator--();

    // Overloading the post-fix -- operator for a fraction
    Fraction operator--(int);

    // Overloading comperTo operator for two fractions
    int compareTo(const Fraction &other) const;
    
    // Reduces the fraction to its simplest form
    void reduce();
            
    // Overloading the << operator for a fraction
    friend std::ostream &operator<<(std::ostream &output, const Fraction &frac)
    {

        output << frac.numerator << "/" << frac.denominator;
        return output;
    }

    // Overloading the >> operator for a fraction
    friend std::istream &operator>>(std::istream &input, Fraction &frac)
    {

        int num = 0;
        if (input >> num)
        {

            if (input >> frac.denominator)
            {
                if (frac.denominator < 0 && num < 0 || num > 0 && frac.denominator < 0)
                {
                    frac.denominator = frac.denominator * (-1);
                    frac.numerator = num * (-1);
                }
                else
                {
                    frac.numerator = num;
                }
                // Both numerator and denominator have been read
            }
            else
            {
                // Only one number has been read
                throw std::runtime_error("Invalid input: Expected two integers separated by space");
            }
        }
        else
        {
            throw std::runtime_error("Invalid input: Expected a number");
        }

        if (frac.denominator == 0)
        {
            throw std::runtime_error("Denominator can't be zero");
        }

        frac.reduce();
        return input;
    }
};


