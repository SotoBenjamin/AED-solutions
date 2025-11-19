#include <bits/stdc++.h>
using namespace std;

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
    bool equationsPossible(vector<string>& equations) {
        DSU d(26);
        vector<pair<int,int>> a;
        for(auto& s : equations){
            int u = s[0]-'a';
            int v = s[3] - 'a';
            int c = s[1];
            if(c == '!'){
                a.push_back({u,v});
                continue;
            }
            d.unite(u,v);
        }
        for(auto [u,v] : a) if( d.same(u,v) ) return false;
        return true;
    }
};

int main(){
	return 0;
}
