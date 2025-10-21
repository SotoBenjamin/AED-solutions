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


int main(){
	
	return 0;
}
