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
    struct Edge{
        int u,v,w;
        bool operator < (const Edge& o){
            if( w != o.w) return w < o.w;
            if( u != o.u ) return u < o.u;
            return v < o.v;
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;
        for(int i = 0 ; i < n ; i++){
            int x = points[i][0] , y = points[i][1];
            for(int j = i+1 ; j < n ; j++){
                int dx = points[j][0] , dy = points[j][1];
                int w = abs(x-dx) + abs(y-dy);
                edges.push_back({i,j,w});
            }
        }
        DSU d(n);
        int ans = 0;
        sort(edges.begin(),edges.end());
        for(auto& [u,v,w] : edges){
            if(d.same(u,v)) continue;
            ans += w;
            d.unite(u,v);
        }
        return ans;
    }
};

int main(){
	return 0;	
}
