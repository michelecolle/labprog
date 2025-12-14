#ifndef MyVector_hpp
#define MyVector_hpp

#include <iostream>
#include <stdexcept>

// Costruttore
template <typename T>
MyVector<T>::MyVector() : buffer_size(8)
{
    size = 0;
    data = new T[buffer_size]; // Allocazione dinamica del buffer
}
template <typename T>
MyVector<T>::MyVector(unsigned int length) : buffer_size(length)
{
    size = 0;
    data = new T[length]; // Allocazione dinamica del buffer
}

// costruttore di copia
template <typename T>
MyVector<T>::MyVector(const MyVector<T> &v)
    : size{v.size}, buffer_size{v.buffer_size}, data{new T[buffer_size]}
{
    std::copy(v.data, v.data + v.size, data);
}

// operatore di copia
template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &v)
{
    size = v.size;
    T *temp = nullptr;
    if (v.size < buffer_size)
    {
    temp = new T[buffer_size];
    }
    else
    {
        temp = new T[v.buffer_size];
    }

    std::copy(v.data, v.data + v.size, temp) ;
    delete[] data;
    data = temp;
    return *this;
}

// Distruttore
template <typename T>
MyVector<T>::~MyVector()
{
    delete[] data; // Deallocazione della memoria
    data = nullptr;
}

// Overloading dell'operatore []
template <typename T>
T &MyVector<T>::operator[](int index)
{
    return data[index];
}

// Overloading dell'operatore []
template <typename T>
const T &MyVector<T>::operator[](int index) const
{
    return data[index];
}

// Funzione push_back() che aggiunge un elemento alla fine;
template <typename T>
void MyVector<T>::push_back(T value)
{
    if (size == buffer_size)
    {
        MyVector<T>::resize_buffer(size * 2);
    }
    data[size] = value;
    size++;
}

// Funzione pop_back() che rimuove l’ultimo elemento;
template <typename T>
void MyVector<T>::pop_back()
{
    if (size == 0)
    {
        throw std::length_error("MyVector is empty");
    }
    else
    {
        size--;
    }
}

// Funzione per riallocare il buffer
template <typename T>
void MyVector<T>::resize_buffer(int new_buffer_size)
{
    T *new_data_buffer = new T[new_buffer_size];

    std::copy(data, data + size, new_data_buffer);
    delete[] data;

    data = new_data_buffer;
    buffer_size = new_buffer_size;
}

// Accesso con boundary check
template <typename T>
T &MyVector<T>::at(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index is out of range");
    }
    else
    {
        return data[index];
    }
}

// Impone una dimensione minima del buffer
template <typename T>
void MyVector<T>::reserve(int min_buffer_size)
{
    if (min_buffer_size > buffer_size)
    {
        MyVector<T>::resize_buffer(min_buffer_size);
    }
}

// Restituisce la dimensione attuale del vettore
template <typename T>
unsigned int MyVector<T>::get_size() const
{
    return size;
}

#endif