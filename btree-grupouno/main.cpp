
#include <iostream>
#include "btree.h"
#include "tester.h"

using namespace std;

int main() {
//test 1
  BTree<int>* btree = new BTree<int>(3);
  int numbers[10] = {45, 75, 100, 36, 120, 70, 11, 111, 47, 114};
  for (int i = 0; i < 10; i++) {
    btree->insert(numbers[i]);
    cout << btree->toString(" ")<< " ";
    cout << endl;
  }

  ASSERT(btree->toString(" ") == "11 36 45 47 70 75 100 111 114 120",
         "The function insert is not working");


//test 2
  ASSERT(btree->height() == 2, "The function height is not working");
  for (int i = 0; i < 10; i=i+2) {
//test3
    ASSERT(btree->search(numbers[i]) == true,
           "The function search is not working");
  }
//test 4
  ASSERT(btree->minKey() == 11, "The function minKey is not working");
//test 5
  ASSERT(btree->maxKey() == 120, "The function maxKey is not working");

//test 6
  btree->remove(100);
  btree->remove(111);
  btree->remove(45);

  cout << btree->toString(" ") << endl;

  ASSERT(btree->toString(" ") == "11 36 47 70 75 114 120",
         "The function remove is not working");
// test 7
//cout << btree->height() << endl;
  ASSERT(btree->height() == 1, "The function height is not working");

//test 8
  btree->remove(114);
  btree->insert(40);
  cout << btree->toString(" - ") << endl;
  
  ASSERT(btree->toString(" - ") == "11 - 36 - 40 - 47 - 70 - 75 - 120",
         "The function toStrings is not working");
//    cout << btree->height() << endl;
    ASSERT(btree->height() == 2, "The function height is not working");

  btree->insert(125);
  btree->insert(115);
  
  ASSERT(btree->maxKey() == 125, "The function maxKey is not working");
  ASSERT(btree->search(47) == true,  "The function search is not working");  
  
  btree->remove(11);
    
  ASSERT(btree->search(11) == false,  "The function search is not working");
  ASSERT(btree->minKey() == 36, "The function minKey is not working");

   ASSERT(btree->size() == 8, "The function size is not working");
  
  btree->clear();  
  ASSERT(btree->size() == 0, "The function size is not working");
//    cout << btree->height() << endl;

    ASSERT(btree->height() == 0, "The function height is not working");

  return 0;
}
