#ifndef MY_CLASS_H // include guard, per evitare inclusioni multiple
#define MY_CLASS_H
#include <ostream>
namespace rational_number
{
    class Rational
    {
        public:
            Rational(int numerator = 0, int denominator = 1);
            int getNumerator() const;// const perche' non modifica l'oggetto
            int getDenominator() const;
            double toDouble();
            Rational operator=(const Rational r);
            
            //Rational operator+(const Rational r);
            //Rational operator+(const int n);
            
        
        private:
            int n;
            int d;
            void reduce(); // funzione privata per ridurre il numero razionale ai minimi termini
    };

    // Helper Functions, NB sotto alla dichiarazione della classe, altrimenti il compilatore non sa cosa sia Rational
    Rational getReciprocal(const Rational& r);

    //operator overlads
    //NB la somma con un intero e' gestita automicamente dal costruttore,
    //in entrambi i sensi, perche' l'intero viene convertito in razionale                      
    Rational operator+(const Rational& r1, const Rational& r2);
    Rational operator+(const Rational& r1);//appone il segno +, utile per espressioni come +r1
    Rational operator-(const Rational& r1, const Rational& r2);
    Rational operator-(const Rational& r1);
    Rational operator*(const Rational& r1, const Rational& r2);
    Rational operator/(const Rational& r1, const Rational& r2);
    bool operator==(const Rational& r1, const Rational& r2);
    bool operator>(const Rational& r1, const Rational& r2);
    bool operator<(const Rational& r1, const Rational& r2);
    //bous, literal operator
    Rational operator ""_RA(unsigned long long input);
    std::ostream& operator<<(std::ostream& os, const Rational& r);

    //non é l'unico tentativo di classe razionale XD
    //https://github.com/github-copilot/code_referencing?cursor=64730fd53efaa5c75fd1cc460a7c9637,a5edf7d94ede794f6bf04fc55722d981,c008233df25e78e6e58370ba4868c3b3,ce3b47b7cfc7623424f5d838836c8593,fbf2360c450f7e81cae5a988a0c74caf

}
#endif