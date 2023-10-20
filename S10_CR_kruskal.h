#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    char init;
    char end;
    int weight;
    Edge(char i, char e, int w = 0){ init = i; end = e; weight = w;}
};


vector<Edge> kruskal(vector<char> vertices, vector<Edge> aristas){
    //usar el DisjointSets
    vector<Edge> solucion;
    DisjoinSetArray<char> ds(vertices);
    //1- ordenar las aristas en funcion del peso

    //2- Recorrer todas las aristas y agregar al árbol solucion
    
    return solucion;
}

void mostrar_ordenado(vector<Edge> result){
    //TODO
}