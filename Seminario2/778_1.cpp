#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int n;

    vector<pair<int,int>> dir = { {0,1} , {0,-1} , {1,0} , {-1,0} };

    bool isIn(int x , int y){
       return  x >= 0 && x < n && y >= 0 && y < n;
    } 

    bool check(int t, vector<vector<int>>& grid){
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        queue<pair<int,int>> q;
        if(grid[0][0] <= t){
            q.push({0,0});
            vis[0][0] = 1;
        }
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(auto& [x,y] : dir){
                int dx = i + x;
                int dy = j + y;
                if(isIn(dx,dy) && grid[dx][dy] <= t && !vis[dx][dy]){
                    vis[dx][dy] = 1;
                    q.push({dx,dy});
                }
            }
        }
        return vis[n-1][n-1];
    }

    int swimInWater(vector<vector<int>>& grid) { 
        n = grid.size();
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
