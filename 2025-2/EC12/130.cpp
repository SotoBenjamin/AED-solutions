#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
class Solution {
public:
    int n,m;
    using i2 = pair<int,int>;
    vector<i2> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<char>> g;
    bool isIn(int x,int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void bfs(vector<vector<int>>& d){
        queue<i2> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++)
                if( ( i == 0 || i == n-1 || j == 0 || j == m-1 ) &&  g[i][j] == 'O') q.push({i,j}) , d[i][j] = 0;
        }
        while(!q.empty()){
            auto [ux,uy] = q.front();
            q.pop();
            for(auto [dx,dy] : dir){
                int vx = ux + dx;
                int vy = uy + dy;
                if(isIn(vx,vy) && g[vx][vy] == 'O' && d[vx][vy] == INF){
                    d[vx][vy] = 1 + d[ux][uy];
                    q.push({vx,vy});
                }
            }
        }
    }


    void solve(vector<vector<char>>& board) {
        n = (int) board.size();
        m = (int) board[0].size();
        g = board;
        vector<vector<int>> d(n,vector<int>(m,INF));
        bfs(d);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if( d[i][j] == INF) g[i][j] = 'X';
            }
        }
        board = g;
    }
};

int main(){
	return 0;
}
