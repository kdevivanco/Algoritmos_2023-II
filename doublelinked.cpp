//
// Created by MacBookPro on 3/10/23.
//


#include<iostream>
using namespace std;


template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template<typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    //overload ==
    bool operator==(const DoubleLinkedList<T>& other) {
        if (size != other.size) {
            return false;
        }
        Node<T>* temp1 = head;
        Node<T>* temp2 = other.head;
        while (temp1 != nullptr) {
            if (temp1->data != temp2->data) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};