
#include <iostream>
//#include "solucion.h"

using namespace std;


int COUNT = 0;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

void push_front(Node*& head, int value){
    Node* nuevo = new Node;
    nuevo->data = value;
    nuevo->next = head;
    nuevo->prev = nullptr;

    if (head != nullptr) {
        head->prev = nuevo;
    }

    head = nuevo;
}


bool search(Node*& head, int value) {
    Node* slow = head;
    Node* fast = head;

    if(head->data == value){

        return true;
    }

    if(head->next->data==value){
        COUNT++;
        return true;
    }


    if (fast->next->next->data == value){
        COUNT++;
        COUNT++;
        Node* temp = fast->next->next;
        fast->next->next = temp->next;
        fast->next->next->prev = fast->next->next;

        temp->next = slow;
        slow->prev = temp;
        head = temp;
        return true;

    }

    //Empiezan juntos, luego fast avanza 1
    while (fast != nullptr && fast->data != value) {
        fast = fast->next;
        COUNT++;
        //fast avanza dos
        if (fast != nullptr && fast->data != value) {
            fast = fast->next;
            COUNT++;

            slow = slow->next;
        }
    }

    if (fast->data == value) {
        if (slow != fast) {
            fast->prev->next = fast->next;
            if (fast->next != nullptr) {
                fast->next->prev = fast->prev;
            }

            fast->next = slow->next;
            fast->prev = slow;
            slow->next = fast;

            return true;
        }
    }

    return false;
}

void display(Node* head){
    Node* current = head; // Start from the first node
    while(current != nullptr){
        cout << current->data << "->";
        current = current->next;
    }

}

int main(){
    Node* head = nullptr;
    for(int i=0; i<10; i++)
        push_front(head, (10-i)*2);
    display(head);//2->4->6->8->10->....
    bool result = false;
    cout<<endl;
    for(int i=0;i<8;i++)
    {
        COUNT = 0;
        result = search(head, 16);
        cout<<result<<"("<<COUNT<<")"<<endl;
        // display(head);
        // cout<<endl;
    }
    display(head);
    // 1
    return 0;
}