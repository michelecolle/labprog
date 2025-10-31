#include <iostream>
#include <Rational.hh>
using namespace rational_number;
int main()
{
    std::cout << "=== Rational tests ===\n";

    Rational r_default{};
    std::cout << "default: " << r_default << " = " << r_default.toDouble() << '\n';

    Rational r1{1};
    Rational r2{3, 9}; // should be reduced
    std::cout << "r1: " << r1 << " = " << r1.toDouble() << '\n';
    std::cout << "r2 (3/9 reduced): " << r2 << " = " << r2.toDouble() << '\n';
    

    // Assignment operator
    Rational r_assign;
    r_assign = r2;
    std::cout << "assigned r_assign = r2: " << r_assign << '\n';

    // Addition
    Rational r_add = r1 + r2;
    std::cout << "r1 + r2: " << r_add << '\n';
    Rational r_add2 = 1 + r2;
    std::cout << "1 + r2: " << r_add2 << '\n';
    Rational r_add3 = r2 + 2;
    std::cout << "r2 + 2: " << r_add3 << '\n';

    // Unary + and -
    std::cout << "+r2: " << +r2 << '\n';
    std::cout << "-r2: " << -r2 << '\n';

    // Subtraction
    std::cout << "r1 - r2: " << (r1 - r2) << '\n';

    // Multiplication
    std::cout << "r1 * r2: " << (r1 * r2) << '\n';

    // Division
    Rational r_div = r1 / r2;
    std::cout << "r1 / r2: " << r_div << " = " << r_div.toDouble() << '\n';

    // Comparisons
    std::cout << "r1 == r2: " << (r1 == r2) << '\n';
    std::cout << "r1 > r2: " << (r1 > r2) << '\n';
    std::cout << "r1 < r2: " << (r1 < r2) << '\n';

    // User-defined literal
    Rational lit = 5_RA;
    std::cout << "literal 5_RA: " << lit << '\n';
    Rational lit2 = -3/5_RA;
    std::cout << "literal -3/5_RA: " << lit2 << '\n';

    // Reciprocal
    std::cout << "reciprocal of r2: " << getReciprocal(r2) << '\n';

    // Accessors
    std::cout << "r2 numerator: " << r2.getNumerator() << ", denominator: " << r2.getDenominator() << '\n';

    std::cout << "=== End of tests ===\n";
    return 0;
}