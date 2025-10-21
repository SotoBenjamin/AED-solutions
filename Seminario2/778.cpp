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
    int id[55][55];
    
    int n;

    vector<pair<int,int>> dir = { {0,1} , {0,-1} , {1,0} , {-1,0} };

    bool isIn(int x , int y){
       return  x >= 0 && x < n && y >= 0 && y < n;
    } 

    bool check(int t, vector<vector<int>>& grid){
        DSU d(n*n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] > t) continue;
                for(auto& [x,y] : dir){
                    int dx = i + x;
                    int dy = j + y;
                    if(isIn(dx,dy) && grid[dx][dy] <= t){
                        d.unite(id[i][j] , id[dx][dy]);
                    }
                }
            }
        }
        return d.same(id[0][0],id[n-1][n-1]);
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int t = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                id[i][j] = t;
                t++;
            }
        }
        
        int l = 0 , r = n*n -1;
        int ans = -1;
        while(l <= r){
            int mid = (l+r)/2;
            if(check(mid,grid)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};

int main(){
	
	
	return 0;
}
