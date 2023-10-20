

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};


template <typename T>
T getKthFromtheEnd(Node* head, int k) {
    Node *buscadorfin = head; // fast
    Node *buscadorposicion = head; //slow
    int counter = 1; // cuenta cuanto ha avanzado el puntero
    while (buscadorfin->next != nullptr) {
        buscadorfin = buscadorfin->next;

        counter++; //se incrementa el ptr primero por si llega nullptr

        if (counter == k) { // por cada k avances,
            counter = 1; // se reinicia
            buscadorposicion = buscadorposicion->next; // El slow avanza al sgte
        }
    }

    return buscadorposicion->next->data;

}

int main(){

    Node *head = new Node(8);
    head->next = new Node(7);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(2);

    cout << getKthFromtheEnd<int>(head, 2) << endl;

}
