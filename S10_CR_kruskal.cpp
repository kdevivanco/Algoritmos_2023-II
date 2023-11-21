#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    char init;
    char end;
    int weight;
    Edge (char i, char e, int w = 0) {
        init = i;
        end = e;
        weight = w;
    }
};

class DisjointSetArray {
private:
    vector<char> parent;

public:
    DisjointSetArray(vector<char> vertices) : parent(vertices.size()) {
        for (size_t i = 0; i < vertices.size(); ++i) {
            parent[i] = vertices[i];
        }
    }

    void coutcout(){
        for (size_t i = 0; i < parent.size(); ++i) {
            cout << parent[i] << " ";
        }
        cout << endl;
    }


    char Find(char vertex) {
        if (vertex == parent[vertex - 'A']) {
            return vertex;
        }
        return Find(parent[vertex - 'A']);
    }

    char FindPC(char vertex) {
        if (vertex == parent[vertex - 'A']) {
            return vertex;
        }
        parent[vertex - 'A'] = Find(parent[vertex - 'A']);

        auto result =  parent[vertex - 'A'];
        return result;
    }

    void Union(char a, char b) {
        char parentA = Find(a);
        char parentB = Find(b);
        parent[parentA - 'A'] = parentB;
    }
};

vector<Edge> kruskal(vector<char> vertices, vector<Edge> edges) {
    vector<Edge> result;

    DisjointSetArray ds(vertices);

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    for (size_t i = 0; i < edges.size(); ++i) {
        if (ds.FindPC(edges[i].init) != ds.FindPC(edges[i].end)) {
            result.push_back(edges[i]);
            ds.Union(edges[i].init, edges[i].end);
        }
    }

    return result;
}

void mostrar_ordenado(const vector<Edge>& result) {
    for (const Edge& edge : result) {
        cout << "'" << edge.init << "' '"<< edge.end << "' "  << edge.weight << endl;
    }
}

int main() {
    vector<char> vertices = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    vector<Edge> aristas = {{'A','B',  1},
                            {'A', 'C', 3},
                            {'A', 'D', 5},
                            {'B', 'D', 6},
                            {'C', 'D', 4},
                            {'C', 'E', 7},
                            {'D', 'F', 2},
                            {'E', 'F', 9},
                            {'E', 'G', 4},
                            {'F', 'H', 3},
                            {'G', 'H', 8}};

    vector<Edge> result = kruskal(vertices, aristas);
    mostrar_ordenado(result);


}