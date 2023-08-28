//
// Created by MacBookPro on 21/08/23.
//

#include <iostream>

using namespace std;


// 1. Invertir lista enlazada

// 2. Mezclar dos listas ordenadas
 // a) Ordenar lista, asignar un puntero en cada lista
 // b) Comparar los punteros, el menor se agrega a la lista resultante y avanza (solo para ese puntero)
 // c) debe hacerse pushfront para mantener menos complejidad algoritmica
 // d) obs: si son iguales, se ponen los dos y se avanza en ambos
 // e) invertir la lista (O(n))


// 3. Hallar la interseccion de dos listas ordenadas
    // a) Ordenar lista, asignar un puntero en cada lista
    // b) Comparar los punteros, el menor se avanza (solo para ese puntero)
    // c) si son iguales, se ponen los dos y se avanza en ambos
    // d) invertir la lista (O(n))


// 4. Implementar algoritmo Insertion Sort para lista enlazada
    // a) Usar puntero temporal, para recorrer L1, y se va insertando en L2,
    // b) Se debe tener un puntero en L2 para saber donde insertar
    // Obs: Se puede ir eliminando de una e insertando en otra


template<typename T>
class ForwardList{
private:
    struct Node{
        T data;
        Node *next;
        Node(T data){
            this->data = data;
            this->next = nullptr;
        }
    };
    Node *head;
    Node *tail;
    int size;

public:
    ForwardList();
    virtual ~ForwardList();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_empty();
    int get_size();
    void clear();
    T& operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    void display(Node n);

};