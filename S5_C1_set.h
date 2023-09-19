//
// Created by MacBookPro on 11/09/23.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
template<typename T>
class Set{
private:
    struct Node{
        T data;
        Node* left;
        Node* right;
        Node(T data){
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

public:
    Set(){
        root = nullptr;
    }
    void insert(T data){
        Node* nuevo = new Node(data);
        if (root == nullptr){
            root = nuevo;
            return;
        }
        Node* temp = root;
        while (temp != nullptr){
            if (data == temp->data){
                return;
            }
            if (data < temp->data){
                if (temp->left == nullptr){
                    temp->left = nuevo;
                    return;
                }
                temp = temp->left;
            }
            else{
                if (temp->right == nullptr){
                    temp->right = nuevo;
                    return;
                }
                temp = temp->right;
            }
        }
    }

    void Remove(T data){
        Node* temp = root;
        Node* parent = nullptr;
        while (temp != nullptr && temp->data != data){
            parent = temp;
            if (data < temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
    }
    bool Contains(T data){
        Node* temp = root;
        //Recorremos el arbol
        while (temp != nullptr){
            if (data == temp->data){
                return true;
            }
            if (data < temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        return false;
    }
    Set<T> Union(const Set &other) {
        Set<T> result;
        // Recorremos el arbol en inorden y vamos insertando en el set
        stack<Node *> s;
        Node *temp = root;
        while (temp != nullptr || !s.empty()) { // O(n)
            while (temp != nullptr) { //O(log(n))
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            result.insert(temp->data);
            temp = temp->right;
        }


        s = stack<Node *>(); // Limpiamos el stack, empezamos con el otro:
        temp = other.root;
        while (temp != nullptr || !s.empty()) { // O(n)
            while (temp != nullptr) { //O(log(n))
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            result.insert(temp->data);
            temp = temp->right;
        }

        return result;
    }


    Set Intersection(const Set &other){
        Set<T> result;
        Node* temp = root;
        while (temp != nullptr){
            if (other.Contains(temp->data)){
                result.Insert(temp->data);
            }
            temp = temp->left;
        }
        return result;
    }

    Set Difference(const Set &other){
        Set<T> result;
        Node* temp = root;
        while (temp != nullptr){
            if (!other.Contains(temp->data)){
                result.Insert(temp->data);
            }
            temp = temp->left;
        }
        return result;
    }

    bool find(T data){
        Node* temp = root;
        while (temp != nullptr){
            if (data == temp->data){
                return true;
            }
            if (data < temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        return false;
    }

    void display(){
        inorder_iter();
    }

    void inorder_iter(){
        stack<Node*> s;
        Node* temp = root;
        while (temp != nullptr || !s.empty()){
            while (temp != nullptr){
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << endl;
    }

    //destructor:
    ~Set(){
        destructor(root);
    }

    void destructor(Node* node){
        if (node == nullptr){
            return;
        }
        destructor(node->left);
        destructor(node->right);
        delete node;
    }
};

//Pregunta de examen: Como implementar la interseccion
