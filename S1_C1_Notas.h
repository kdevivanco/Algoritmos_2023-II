//
// Created by MacBookPro on 14/08/23.
//

#ifndef ALGORITMOS_S1_C1_NOTAS_H
#define ALGORITMOS_S1_C1_NOTAS_H


#include<iostream>

using namespace std;
void punteros(){
    int a = 10;
    int *p = &a;
    *p = 20;


    short arr[5] = {1, 2, 3, 4, 5};
    cout << arr <<endl;
    cout << &arr[0] <<endl;
    cout << *(arr+0) <<endl; // imprime direccion 0
    cout << *(arr+1) <<endl; // imprime direccion 1
    // cout << *(arr+16) <<endl; // noimprime
}

#endif //ALGORITMOS_S1_C1_NOTAS_H
