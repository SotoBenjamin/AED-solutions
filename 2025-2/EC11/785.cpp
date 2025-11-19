#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    int n;
    vector<int> color;
    bool dfs(int u,int c){
        vis[u] = c;
        color[u] = c;
        bool ok = 1;
        for(auto& v : adj[u]){
            if(!vis[v]) ok &= dfs(v,1-c);
            else if(color[v] == c) ok = 0;
        }
        return ok;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        adj = graph;
        n = (int) graph.size();
        vis.assign(n,0);
        color.assign(n,-1);
        bool ok = 1;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]) {
                ok &= dfs(i,0);
            } 
        }
        return ok;
    }
};

int main(){
	
	return 0;
}
