#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<bool>> vis;
    int n;
    int m;
    using i2 = pair<int,int>;
    vector<i2> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> g;
    bool isIn(int x,int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int c;
    void dfs(int sr,int sc){
        vis[sr][sc] = 1;
        for(auto [dx,dy] : dir){
            int vx = sr + dx;
            int vy = sc + dy;
            if(isIn(vx,vy) && g[vx][vy] == c && !vis[vx][vy]) dfs(vx,vy);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = (int) image.size();
        m = (int) image[0].size();
        vis.assign(n,vector<bool>(m,0));
        g = image;
        c = image[sr][sc];
        dfs(sr,sc);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j]) image[i][j] = color;
            }
        }
        return image;
    }
};


int main(){
	return 0;
}
