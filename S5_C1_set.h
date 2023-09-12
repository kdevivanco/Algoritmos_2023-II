//
// Created by MacBookPro on 11/09/23.
//
#include <iostream>
#include <vector>


template<typename T>
class Set{
private:
    //todo atributos

    public:
    Set();
    void Insert(T data); //O(1)
    //En un BST balanceadeo -> O(log(n)) los metodos que son O(1)
    void Remove(T data); //O(1)
    bool Contains(T data); //O(1)
    Set Union(const Set &other); // O(n)
    //Si fuera con BST balanceado -> inorder iteration ->
    // n elementos, se insertan con log(n) === O(nlog(n))

    Set Intersection(const Set &other); //O(n)
    // En BTS balanceado -> O(nlog(n))
    // Se hace primero find (log(n)), y luego insert (log(n)), n veces
    // Como es uno despues de otro, y no anidado es una suma de dos log(n) * n veces => O(nlog(n))



    // const Set &other ->
    // Se envia asi para que no se modifique, es constante y no se cree un objeto nuevo (copia) del og
    Set Difference(const Set &other); //O(n)
    //Find:
    T find(T data);

    std::vector<T> sort();
    // Complejidad algoritmica -> O(n) -- inorder para recorrer e insertar
    //O(nlog(n)) -- sort
    //O(n) -- inorder para recorrer e insertar


//    Set SymmetricDifference(const Set &other);
//    Set CartesianProduct(const Set &other);
    ~Set();
    void print();
};

//Pregunta de examen: Como implementar la interseccion
