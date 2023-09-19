//
// Created by MacBookPro on 14/09/23.
//

template<typename T>
class BSTIterator {
public:
    enum Type{
        PreOrder, InOrder, PostOrder, BST
    };
private:
    Node<T>* current;
    Type type;
    stack<Node<T>*> mystack;
};