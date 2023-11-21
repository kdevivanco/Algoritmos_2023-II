//
// Created by MacBookPro on 7/11/23.
//


#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <unistd.h>
using namespace std;

const string alfabeto =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";
string generarTexto(size_t N)
{
    string resultado = "";
    for (size_t i = 0; i < N; i++)
        resultado += alfabeto[rand() % alfabeto.size()];
    return resultado;
}

vector<int> testInocente(string Texto, string Patron) {
    //va buscando patron por patron
    auto start = std::chrono::steady_clock::now();
    vector<int> result;

    for (int i = 0; i <= Texto.size() - Patron.size(); i++) {
        int j;
        for (j = 0; j < Patron.size(); j++) {
            if (Texto[i+j] != Patron[j]) { // si no son iguales termina el loop
                break;
            }
        }
        if (j == Patron.size()) { // cuando sea igual entonces se encontro
            result.push_back(i);
        }
    }

    auto end = std::chrono::steady_clock::now();
    cout << "Inocente time in milliseconds: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " ms" << endl;
    for (auto &elem : result){
        elem -=1;
    }
    return result;
}

vector<int> testBoyerMoore(string Texto, string Patron) {
    auto start = std::chrono::steady_clock::now();
    vector<int> result;

    int n = Texto.size();//numero total de caracteres
    int m = Patron.size(); // numero de caracteres del patron


    vector<int> badChar(256, -1); //256 caracteres ASCII
    for (int i = 0; i < m; i++) { //Se llena la tabla de bad character
        badChar[Patron[i]] = i;
    }

    int s = 0; // s marca la posicion del texto
    while (s <= (n - m)) { // menor o igual a la posicion maxima
        int j = m - 1;

        while (j >= 0 && Patron[j]==Texto[s+j]) { // comparacion derecha izq
            j--;
        }

        if (j < 0) { // si j es menor a 0, se encontro el patron
            result.push_back(s);
            if (s + m < n) { //
                s += m - badChar[Texto[s + m]];
            } else { // Si no hay espacio, se mueve 1
                s += 1;
            }
        } else {
            s += max(1, j - badChar[Texto[s + j]]); 
        }
    }

    auto end = std::chrono::steady_clock::now();
    cout << "BoyerMoore - tiempo en milisec: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " ms" << endl;

    for (auto &elem : result){
        elem = elem - 1 ;
    }

    return result;
}


void verificarResultado(vector<int> result1, vector<int> result2)
{
    if (result1.size() != result2.size())

        cerr << "Error!! el resultado no es el mismo\n";
    for (int i = 0; i < result1.size(); i++)
//        cout << result1[i] << " ";
        if (result1[i] != result2[i])
//            cout << result1[i] << " " << result2[i] << endl;
            cerr << "Error!! el resultado no es el mismo\n";
}

int main()
{
    srand(time(NULL));
    size_t N = 10000000; // 100,1000,10000,100000,1000000
    int m = 10;
    string Texto = "AABAACAADAABAABA";
    string Patron = "ABA";
    vector<int> resulta = testInocente(Texto, Patron);
    vector<int> resultb = testBoyerMoore(Texto, Patron);
    for(int i = 0; i < resulta.size(); i++) {
        cout << resulta[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < resultb.size(); i++) {
        cout << resultb[i] << " ";
    }
    cout << endl;
    cout << "-----------------------------" << endl;
    return 0;
}

//100:
//Inocente time in milliseconds: 7 ms
//BoyerMoore - tiempo en milisec: 5 ms

//1000
//74
//13


//10000
//605
//47

//100000
// 6414
//525

//1000000
//63863
//4715


//10 000 000
//670689
//57102