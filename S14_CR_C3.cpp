//
// Created by MacBookPro on 17/11/23.
//
#include <vector>
#include <iostream>
int CONT = 0;

using namespace std;

template<typename T>
void conjuntoPotencia(vector<T>& conjunto, int indice, vector<T>& subconjunto, vector<vector<T>>& conjuntoPot, const T& P, T currentSum) {
    if (indice == conjunto.size()) {
        if (currentSum == P) {
            conjuntoPot.push_back(subconjunto);
        }
        return;
    }

    subconjunto.push_back(conjunto[indice]);
    conjuntoPotencia(conjunto, indice + 1, subconjunto, conjuntoPot, P, currentSum + conjunto[indice]);
    subconjunto.pop_back();
    conjuntoPotencia(conjunto, indice + 1, subconjunto, conjuntoPot, P, currentSum);
}

template<typename T>
void displayAllSubsets(vector<T>& conjunto, const T& P) {
    vector<vector<T>> conjuntoPot;
    vector<T> subconjunto;
    conjuntoPotencia(conjunto, 0, subconjunto, conjuntoPot, P, 0);

    // Imprimir subconjuntos con suma igual a P
    for (const auto& subc : conjuntoPot) {
        cout << "{ ";
        for (const auto& elem : subc) {
            cout << elem << " ";
        }
        cout << "}" << endl;
    }
}



template<typename T>
void displayAllSubsets_pruning(vector<T> set, int sum, int currentSum, int index, vector<T> subset, vector<vector<T>>& subsets) {
    // cota inferior
    if (currentSum > sum) {
        return;
    }

    // cota superior
    if (currentSum == sum) {
        subsets.push_back(subset);
        return;
    }

    // caso recursivo
    for (int i = index; i < set.size(); ++i) {
        subset.push_back(set[i]);
        displayAllSubsets_pruning(set, sum, currentSum + set[i], i + 1, subset, subsets);
        subset.pop_back();
    }


}

// Wrapper function with initial parameters
template<typename T>
void displayAllSubsets_pruning(vector<T> set, int sum) {
    vector<vector<T>> subsets;
    vector<T> subset;
    int currentSum = 0;
    int index = 0;
    displayAllSubsets_pruning(set, sum, currentSum, index, subset, subsets);
    for (int i = 0; i < subsets.size(); ++i) {
        cout << "{";
        for (int j = 0; j < subsets[i].size(); ++j) {
            cout << subsets[i][j] << " ";
        }
        cout << "}" << endl;
    }
}



//TO-DO
int main(){
    vector<int> conjunto = {1,2,3,4,5,6,7,8,9,10};
    int P = 5;
    CONT = 0;
    displayAllSubsets(conjunto, P);
    cout<<"Sin optimizar:"<<CONT<<endl;
//{5}
//{2 3}
//{1 4}
    int K = 5;
    CONT = 0;
    displayAllSubsets_pruning(conjunto, K );
//{5}
//{2 3}
//{1 4}
    cout<<"Optimizado:"<<CONT<<endl;
}
