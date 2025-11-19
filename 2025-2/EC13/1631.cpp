#include <bits/stdc++.h>
using namespace std;


#define INF 1e9

class Solution {
public:
    int n,m;
    using i3 = tuple<int,int,int>;
    using i2 = pair<int,int>;

    vector<i2> dir = {{0,-1},{0,1},{1,0},{-1,0}};

    bool isIn(int x,int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dijkstra(vector<vector<int>>& grid,vector<vector<int>>& d){
        d.assign(n,vector<int>(m,INF));
        priority_queue<i3,vector<i3>,greater<i3>> pq;
        d[0][0] = 0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [cur_d , x , y] = pq.top();
            pq.pop();
            if(cur_d != d[x][y]) continue;
            for(auto [dx,dy] : dir){
                int vx = x + dx;
                int vy = y + dy;
                if(!isIn(vx,vy)) continue;
                int w = abs(grid[x][y] - grid[vx][vy]);
                if(max(cur_d,w) < d[vx][vy]){
                    d[vx][vy] = max(cur_d,w);
                    pq.push({d[vx][vy],vx,vy});
                }
            }
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = (int) heights.size();
        m = (int) heights[0].size();
        vector<vector<int>> d;
        dijkstra(heights,d);
        return d[n-1][m-1];
    }
};

int main(){
	return 0;
}
