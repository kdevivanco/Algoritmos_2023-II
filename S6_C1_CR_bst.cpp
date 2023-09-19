#include <iostream>
#include <algorithm>

using namespace std;


template <typename T>
class NodeAVL {
public:
    T data;
    NodeAVL<T>* left;
    NodeAVL<T>* right;
    int height;

    NodeAVL(T data) : data(data), left(nullptr), right(nullptr), height(1) {}

    int calculateBalancedFactor() {
        int left_height = (left != nullptr) ? left->height : 0;
        int right_height = (right != nullptr) ? right->height : 0;
        return left_height - right_height;
    }

    void updateHeight() {
        int left_height = (left != nullptr) ? left->height : 0;
        int right_height = (right != nullptr) ? right->height : 0;
        height = 1 + max(left_height, right_height);
    }

    bool isBalanced(){
        int left_height = (left != nullptr) ? left->height : 0;
        int right_height = (right != nullptr) ? right->height : 0;
        return abs(left_height - right_height) <= 1;
    }
};

template <typename T>
class AVLTree {
private:
    NodeAVL<T>* root;

public:
    AVLTree() : root(nullptr) {}

    void insert(T value) {
        root = insert(root, value);
    }

    void displayPreOrder() {
        displayPreOrder(root);
    }

    void displayInOrder() {
        displayInOrder(root);
    }

    int height() {
        if (root == nullptr) {
            return -1;
        }
        return root->height - 1;
    }


    bool isBalanced(){
        return isBalanced(root);
    }

    void drawTree(){
        drawTree(root, 0);
    }

private:
    bool isBalanced(NodeAVL<T>* node){
        if (node == nullptr) return true;
        if (!node->isBalanced()) return false;
        return isBalanced(node->left) && isBalanced(node->right);
    }


    void drawTree(NodeAVL<T> *node,int num){
        if (node == nullptr) return;
        drawTree(node->right, num+1);
        for (int i = 0; i < num; ++i) {
            cout << "      ";
        }
        cout << "|---" << node->data << "(" <<node->height-1<<")" << endl;
        drawTree(node->left, num+1);
    }

    NodeAVL<T>* rotateRight(NodeAVL<T>* y) {
        NodeAVL<T>* x = y->left;
        NodeAVL<T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->updateHeight();
        x->updateHeight();

        return x;
    }

    NodeAVL<T>* rotateLeft(NodeAVL<T>* x) {
        NodeAVL<T>* y = x->right;
        NodeAVL<T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->updateHeight();
        y->updateHeight();

        return y;
    }

    NodeAVL<T>* balance(NodeAVL<T>* node) {
        if (node == nullptr) return nullptr;

        node->updateHeight();

        int balance = node->calculateBalancedFactor();

        if (balance > 1) {
            if (node->left->calculateBalancedFactor() >= 0) {
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balance < -1) {
            if (node->right->calculateBalancedFactor() <= 0) {
                return rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    NodeAVL<T>* insert(NodeAVL<T>* node, T value) {
        if (node == nullptr) {
            return new NodeAVL<T>(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            return node;
        }

        return balance(node);
    }

    void displayPreOrder(NodeAVL<T>* node) {
        if (node == nullptr) return;

        cout << node->data << " ";
        displayPreOrder(node->left);
        displayPreOrder(node->right);
    }

    void displayInOrder(NodeAVL<T>* node) {
        if (node == nullptr) return;

        displayInOrder(node->left);
        cout << node->data << " ";
        displayInOrder(node->right);
    }
};

int main() {
    AVLTree<int> avl;

    avl.insert(35);
    avl.insert(30);
    avl.insert(27);
    avl.insert(11);
    avl.insert(16);
    avl.insert(100);
    avl.insert(50);
    avl.insert(91);
    avl.insert(73);
    avl.insert(5);

    avl.displayPreOrder();
    cout << endl;
    avl.displayInOrder();

    cout << endl;
    cout << "Height: ";
    cout << avl.height() << endl;

    cout << "Is balanced: ";
    if (avl.isBalanced()) cout << "Yes" << endl;
    else cout << "No" << endl;

    cout << "Tree: " << endl;
    avl.drawTree();

    return 0;
}