#include <iostream>

class MyVector {
public:

    MyVector(size_t size)
    {
        size_ = size;
        //chiamo new per allocare un array di interi di dimensione size
        data_ = new double[size_];
    }
    ~MyVector() { delete[] data_; } // destructor to free allocated memory, size é automatica e viene distrutta in autonomia
    size_t size() const { return size_; }
    double& operator[](size_t index) 
    { 
        std::cout << "NONCONST Accessing index: " << index << "\n";
        return data_[index]; 
    }
    const double& operator[](size_t index) const 
    { 
        std::cout << "CONST Accessing index: " << index << "\n";
        return data_[index]; 
    }
    //siccome la funzione 'e const', posso chiamare solo metodi const su 'this'
    //se non avessi l'operatore di accesso agli elementi const, non potrei implementare questa funzione
    double safe_get(size_t index) const
    {
        if (index >= size_ || index < 0)
        {
            std::cerr << "Index out of bounds: " << index << "\n";
            throw std::out_of_range("Index out of bounds");
        }
        return (*this)[index];//devo dereferenziare this per chiamare l'operatore di accesso agli elementi
    }
    double& safe_set(size_t index)//se non metto la & ritorna una copia del valore, non posso usarla per assegnare, errore di compilazione
    {
        if (index >= size_ || index < 0)
        {
            std::cerr << "Index out of bounds: " << index << "\n";
            throw std::out_of_range("Index out of bounds");
        }
        return (*this)[index];//devo dereferenziare this per chiamare l'operatore di accesso agli elementi
    }
private:
    size_t size_;
    double* data_;
};

int main()
{
    MyVector vec(5);
    double p = vec.safe_get(2);
    std::cout << "Value at index 2: " << p << "\n";
    vec[3] = 3.14;
    std::cout << "Value at index 3: " << vec[3] << "\n";

    double pp = vec.safe_set(4) = 42;
    std::cout << "Value at index 4: " << vec.safe_get(4) << "\n";
    std::cout << "Value of pp: " << pp << "\n";

    return 0;
}