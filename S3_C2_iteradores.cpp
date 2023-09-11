//
// Created by MacBookPro on 29/08/23.
//

#include <iostream>

using namespace std;

template<typename T>
class Iterator{
private:
    // Current
public:
    Iterator operator++();
    Iterator operator--();
    T operator*();

    Iterator begin(); // Retorna la primera posicion del contenedor
    Iterator end(); // Retorna la ultima posicion del contenedor
    bool operator==(const Iterator& other);
    bool operator!=(const Iterator& other);


    // Constructor
    // Destructor
    // Operator *
    // Operator ++
    // Operator ==
    // Operator !=
};

template<typename T>
class SimpleArray{
private:
    T* array;

};