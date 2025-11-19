#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
class Solution {
public:
    int n,m;
    using i2 = pair<int,int>;
    vector<i2> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> g;
    bool isIn(int x,int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void bfs(vector<vector<int>>& d){
        queue<i2> q;
        d.assign(n,vector<int>(m,INF));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++)
                if(g[i][j] == 2) q.push({i,j}) , d[i][j] = 0;
        }
        while(!q.empty()){
            auto [ux,uy] = q.front();
            q.pop();
            for(auto [dx,dy] : dir){
                int vx = ux + dx;
                int vy = uy + dy;
                if(isIn(vx,vy) && g[vx][vy] == 1 && d[vx][vy] == INF){
                    d[vx][vy] = 1 + d[ux][uy];
                    q.push({vx,vy});
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        g = grid;
        n = (int) grid.size();
        m = (int) grid[0].size();
        vector<vector<int>> d;
        bfs(d);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(g[i][j] == 1) ans = max(ans,d[i][j]);
            }
        }
        return ans == INF ?  -1 : ans;
    }
};

int main(){
	return 0;
}
