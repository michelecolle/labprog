#include <iostream>
//questa é la dimensione del puntatore a double, in un sistema a 64 bit dovrebbe essere 8 byte
//genera un warning in compilazione
//decadimento dell'array a puntatore
void print_array_length(double arr[])
{
    std::cout << "Length of array pointer in bytes: " << sizeof(arr) << "\n";
}
int main()
{
    double n[10];
    //questa dimensione é corretta
    std::cout << "Length of array n: " << sizeof(n)/sizeof(n[0]) << "\n";
    print_array_length(n);
    return 0;
}