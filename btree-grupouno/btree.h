#ifndef BTree_H
#define BTree_H

#include <iostream>
#include "node.h"

using namespace std;

template <typename TK>
class BTree
{
private:
  Node<TK> *root;
  int M; // grado u orden del árbol
  int n; // total de elementos en el árbol

    void insert(TK key, Node<TK> *node) {
        if (node->isLeaf())
        {
            for (int i = 0; i < node->count; i++) {
                if (node->keys[i] == key) {
                    return;
                }
            }
            node->insert(key);
        }
        else
        {
            // Sino tiene que encontrar el child donde insertarlo
            int i = 0;
            while (i < node->count && key > node->keys[i]){
                i++;
            }

            // se inserta resursivamente en el child??
            insert(key, node->children[i]);

            // si el child node esta full se separa
            if (node->children[i]->isFull())
            {
                splitChild(node, i);
            }
        }
    }

    void splitChild(Node<TK> *parent, int childIndex)
    {
        Node<TK> *child = parent->children[childIndex];
        Node<TK> *newChild = new Node<TK>(M);

        for (int i = M / 2, j = 0; i < child->count; i++, j++)
        {
            newChild->insert(child->keys[i]);
        }

        child->count = M / 2;

        for (int i = parent->count; i > childIndex; i--){
            parent->children[i + 1] = parent->children[i];
        }

        parent->insert(child->keys[M / 2]);
        parent->insertChild(childIndex + 1, newChild);

        if (parent->isFull()){
            Node<TK> *newRoot = new Node<TK>(M);
            newRoot->insertChild(0, root);
            splitChild(newRoot, 0);
            root = newRoot;
        }
    }

public:
  BTree(int _M) : root(nullptr), M(_M) {}

  bool search(TK key) // complejidad O(log n)
  {
    for (int i = 0; i < root->count; i++)
    {
      if (root->keys[i] == key)
      {
        return true;
      }
    }
  }

  void insert(TK key){
        if (root == nullptr)
        {
          root = new Node<TK>(M);
        }
         insert(key, root);
      }

  // funciona solo que no deberia haber ningun 0 para que pase el test (corregir insert)
  void remove(TK key)
  {
    // recorre todo el arbol
    for (int i = 0; i < root->count; i++)
    {
      if (root->keys[i] == key)
      {
        root->remove(i);
      }
    }

    //recorre el arbol y si hay un valor que es exactamente 0 lo elimina (por ahora, luego no es necesario)
    for (int i = 0; i < root->count; i++)
    {
      if (root->keys[i] == 0)
      {
        root->remove(i);
      }
    }
  }

  int height()
  {
    if (root == nullptr)
    {
      return 0;
    }
    else
    {
//        cout << M << endl;
//        return M -1 ;
      return root->height(); // calculamos el height a traves del root
    }
  }

  std::string toString(const std::string &sep)
  {
    if (root == nullptr)
    {
      return " ";
    }
    else
    {
      return root->toString(sep);
    }
  }

  TK minKey()
  {
    int min = root->keys[0];
    for (int i = 0; i < root->count; i++)
    {
      if (root->keys[i] < min && root->keys[i] != 0)
      {
        min = root->keys[i];
      }
    }
    return min;
  }

  TK maxKey()
  {
    int max = root->keys[0];
    for (int i = 0; i < root->count; i++)
    {
      if (root->keys[i] > max)
      {
        max = root->keys[i];
      }
    }
    return max;
  }

  void clear()
  {
    if (root != nullptr)
    {
      root->clear();
      delete root;
      root = nullptr;
    }
  }

  int size(){
        if (root == nullptr){
            return 0;
        }
      return root->count;

  }

  ~BTree()
  {
    clear();
  }
};

#endif
