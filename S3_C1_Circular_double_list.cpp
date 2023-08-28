//
// Created by MacBookPro on 28/08/23.
//

#include <iostream>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node* next;
    Node* prev;
};

template<typename T>
class CircularList{
private:
    Node<T>* head;
public:
    CircularList(){
        head(new Node<T>);
        head->next = head;
        head->prev = head;
    }

    ~CircularList(){
        //Limpia partir de la cabeza. En cambio el clear,
        // puede que depsues de llamar y limpiar la lista se quiera seguir insertando,
        deletesNodes(head);
    }

    bool is_empty(){
        return head->next == nullptr;
    }

    void push_front(T data){
        Node<T>* nuevo = new Node<T>;
        nuevo->data = data;
        //Si la lista tiene elemntos:
        nuevo->next = head->next;
        nuevo->prev = head;
        head->next->prev = nuevo;
        head->next = nuevo;
    }
    void clear(){
        clear(head->next);
        //Si haces en clear() head = nullptr, ya no se podra insertar mas elementos
        //Se limpia a partir del next, pero el head no se toca
        //Lo deja limpio para nuevas inserciones
    }

    void deletesNodes(Node<T>* &node){
        //borras to do incluyendo este nodo
        // este es el que llama el destructor
    }

    void pop_front(){
        if (is_empty()){
            cout << "Lista vacia" << endl;
            return;
        }
        head->next = head->next->next;
        delete head->next->prev;
        head->next->prev = head;
    }



};