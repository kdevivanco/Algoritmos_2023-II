#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge
{
    char init;
    char end;
    float weight;
};

vector<vector<int>> FloydWarshall(vector<char> vertices, vector<Edge> aristas)
{
    int V = vertices.size();
    vector<vector<float>> dists(V, vector<float>(V, numeric_limits<float>::max()));
    vector<vector<int>> tour(V, vector<int>(V, -1));

    for (int i = 0; i < V; i++) {
        dists[i][i] = 0; // distancia de un vértice a si mismo es 0
    }

//    Primera inicializacion de la matriz de distancias
//    distancias directas para las aristas existentes
    for (const Edge& edge : aristas) {
        int u = edge.init - '1';
        int v = edge.end - '1';
        dists[u][v] = edge.weight;
        tour[u][v] = v;
    }

    for (int k = 0; k < V; k++) { //O(n^3) - n = |V|
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dists[i][k] + dists[k][j] < dists[i][j]) {
                    dists[i][j] = dists[i][k] + dists[k][j];
                    tour[i][j] = tour[i][k];
                }
            }
        }
    }

    return tour;
}

void displayPath(vector<vector<int>> tour, char init, char end) //O(n) - Tamano del camino  - peor de los casos es O(V)
{
    int start = init - '1';
    int target = end - '1';

    if (tour[start][target] == -1) {
        cout << "No existe camino de " << init << " hasta " << end << endl;
    } else {
        cout << "Camino mas corto " << init << " to " << end << ": " << endl;
        cout << init;
        while (start != target) {
            start = tour[start][target];
            cout << "->" << char('1' +  start);
        }
        cout << endl;
    }
}

void test1(){
    vector<char> vertices = {'1','2','3','4','5'};
    vector<Edge> aristas =
            {{'1', '3', 6},
             {'1', '4', 3},
             {'2', '1', 3},
             {'3', '4', 2},
             {'4', '2', 1},
             {'4', '3', 1},
             {'5', '2', 4},
             {'5', '4', 2}
            };
    vector<vector<int>> tourMatrix = FloydWarshall(vertices, aristas);
    displayPath(tourMatrix, '5','1');//5->4->2->1
    displayPath(tourMatrix, '2','3');//2->1->4->3
    displayPath(tourMatrix, '5','3');//5->4->3
}
void test2(){
    vector<char> vertices = {'1','2','3','4'};
    vector<Edge> aristas =
            {{'1', '3', -2},
             {'2', '1', 4},
             {'2', '3', 3},
             {'3', '4', 2},
             {'4', '2', -1}
            };
    vector<vector<int>> tourMatrix = FloydWarshall(vertices, aristas);
    displayPath(tourMatrix, '2','3');//2->1->3
    displayPath(tourMatrix, '4','3');//4->2->1->3
    displayPath(tourMatrix, '2','4');//2->1->3->4
}
int main(){
    test1();
    test2();
}
