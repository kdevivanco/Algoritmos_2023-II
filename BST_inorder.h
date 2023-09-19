//
// Created by MacBookPro on 11/09/23.
//

#ifndef ALGORITMOS_BST_INORDER_H
#define ALGORITMOS_BST_INORDER_H
#include<stack>
#include<iostream>

using namespace std;


template<typename t>
class Node{
public:
    t data;
    Node* left;
    Node* right;
    Node(t data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};


template<typename T>
class BST {
private:
    Node<T>* root;
public:

    auto begin(){
        return iterator(root); // iterator(root) es un objeto de la clase iterato
        //El current no se ubica en la raiz
    }



    void inorder_iter(){
        stack<T> mystack;
        Node<T>* temp ;
        temp = root;
        while (temp != nullptr || !mystack.empty()){
            while (temp != nullptr){
                mystack.push(temp);
                temp = temp->left;
            }
            while(!mystack.empty()){
                temp = mystack.top();
                mystack.pop();
                cout << temp->data << " ";
                temp = temp->right;
                while (temp != nullptr){
                    mystack.push(temp);
                    temp = temp->left;
                }
            }
        }

    }
};


template<typename T>
class Iterator{
    Node<T> *current;
    stack<Node<T>> mystack;

    Iterator(Node<T>* root){
        Node<T>* temp = root;
        while (temp != nullptr){
                mystack.push(temp);
                temp = temp->left;
        }

        current = mystack.pop();
    }

    void operator++(){
        Node<T>* temp = current->right;
        while (temp != nullptr){
            mystack.push(temp);
            temp = temp->left;
        }
        current = mystack.pop();
    } // Termina cuando el stack esta vacio

    T operator*(){
        return current->data;
    }
};
#endif //ALGORITMOS_BST_INORDER_H
