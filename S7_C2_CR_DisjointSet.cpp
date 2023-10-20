#include <iostream>
#include <forward_list>
#include <functional>
#define MAX_COLISION 3
using namespace std;

template<typename TK, typename TV>
class DSHash
{
private:
    struct Entry{
        TK key;
        TV value;
        Entry(TK _k, TV _v) : key(_k), value(_v) {}
    };
    forward_list<Entry>* array; // hash table
    int capacity; // tamanio del hash table
    int size; // total de elementos

public:
    DSHash(int cap = 3) : capacity(cap), size(0) {
        // Inicializar el hashtable
        array = new forward_list<Entry>[capacity];
    }

    ~DSHash() {
        delete[] array;
    }

    void insert(TK key, TV value) {
        size_t index = getHashCode(key) % capacity;
        for (Entry& entry : array[index]) {
            if (entry.key == key) {
                entry.value = value; // actualiza el valor, "chancar"
                return;
            }
        }
        // si la llave es nueva...
        Entry entry(key, value); // crea nuevo entry
        array[index].push_front(entry); // anade
        size++;
    }

    TV find(TK key) {
        size_t index = getHashCode(key) % capacity;
        // buscamos la incidencia
        for (const Entry& entry : array[index]){
            if (entry.key == key){
                return entry.value;
            }
        }
        // si nunca encuentra el caso...
        throw runtime_error("No se encontro el elemento en ninguna llave");
    }

    void Union(TK elem1, TK elem2) {
        // mezclar los conjuntos que pertenecen elem1 y elem2
        // ubicamos cada valor
        TV set1 = find(elem1);
        TV set2 = find(elem2);
        if (set1 != set2) { // si no están unidos
            size_t index = getHashCode(elem2) % capacity;
            for (Entry& entry : array[index]) {
                entry.value = set1;

            }
        }
    }

    void display() {
        for (int i=0; i<capacity; i++) {
            for (Entry& entry : array[i]) {
                if (entry.value) {
                    cout << entry.key << " " << entry.value << endl;
                }
            }
        }
    }

    void remove(TK key){
        size_t index = getHashCode(key) % capacity;
        for (Entry& entry : array[index]){
            if (entry.key == key){
                entry.value = 0;
                return;
            }
        }
        throw runtime_error("No se encontro el elemento en ninguna llave");
    }
    TV getvalue(TK key){
        size_t index = getHashCode(key) % capacity;
        for (Entry& entry : array[index]){
            if (entry.key == key){
                return entry.value;
            }
        }
        throw runtime_error("No se encontro el elemento en ninguna llave");
    }
private:
    size_t getHashCode(TK key) {
        hash<TK> fhash;
        return fhash(key);
    }

    void rehashing() {
        int newcap = capacity * 2;
        forward_list<Entry>* newarr = new forward_list<Entry>[newcap];

        for (int i=0; i<capacity;i++) {
            for (const Entry& entry : array[i]) {
                size_t newIndex = getHashCode(entry.key) % newcap;
                newarr[newIndex].push_front(entry);
            }
        }

        delete[] array; //limpiamos
        array = newarr;
        capacity = newcap;

    }
};