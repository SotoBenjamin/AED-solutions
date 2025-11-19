#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
class Solution {
public:
    using pii = pair<int,int>;
    int n;
    
    vector<pii> dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{-1,-1},{1,-1}};
    bool isIn(int x,int y){
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    void bfs(int sx,int sy, vector<vector<int>>& d, vector<vector<int>>& g){
        queue<pii> q;
        d.assign(n,vector<int>(n,INF));
        if(g[sx][sy] != 0) return;
        q.push({sx,sy});
        d[sx][sy] = 1;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();            
            for(int k = 0 ; k <  (int) dir.size() ; k++){
                int vx = x + dir[k].first;
                int vy = y + dir[k].second;
                if(isIn(vx,vy) && g[vx][vy] == 0 && d[vx][vy] == INF){
                    d[vx][vy] = 1 + d[x][y];
                    q.push({vx,vy});
                }
            }
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = (int) grid.size();
        vector<vector<int>> d;
        bfs(0,0,d,grid);
        return d[n-1][n-1] == INF ?  -1 : d[n-1][n-1];
    }
};


int main(){
	return 0;
}
