#include <iostream>
using namespace std;
template <typename TK>
struct Node {
    TK* keys;
    Node** children;
    int count;
    bool leaf;
    int M; // grado u orden del árbol

    Node(int _M) : keys(nullptr), children(nullptr), count(0), leaf(true), M(_M) {
        keys = new TK[M - 1];
        children = new Node<TK>*[M];
    }

    void insert(TK key) {
        int i = 0;
        while (i < count && key > keys[i]) {  //este while es para encontrar la posicion donde se insertara la llave
            i++;
        }

        for (int j = count; j > i; j--) { //este for es para mover las llaves una posicion a la derecha
            keys[j] = keys[j - 1]; // j hace referencia a la posicion de la llave
            // i hace referencia a la posicion donde se insertara la llave
        }
        keys[i] = key;

        count++;
    }

    bool isFull() {
        return (count == M - 1);
    }

    void remove(int index) {
        for (int i = index; i < count - 1; i++) {
            keys[i] = keys[i + 1];
        }
        count--;
    }

    void insertChild(int index, Node<TK>* child) {
        leaf = false;
        for (int i = count; i > index; i--) {
            children[i] = children[i - 1];
        }
        children[index] = child;
        count++;
    }

    std::string toString(const std::string& sep) {
    std::string result;
    for (int i = 0; i < count; i++) {
        if (i > 0) {
            result += sep; 
        }
        result += std::to_string(keys[i]);
    }
    return result;
}

    bool isLeaf() {
        return leaf;
    }

        int height() {
            int height = log(count) / log(M);
            return height;
        }

    bool search(TK key) {
        int i = 0;
        while (i < count && key > keys[i]) {
            i++;
        }

        if (i < count && keys[i] == key) {
            return true;
        } else if (leaf) {
            return false;
        } else {
            return children[i]->search(key);
        }
        return false;
    }

    void clear(){
        for (int i = 0; i < count; i++) {
            keys[i] = 0;
        }
        count = 0;
    }

};
