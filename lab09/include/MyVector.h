#ifndef MyVector_h
#define MyVector_h

template<typename T> class MyVector {
    
public:
    // Costruttore
    MyVector();

    MyVector(unsigned int length);

    //costruttore di copia
    MyVector(const MyVector<T>& v);


    //operatore di copia 
    MyVector<T>& operator=(const MyVector<T>& v);


    // Distruttore
    ~MyVector();

    // Overloading dell'operatore []
    T& operator[](int index);
    const T& operator[](int index) const;

    // Funzione push_back() che aggiunge un elemento alla fine;
    void push_back(T value);

    // Funzione pop_back() che rimuove l’ultimo elemento;
    void pop_back();

    // Accesso con boundary check 
    T& at(int index);

    // Impone una dimensione minima del buffer
    void reserve(int min_buffer_size);

    // Restituisce la dimensione attuale del vettore
    unsigned int get_size() const;

private:
    unsigned int size;        // Memorizza il numero di elementi del vettore
    unsigned int buffer_size; // Memorizza la lunghezza del buffer
    T* data;    // Puntatore al buffer dinamico che contiene i dati

    // Funzione per riallocare il buffer
    void resize_buffer(int new_buffer_size);
    
};
// A differenza della convenzione .h/.cpp, l'implementazione delle funzioni membro è qui nel file .hpp
// in questo caso il file .hpp viene incluso alla fine del file .h e va salvato nella cartella include
// perché è un header e non un file di implementazione .cpp
// questo perché si tratta di un template e il compilatore deve avere accesso all'implementazione
// del template in fase di compilazione
// in pratica è come se fosse tutto in un unico file .h
#include "MyVector.hpp"

#endif