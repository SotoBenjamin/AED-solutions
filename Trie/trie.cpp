#include <bits/stdc++.h>

using namespace std;

struct TrieNode{
    TrieNode* children[26];
    bool end = false;
    TrieNode(){
        for(int i = 0 ; i < 26 ; i++){
            children[i] = nullptr;  
        }
    }
};
class Trie {
    TrieNode* root = nullptr;
public:

    Trie(){
        root = new TrieNode();
    }
    void insert(string word) {
        auto curr = root;
        for(char c : word){
            int id = c-'a';
            if(curr->children[id] == nullptr){
                curr->children[id] = new TrieNode();
            }
            curr = curr->children[id];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        auto curr = root;
        for(char c : word){
            int id = c - 'a';
            if(curr->children[id] == nullptr){
                return false;
            }
            curr = curr->children[id];
        }
        return curr->end;
    }
    bool startsWith(string prefix) {
        auto curr = root;
        for(char c : prefix){
            int id = c - 'a';
            if(curr->children[id] == nullptr){
                return false;
            }
            curr = curr->children[id];
        }
        return true;
    }
};

int main(){
	
	return 0;
}
