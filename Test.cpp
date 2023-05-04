#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"
#include <stdbool.h>
#include <string>

using namespace ariel;
using namespace std;

int max_int = std::numeric_limits<int>::max();
int min_int = std::numeric_limits<int>::min();

TEST_CASE("Fraction addition") {
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction result = f1 + f2;
    CHECK(result.getNumerator() == 5);
    CHECK(result.getDenominator() == 4);
}

TEST_CASE("Fraction subtraction") {
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction result = f1 - f2;
    CHECK(result.getNumerator() == 1);
    CHECK(result.getDenominator() == 4);
}

TEST_CASE("Fraction multiplication") {
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction result = f1 * f2;
    CHECK(result.getNumerator() == 3);
    CHECK(result.getDenominator() == 8);
}

TEST_CASE("Fraction division") {
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction result = f1 / f2;
    CHECK(result.getNumerator() == 3);
    CHECK(result.getDenominator() == 2);
}

TEST_CASE("Fraction addition with float") {
    Fraction f1(3, 4);
    float f2 = 0.5;
    Fraction result = f1 + f2;
    CHECK(result.getNumerator() == 5);
    CHECK(result.getDenominator() == 4);
}

TEST_CASE("Fraction subtraction with float") {
    Fraction f1(3, 4);
    float f2 = 0.5;
    Fraction result = f1 - f2;
    CHECK(result.getNumerator() == 1);
    CHECK(result.getDenominator() == 4);
}

TEST_CASE("Fraction multiplication with float") {
    Fraction f1(3, 4);
    float f2 = 0.5;
    Fraction result = f1 * f2;
    CHECK(result.getNumerator() == 3);
    CHECK(result.getDenominator() == 8);
}

TEST_CASE("Fraction division with float") {
    Fraction f1(3, 4);
    float f2 = 0.5;
    Fraction result = f1 / f2;
    CHECK(result.getNumerator() == 3);
    CHECK(result.getDenominator() == 1);
}

TEST_CASE("Fraction addition overflow") {
    Fraction f1(max_int, 1);
    Fraction f2(1, 1);
    CHECK_THROWS_AS(f1 + f2, overflow_error);
}

TEST_CASE("Fraction subtraction overflow") {
    Fraction f1(min_int, 1);
    Fraction f2(1, 1);
    CHECK_THROWS_AS(f1 - f2, overflow_error);
}

TEST_CASE("Fraction multiplication overflow") {
    Fraction f1(max_int, 2);
    Fraction f2(2, 1);
    CHECK_THROWS_AS(f1 * f2, overflow_error);
}

TEST_CASE("Fraction division overflow") {
    Fraction f1(max_int, 1);
    Fraction f2(0, 1);
    CHECK_THROWS_AS(f1 / f2, invalid_argument);
}

TEST_CASE("Fraction construction with denominator = 0") {
    CHECK_THROWS_AS(Fraction(1, 0), invalid_argument);
}

TEST_CASE("Fraction construction from float") {
    float f = 0.5;
    Fraction frac(f);
    CHECK(frac.getNumerator() == 500);
    CHECK(frac.getDenominator() == 1000);
}

TEST_CASE("Fraction construction from negative float") {
float f = -2.75;
Fraction frac(f);
CHECK(frac.getNumerator() == -11);
CHECK(frac.getDenominator() == 4);
}

TEST_CASE("Fraction reduction") {
Fraction frac(16, 8);
frac.reduce();
CHECK(frac.getNumerator() == 2);
CHECK(frac.getDenominator() == 1);
}

TEST_CASE("Fraction addition") {
Fraction frac1(3, 4);
Fraction frac2(1, 2);
Fraction result = frac1 + frac2;
CHECK(result.getNumerator() == 5);
CHECK(result.getDenominator() == 4);
}

TEST_CASE("Fraction subtraction") {
Fraction frac1(5, 8);
Fraction frac2(1, 4);
Fraction result = frac1 - frac2;
CHECK(result.getNumerator() == 3);
CHECK(result.getDenominator() == 8);
}

TEST_CASE("Fraction multiplication") {
Fraction frac1(2, 3);
Fraction frac2(3, 4);
Fraction result = frac1 * frac2;
CHECK(result.getNumerator() == 1);
CHECK(result.getDenominator() == 2);
}

TEST_CASE("Fraction division") {
Fraction frac1(2, 3);
Fraction frac2(3, 4);
Fraction result = frac1 / frac2;
CHECK(result.getNumerator() == 8);
CHECK(result.getDenominator() == 9);
}
