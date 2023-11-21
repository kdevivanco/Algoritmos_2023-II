//￿Implemente￿un￿algoritmo￿en￿C++￿para￿traer￿todos￿las￿palabras￿palíndromos￿de￿la￿colección.

#include <iostream>
#include <vector>

using namespace std;

// Implementar un algoritmo en c++ para traer todas las palabras palindromas de un trie
const int E=26;
class SimpleTrie{
private:
    struct TrieNode
    {
        bool endWord;
        TrieNode* children[E];
    };
    TrieNode* root;
public:
    vector<string> getPalindromes(){
        vector<string> palindromes;
        getPalindromes(root, "", palindromes);
        return palindromes;
    }
    void getPalindromes(TrieNode* node, string word, vector<string>& palindromes){
        if(node->endWord){
            palindromes.push_back(word);
        }
        for(int i=0; i<E; i++){
            if(node->children[i]){
                getPalindromes(node->children[i], word+(char)(i+'a'), palindromes);
            }
        }
    }
};
