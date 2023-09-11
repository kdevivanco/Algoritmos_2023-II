//
// Created by MacBookPro on 11/09/23.
//

#include<iostream>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<string,int> myhash;
    myhash.insert({"juan",18});
    myhash.insert({"pedro",20});
    myhash.insert({"maria",19});
    myhash.insert({"jose",21});
    myhash.insert({"jose",28});
    myhash.insert({"andy",21});
    // Si insertamos un elemento repetido. o un elemento con la misma llave, no lo inserta
    for (unordered_map<string,int>::iterator it = myhash.begin(); it != myhash.end(); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }

    cout << "nuevoooo ----- "<<endl;

    // Pero si se reasigna, si lo chanca:
    myhash["maria"] = 28;


    //Enumerar elementos, chaining
    //Con hash se pierde el orden de entrada de los datos
    // Tampoco te ordena por la llave
    // Hash te ordena por el hash de la llave

    //Iterador bucket por bucket:

    int num_buckets = myhash.bucket_count();
    cout << "num_buckets: " << num_buckets << endl;
    // El tamano del array del hash els el num de buckets




    //Ahora queremos saber cuales de esos buckets tienen datos:

    for (int i = 0; i <num_buckets ;i++){
        cout << "Bucket " << i << " => ";
        for (auto it = myhash.begin(i); it != myhash.end(i); it++){
            cout << it->first << " " << it->second << ", ";
        }
        cout << endl;
    }
    hash<string> f_hash;
    cout << "hash de juan: " << f_hash("juan") << endl;

    cout << f_hash("pedro") % num_buckets << endl; // Esto nos dice en que bucket esta juan

    // Si queremos saber si un elemento esta en el hash:


    // find retorna un iterador al elemento, si no lo encuentra, retorna un iterador al final del hash
    auto it = myhash.find("juan");
    cout << "esta juan? " << (it != myhash.end()) << endl; // 1 = true 0 = false



    return 0;


}