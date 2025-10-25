#include  <Rational.hh>
#include <stdexcept>
namespace rational_number
{
    /// @brief Crea un nuovo numero razionale che e' il reciproco di r
    /// @param r 
    /// @return 
    Rational getReciprocal(const Rational& r)
    {
        return Rational(r.getDenominator(), r.getNumerator());
    }
    Rational operator+(const Rational& r1, const Rational& r2)
    {
        int n = r1.getNumerator() * r2.getDenominator() + r2.getNumerator() * r1.getDenominator();
        int d = r1.getDenominator() * r2.getDenominator();
        return Rational(n, d);
    }
    Rational operator+(const Rational& r1)
    {
        return r1;
    }
    Rational operator-(const Rational& r1, const Rational& r2)
    {
        int n = r1.getNumerator() * r2.getDenominator() - r2.getNumerator() * r1.getDenominator();
        int d = r1.getDenominator() * r2.getDenominator();
        return Rational(n, d);
    }
    Rational operator-(const Rational& r1)
    {
        return Rational(-r1.getNumerator(), r1.getDenominator());
    }
    Rational operator*(const Rational& r1, const Rational& r2)
    {
        int n = r1.getNumerator() * r2.getNumerator();
        int d = r1.getDenominator() * r2.getDenominator();
        return Rational(n, d);
    }
    Rational operator/(const Rational& r1, const Rational& r2)
    {
        return r1*getReciprocal(r2);
    }
    bool operator==(const Rational& r1, const Rational& r2)
    {
        return (r1.getNumerator()*r2.getDenominator() == r2.getNumerator()*r1.getDenominator())? true: false;
    }
    bool operator>(const Rational& r1, const Rational& r2)
    {
        return (r1.getNumerator()*r2.getDenominator() > r2.getNumerator()*r1.getDenominator())? true: false;
    }
    bool operator<(const Rational& r1, const Rational& r2)
    {
        return (r1.getNumerator()*r2.getDenominator() < r2.getNumerator()*r1.getDenominator())? true: false;
    }
    Rational operator ""_RA(unsigned long long input)\
    {
        return Rational(static_cast<int>(input), 1);
    }

    std::ostream& operator<<(std::ostream& os, const Rational& r)
    {
        r.getDenominator() != 1? os << r.getNumerator() << '/' << r.getDenominator(): os << r.getNumerator();
        return os;
    }


    //--------------------------------------------------------------------------//
    //funzioni membro della classe Rational
    //--------------------------------------------------------------------------//

    Rational::Rational(int numerator, int denominator)
    {
        //l'unica eccezione e' il denominatore nullo
        if (denominator == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        n = numerator;
        d = denominator;
        reduce();
    }

    int Rational::getNumerator() const
    {
        return n;
    }

    int Rational::getDenominator() const
    {
        return d;
    }

    double Rational::toDouble()
    {
        return static_cast<double>(n) / d;
    }
    Rational Rational::operator=(const Rational r)
    {
        n = r.getNumerator();
        d = r.getDenominator();
        return *this;//ritorno il valore, non il puntatore
    }
    // Rational Rational::operator+(const Rational r)
    // {
    //     int n1 = r.getNumerator();
    //     int d1 = r.getDenominator();
    //     int new_n = n * d1 + n1 * d;
    //     int new_d = d * d1;
    //     n = new_n;
    //     d = new_d;
    //     return *this;//ritorno il valore, non il puntatore
    // }

    // Rational Rational::operator+(const int n)
    // {
    //     int new_n = this->n + n * this->d;
    //     this->n = new_n;
    //     return *this;//ritorno il valore, non il puntatore    
    // }

    void reduce_inpl(int *numerator, int *denominator)
    {
        // riduzione in place del numero razionale
        // charamente per efffettuare la riduzione migliore andrebbero coalcolati i fattori primi
        // al momento mi limito ai multipli diretti
        int tn = *numerator;
        int td = *denominator;
        if(tn%td==0)
        {
            *numerator=tn/td;
            *denominator=1;
        }
    }
    void fix_sign(int *numerator, int *denominator)
    {
        //assicura che il denominatore sia sempre positivo
        if(*denominator<0)
        {
            *denominator = -(*denominator);
            *numerator = -(*numerator);
        }
    }

    void Rational::reduce()
    {
        int* numerator = &n;
        int* denominator = &d;
        reduce_inpl(numerator, denominator);//sfruttando i puntatori mi basta una funzione
        if (*numerator != 0) //attenzione alla dereferenziazione!
            reduce_inpl(denominator, numerator);
        fix_sign(numerator, denominator);
    }

} // namespace rational_number