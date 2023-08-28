//
// Created by MacBookPro on 22/08/23.
//

#include <iostream>
using namespace std;
#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node* next;
};


void sorted_insert(Node*& head, int data){
    Node* nuevo = new Node;
    nuevo->data = data;
    nuevo->next = nullptr;
    //1er caso: lista vacia o nodo menor al data
    if (head == nullptr || head->data >= data){
        nuevo->next = head;
        head = nuevo;
    }  // 2do caso
    else {
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data < data){
            temp = temp->next;
        }
        nuevo->next = temp->next;
        temp->next = nuevo;
    }
}

void display(Node* head){
    //Caso base: lista vacia
    if (head == nullptr) {
        cout << "Lista vacia" << endl;
        return;
    }
    // Itera por la lista usando next, hasta que el next sea nullptr
    Node* temp = head;
    while (temp != nullptr){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

void push_front(Node*& head, int data){
    //Asigna un nuevo nodo, y el next del nuevo apunta al head
    //Luego vuelve el head el nuevo, para que sea el primero
    // Complejidad: O(1)
    Node* nuevo = new Node;
    nuevo->data = data;
    nuevo->next = head;
    head = nuevo;
}

Node* union_lists(const Node* h1, const Node* h2) {
    Node* res = nullptr;
    Node** tercerpuntero = &res; // Pointer to the last node in the result list

    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data < h2->data) {
            *tercerpuntero = new Node{h1->data, nullptr};
            h1 = h1->next;
        } else if (h1->data > h2->data) {
            *tercerpuntero = new Node{h2->data, nullptr};
            h2 = h2->next;
        } else {
            *tercerpuntero = new Node{h1->data, nullptr};
            h1 = h1->next;
            h2 = h2->next;
        }
        tercerpuntero = &((*tercerpuntero)->next);
    }

    // Attach remaining elements if any
    while (h1 != nullptr) {
        *tercerpuntero = new Node{h1->data, nullptr};
        h1 = h1->next;
        tercerpuntero = &((*tercerpuntero)->next);
    }
    while (h2 != nullptr) {
        *tercerpuntero = new Node{h2->data, nullptr};
        h2 = h2->next;
        tercerpuntero = &((*tercerpuntero)->next);
    }

    return res;
}


void test1(){
    Node* head = nullptr;
    sorted_insert(head, 10);//O(n)
    sorted_insert(head, 5);
    sorted_insert(head, 4);
    sorted_insert(head, 8);
    sorted_insert(head, 12);
    display(head);//4->5->8->10->12->
}

void test2()
{
    Node* head1 = nullptr;
    push_front(head1, 10);
    push_front(head1, 8);
    push_front(head1, 6);
    push_front(head1, 2);
    Node* head2 = nullptr;
    push_front(head2, 12);
    push_front(head2, 11);
    push_front(head2, 8);
    push_front(head2, 7);
    push_front(head2, 4);
    push_front(head2, 2);
    Node* head3 = union_lists(head1, head2);
    display(head1);//2->6->8->10->
    display(head2);//2->4->7->8->11->12->
    display(head3);//2->4->6->7->8->10->11->12->
}

int main(){
    //1- Inserta ordenado
    test1();
    //2- Union de listas ordenadas
    test2();
}