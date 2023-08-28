//
// Created by MacBookPro on 17/08/23.
//
#include <iostream>
//https://www.youtube.com/watch?v=okr-XE8yTO8

using namespace std;

template<typename T>
class Queue{
private:
    T *array;
    int capacity;
    int front, back;

public:
    Queue<T>(int capacity){
        this->capacity = capacity;
        array = new T[capacity];
        front = back = -1;
    }
    virtual ~Queue(){
        delete[] array;
    }
    void resize() {
        size_t newSize = capacity + 1;
        int* newArr = new int[newSize];
        for (int i = 0; i < capacity; ++i) {
            newArr[i] = array[i];
        }

        capacity = newSize;
        delete [] array;
        array = newArr;
    }

    bool is_full(){
        return (back + 1) % capacity == front;
    }
    bool is_empty(){
        return front == -1;
    }
    void enqueue(T data){
        if (is_full()){
            this->resize();
        }
        if (is_empty()){
            front = back = 0;
        } else {
            back = (back + 1) % capacity;
        }
        array[back] = data;
    }
    T dequeue(){
        if (is_empty()){
            cout << "Queue is empty" << endl;
            return T();
        }
        T data = array[front];
        if (front == back){
            front = back = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return data;
    }
    void display(){
        if (is_empty()){
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (i != back){
            cout << array[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << array[i] << endl;
    }
};


int main()
{
    Queue<int> cola(4);
    cola.enqueue(10);
    cola.enqueue(8);
    cola.enqueue(4);
    cola.enqueue(9);
    cola.enqueue(1);
    cola.display();//10,8,4,9,1
    cola.dequeue();
    cola.dequeue();
    cola.display();//4,9,1
    return 0;
}
