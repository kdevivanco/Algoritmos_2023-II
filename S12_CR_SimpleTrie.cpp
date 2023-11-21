//
// Created by MacBookPro on 2/11/23.
//


#include <iostream>
//#include "trie.h"

using namespace std;

const unsigned ALPHA_SIZE = 26; // tamanio del alfabeto de letras minusculas

class TrieSimple
{
private:
    struct TrieNode
    {
        TrieNode **children;
        bool endWord; // indica si es final de una palabra
        int count;

        TrieNode()
        {
            children = new TrieNode*[ALPHA_SIZE];
            for (int i = 0; i < ALPHA_SIZE; ++i)
                children[i] = nullptr;
            endWord = false;
            count = 0;

        }

        ~TrieNode()
        {
            for (int i = 0; i < ALPHA_SIZE; ++i)
                if (children[i] != nullptr)
                    delete children[i];
            delete [] children;
        }
    };

    TrieNode *root;

public:
    TrieSimple() {
        root = nullptr;
    }

    void insert(string key){
        if(root == nullptr)
            root = new TrieNode();
        TrieNode* temp = root;
        for(int i=0;i<key.size();i++)
        {
            int index = key[i] - 'a';
            if(temp->children[index] == nullptr)
                temp->children[index] = new TrieNode();
            temp = temp->children[index];
        }
        temp->endWord = true;
    }

    bool search(string key){
        if(root == nullptr)
            return false;
        TrieNode* temp = root;
        for(int i=0;i<key.size();i++){
            int index = key[i] - 'a';
            if(temp->children[index] == nullptr)
                return false;
            temp = temp->children[index];
        }
        return temp->endWord;
    }

    bool isEmpty(TrieNode* root)
    {
        for (int i = 0; i < ALPHA_SIZE; i++)
            if (root->children[i])
                return false;
        return true;
    }

    void remove(string key)
    {
        root = remove(root, key);
    }


    string toString(string sep)
    {


        return toString(root, sep, "");
    }



private:
    TrieNode* remove(TrieNode* root, string key, int depth = 0){
        if (!root){
            return NULL;
        }

        if (depth == key.size()) {
            if (root->endWord)
                root->endWord = false;

            if (isEmpty(root)) {
                delete (root);
                root = NULL;
            }
            return root;
        }

        int index = key[depth] - 'a';
        root->children[index] = remove(root->children[index], key, depth + 1);

        if (isEmpty(root) && root->endWord == false) {
            delete (root);
            root = NULL;
        }

        return root;
    }


    string toString(TrieNode *node, string sep, string prefix)
    {
        string result = "";
        if (node == nullptr)
            return result;
        if (node->endWord)
            result += prefix + sep;
        for (int i = 0; i < ALPHA_SIZE; ++i)
            if (node->children[i] != nullptr)
                result += toString(node->children[i], sep, prefix + (char)('a' + i));
        return result;
    }
};


void testTrie(TrieSimple* trie, vector<string> diccionario){
    for(string word : diccionario)
        trie->insert(word);
    cout<<trie->toString(" ")<<endl;
    cout<<trie->search("amor")<<endl;
    cout<<trie->search("rosa")<<endl;
    trie->remove("nada");
    trie->remove("roma");
    trie->remove("amorfo");
    cout<<trie->toString(",")<<endl;
}

int main(){
    vector<string> diccionario = {"romano", "roma", "romario", "rosario", "rata", "amor", "amorfo", "amorcito", "amiga"};

    testTrie(new TrieSimple(), diccionario);

    return 0;
}