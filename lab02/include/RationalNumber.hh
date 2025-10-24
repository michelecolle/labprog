#ifndef MY_CLASS_H // include guard, per evitare inclusioni multiple
#define MY_CLASS_H
namespace rational_number
{
    // Helper Functions
    class RationalNumber
    {
        public:
            RationalNumber(int numerator = 0, int denominator = 1);
            int getNumerator();
            int getDenominator();
            double toDouble();
        
        private:
            int n;
            int d;
    };
}
#endif