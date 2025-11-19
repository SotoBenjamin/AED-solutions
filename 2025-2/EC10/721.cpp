#include <bits/stdc++.h>
using namespace std;


int n;
struct DSU {
    int N = 0;
    int* parent = nullptr;
    int* sz = nullptr;
    
    DSU(int _N){    
        N = _N;
        parent = new int[N];
        sz = new int[N];
        for(int i = 0 ; i < N ; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int a,int b){
        return find(a) == find(b);
    }

    void unite(int a, int b){
        if(same(a,b)) return;
        a = find(a);
        b = find(b);
        if( sz[a] < sz[b] ) swap(a,b);
        sz[a] += b;
        parent[b] = a;
    }
    ~DSU(){
        delete [] parent;
        delete [] sz;
        N = 0;
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        n = accounts.size();
        unordered_map<string,int> account;
        DSU d(n);
        for(int i = 0 ; i < (int) accounts.size() ; i++){
            for(int j = 1 ; j < (int) accounts[i].size() ; j++){
                string s = accounts[i][j];
                if(account.count(s) > 0) d.unite(i,account[s]);
                else account[s] = i;
            }
        }
        map<int,set<string>> mp;
        for(int i = 0 ; i < n ; i++){
            int p = d.find(i);
            for(int j = 1 ; j < (int) accounts[i].size() ; j++) mp[p].insert(accounts[i][j]);
        }
        vector<vector<string>> ans;
        for(auto& [p,el] : mp){
            vector<string> t;
            t.push_back(accounts[p][0]);
            for(auto& s : el) t.push_back(s);
            ans.push_back(t);
        }
        return ans;
    }
};

int main(){
	return 0;
}
