#include "RationalNumber.hh"
namespace rational_number
{
    RationalNumber::RationalNumber(int numerator, int denominator)
        : n(numerator), d(denominator)
    {
        // Constructor implementation
    }

    int RationalNumber::getNumerator()
    {
        return n;
    }

    int RationalNumber::getDenominator()
    {
        return d;
    }

    double RationalNumber::toDouble()
    {
        return static_cast<double>(n) / d;
    }
} // namespace rational_number