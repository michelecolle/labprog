#include <iostream>

class Date {
public:
    //SOLO nei costruttori e con i : si possono inizializzare i membri dopo la dichiarazione
    //nel codice normale non si può fare, a(10); da errore perche' viene interpretato come una dichiarazione di funzione
    Date(int d = 1, int m =1, int y = 1900) : y(y), m(m), d(d) {
        
    }
 // ...
 const int& day() const;
 int month();
 int& year();
 void add_day(int n);
 void add_month(int n);
 void add_year(int n);
 // ...
private:
 int d;
 int m;
 int y;
};

const int& Date::day()  const{
    return d;
}
int Date::month() {
    return m;
}
int& Date::year() {
    return y;
}
void Date::add_day(int n) {
    d += n;
}
void Date::add_month(int n) {
    m += n;
}
void Date::add_year(int n) {
    y += n;
}

int main() {
    int a(5);
    int b;
    b&(10);
    std::cout << a << " " << b << std::endl;

    //const
    Date today(10,12,2023);
    std::cout << today.day()<< std::endl;


    const int& d = today.day(); // OK: day() is a const member function
    //d = d + 1;//errore di compilazione: assignment of read-only location 'd'
    std::cout << today.day()<< std::endl;

    //default constructor
    Date date1{10, 12, 2025};
    std::cout << date1.day()<< std::endl;

    Date date2{10}; // Default constructor

    std::cout << "Test const interface" << std::endl;

    
    return 0;
}