//
// Created by MacBookPro on 12/09/23.
//

#include "S5_C1_set.h"
using namespace std;
int main(){
    Set<int> myset;
    myset.insert(10); myset.insert(5); myset.insert(8); myset.insert(10);
    myset.insert(2); myset.insert(5); myset.insert(15); myset.insert(3);
    myset.display();//2,3,5,8,10,15,
    cout<<myset.find(8)<<endl;//1
    cout<<myset.find(18)<<endl;//0
    Set<int> myset2;
    myset2.insert(9); myset2.insert(5); myset2.insert(15); myset2.insert(30);
    Set<int> myset3 = myset.Union(myset2);
    myset3.display();//2,3,5,8,9,10,15,30
    //destructor
}