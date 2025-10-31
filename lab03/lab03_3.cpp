#include <iostream>
void print_pointer(const void* p)//void* non é dereferenziabile
{
    std::cout << "pointer address: " << p <<"\n";
}
//la & indica che si sta passando una reference, ovvero un alias del valore originale
//si accede direttamente all'oggetto referenziato senza dover usare l'operatore di dereferenziazione *
//const mi vieta di modificare tale valore, accetto in sola lettura, pena errore di compilazione
void print_reference(const int& ri, const double& rd)
{
    std::cout << "reference address: " << &ri << " value: " << ri << "\n";
    std::cout << "reference address: " << &rd << " value: " << rd << "\n";
    std::cout << "ri + rd: " << ri+ rd << "\n";
    

    print_pointer(&ri);
    print_pointer(&rd);
}
int main()
{   
    //stampa dell'indirizzo del puntatore e del valore a cui punta
    int num = 42; 
    int * p = &num;
    print_reference(num, 3.14);
    print_pointer(p);
    return 0;
}   