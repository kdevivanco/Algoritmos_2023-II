#include <iostream>
#include <stdexcept>

using namespace std;
template <typename T>
static void heapify_down_asc(T* arr, int n, int i) {
    int nod_mayor = i;
    int nod_izq = 2 * i + 1;
    int nod_der = 2 * i + 2;

    if (nod_izq < n && arr[nod_izq] > arr[nod_mayor]) {
        nod_mayor = nod_izq;
    }

    if (nod_der < n && arr[nod_der] > arr[nod_mayor]) {
        nod_mayor = nod_der;
    }

    if (nod_mayor != i) {
        T temp = arr[i];
        arr[i] = arr[nod_mayor];
        arr[nod_mayor] = temp;
        heapify_down_asc(arr, n, nod_mayor);
    }
}

template <typename T>
class Heap {
private:
    T* elements;
    int cap;
    int size;

public:
    static void sortAsc(T* arr, int n) {
        for (int i = n - 1; i > 0; --i) {
            T temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify_down_asc(arr, i, 0);
        }
    }

    Heap(int cap_inicial = 10) {
        cap = cap_inicial;
        elements = new T[cap];
        size = 0;
    }

    ~Heap() {
        delete[] elements;
    }

    void buildFromArray(T* arr, int n) {
        if (n > cap) { // Redimensiona según n
            delete[] elements;
            cap = n;
            elements = new T[cap];
        }

        for (int i = 0; i < n; ++i) {
            elements[i] = arr[i];
        }

        size = n;

        for (int i = (size - 2) / 2; i >= 0; --i) {
            heapify_down(i);
        }
    }

    void push(T val) {
        if (size >= cap) {
            // Duplicar capacidad
            cap *= 2;
            T* new_elements = new T[cap];
            for (int i = 0; i < size; ++i) {
                new_elements[i] = elements[i];
            }
            delete[] elements;
            elements = new_elements;
        }

        elements[size] = val;
        size++;
        heapify_up(size - 1);
    }

    T pop() {
        if (empty()) {
            throw out_of_range("Heap vacío");
        }

        T prim_val = elements[0];
        elements[0] = elements[size - 1];
        size--;
        heapify_down(0);

        return prim_val;
    }

    T top() {
        if (empty()) {
            throw out_of_range("Heap vacío");
        }

        return elements[0];
    }

    void sort() {
        int n = size;
        for (int i = n - 1; i > 0; --i) {
            T temp = elements[0];
            elements[0] = elements[i];
            elements[i] = temp;
            heapify_down_desc(elements, i, 0);
        }
    }

    bool empty() const {
        return size == 0;
    }

private:
    int Parent(int i) {
        return (i - 1) / 2;
    }

    int Left(int i) {
        return 2 * i + 1;
    }

    int Right(int i) {
        return 2 * i + 2;
    }

    void heapify_down(int i) {
        int nodo_izq = Left(i);
        int nodo_der = Right(i);
        int nodo_mayor = i;

        if (nodo_izq < size && elements[nodo_izq] > elements[i]) {
            nodo_mayor = nodo_izq;
        }

        if (nodo_der < size && elements[nodo_der] > elements[nodo_mayor]) {
            nodo_mayor = nodo_der;
        }

        if (nodo_mayor != i) {
            // Intercambia los elementos si es mayor
            T temp = elements[i];
            elements[i] = elements[nodo_mayor];
            elements[nodo_mayor] = temp;
            heapify_down(nodo_mayor);
        }
    }

    void heapify_up(int i) {
        while (i > 0 && elements[Parent(i)] < elements[i]) {
            T temp = elements[i];
            elements[i] = elements[Parent(i)];
            elements[Parent(i)] = temp;

            i = Parent(i);
        }
    }

    void heapify_down_desc(T* arr, int n, int i) {
        int nod_menor = i;
        int nod_izq = 2 * i + 1;
        int nod_der = 2 * i + 2;

        if (nod_izq < n && arr[nod_izq] < arr[nod_menor]) {
            nod_menor = nod_izq;
        }

        if (nod_der < n && arr[nod_der] < arr[nod_menor]) {
            nod_menor = nod_der;
        }

        if (nod_menor != i) {
            T temp = arr[i];
            arr[i] = arr[nod_menor];
            arr[nod_menor] = temp;
            heapify_down_desc(arr, n, nod_menor);
        }
    }
};



int main(){
    //test 1
    Heap<int>* heap = new Heap<int>();
    int array[8] = {23, 10, 49, 50, 13, 12, 9, 45};
    heap->buildFromArray(array, 8);
    cout<<heap->top()<<endl;//50
    heap->push(8);
    heap->push(55);
    heap->push(18);
    cout<<heap->top()<<endl;//55
    heap->pop();
    heap->pop();
    cout<<heap->top()<<endl;//49
    //test 2
    int array2[8] = {23, 10, 49, 50, 13, 12, 9, 45};
    Heap<int>::sortAsc(array2, 8);
    for(int i=0;i<8;i++)
        cout<<array2[i]<<",";
    cout<<endl;
}
