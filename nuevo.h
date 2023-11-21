#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <random>
#include <list>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

#define ASSERT(condition, message) \
    if (!(condition)) { \
        cerr << "Assertion failed: " << message << endl; \
        exit(1); \
    }

int generarInt(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

float generarFloat(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}

// Estructura básica de un grafo con lista de adyacencias
template <typename TV, typename TE>
class ListGraph {
public:
    ListGraph() {}

    void addVertex(TV vertex) {
        vertices_.push_back(vertex);
        adjacency_lists_.emplace_back(); // Create an empty adjacency list for the new vertex
    }

    void createEdge(TV from, TV to, TE weight) {
        int from_index = findVertexIndex(from);
        int to_index = findVertexIndex(to);

        // Check if vertices exist, and if not, add them
        if (from_index == -1) {
            addVertex(from);
            from_index = vertices_.size() - 1;
        }
        if (to_index == -1) {
            addVertex(to);
            to_index = vertices_.size() - 1;
        }

        // Create the edge
        adjacency_lists_[from_index].push_back({to, weight});
        adjacency_lists_[to_index].push_back({from, weight});
    }

    int density() {
        int n = vertices_.size();
        int m = 0;
        for (const auto& adjacency_list : adjacency_lists_) {
            m += adjacency_list.size();
        }
        return m / (n * (n - 1));
    }

    void clear() {
        vertices_.clear();
        adjacency_lists_.clear();
    }

    void insertVertex(const TV& vertex) {
        addVertex(vertex);
    }

private:
    vector<TV> vertices_;
    vector<list<pair<TV, TE>>> adjacency_lists_;

    int findVertexIndex(TV vertex) {
        auto it = find(vertices_.begin(), vertices_.end(), vertex);
        if (it != vertices_.end()) {
            return distance(vertices_.begin(), it);
        }
        return -1; // Vertex not found
    }
};


template <typename TV, typename TE>
class HashGraph {
public:
    void addVertex(const TV& vertex) {
        // si el vértice no existe, se crea un nuevo hash para sus adyacencias
        if (graph.find(vertex) == graph.end()) {
            graph[vertex] = unordered_map<TV, TE>();
        }
    }

    void insertVertex(const TV& vertex) {
        addVertex(vertex);
    }

    void createEdge(const TV& from, const TV& to, const TE& weight) {
        // se crea el vértice si no existe
        addVertex(from);
        addVertex(to);

        // se crea la arista
        graph[from][to] = weight;
        graph[to][from] = weight;
    }

    int density() {
        int n = graph.size();
        int m = 0;
        for (const auto& entry : graph) {
            m += entry.second.size();
        }
        return m / (n * (n - 1));
    }

    void clear() {
        graph.clear();
    }

    void kruskalMST() {
        vector<pair<TE, pair<TV, TV>>> edges;
        for (const auto& entry : graph) {
            TV from = entry.first;
            for (const auto& edge : entry.second) {
                TV to = edge.first;
                TE weight = edge.second;
                edges.push_back({weight, {from, to}});
            }
        }

        sort(edges.begin(), edges.end());

        unordered_map<TV, TV> parent;
        vector<pair<TV, TV>> mst;

        for (const auto& edge : edges) {
            TE weight = edge.first;
            TV from = edge.second.first;
            TV to = edge.second.second;

            TV set1 = find(parent, from);
            TV set2 = find(parent, to);

            if (set1 != set2) {
                mst.push_back({from, to});
                unionSets(parent, set1, set2);
            }
        }

        cout << "Aristas del MST:" << endl;
        for (const auto& edge : mst) {
            cout << edge.first << " - " << edge.second << endl;
        }
    }

private:
    unordered_map<TV, unordered_map<TV, TE>> graph;

    TV find(unordered_map<TV, TV>& parent, TV vertex) {
        if (parent.find(vertex) == parent.end() || parent[vertex] == vertex) {
            return vertex;
        }
        return find(parent, parent[vertex]);
    }

    void unionSets(unordered_map<TV, TV>& parent, TV x, TV y) {
        TV rootX = find(parent, x);
        TV rootY = find(parent, y);
        parent[rootX] = rootY;
    }
};

int main() {
    // Grafo estructurado con lista de adyacencias
    ListGraph<int, float> grafitoAdy;
    // Grafo estructurado con hash de adyacencias
    HashGraph<int, float> grafitoHash;

    int N, init, end;
    float peso;

    cout << "hola" << endl;

    cout << N << endl;
    for (int i = 2; i <= 7; ++i) {
        N = pow(10, i);

        // 1-insertar vertices s
        for (int j = 0; j < N; ++j) {
            grafitoAdy.insertVertex(j);
            grafitoHash.insertVertex(j);
        }

        // 2-insertar aristas en ambos grafos (puede variar el factor de densidad)
        for (int j = 0; j < N * (N - 1) * 0.3; ++j) {
            cout << "aqui" << endl;

            init = generarInt(0, N - 1);
            cout << "1" << endl;

            end = generarInt(0, N - 1);
            cout << "3" << endl;

            peso = generarFloat(1, 100);
            cout << "4" << endl;
//
            grafitoAdy.createEdge(init, end, peso);
            cout << "5" << endl;

            grafitoHash.createEdge(init, end, peso);
            cout << "6  "  << endl;
        }

        // Comparar la densidad de los dos grafos
        ASSERT(grafitoAdy.density() == grafitoHash.density(), "Los grafos no son iguales");

        // 3- Ejecutar una operación y capturar los tiempos
        // Aquí puedes agregar la operación que desees realizar y medir el tiempo si es necesario

        // 4- Limpiar el grafo
        grafitoAdy.clear();
        grafitoHash.clear();
    }
}