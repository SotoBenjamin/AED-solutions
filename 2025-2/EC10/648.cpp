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
    pair<bool , string> haveprefix(string word){
        auto curr = root;
        string ans = "";
        for(char c : word){
            int id = c - 'a';
            if(curr->end){
                return {curr->end, ans};
            }
            if(curr->children[id] == nullptr){
                return {curr->end , ans};
            }
            ans += c;
            curr = curr->children[id];
        }
        return {curr->end , ans};
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        for(string& s : dictionary){
            t.insert(s);
        }
        vector<string> words;
        string curr = "";
        for(int i = 0 ; i < (int) sentence.size() ; i++){
            if(sentence[i] == ' '){
                words.push_back(curr);
                curr = "";
            }
            else{
                curr += sentence[i];
            }
        }
        words.push_back(curr);
        string ans = "";
        for(string s : words){
            auto [have_prefix , pre] = t.haveprefix(s);
            if(have_prefix) ans += pre;
            else ans += s;
            ans += ' ';
        }
        return ans.substr(0,ans.size()-1);
    }
};


int main(){
	return 0;
}
