#include <bits/stdc++.h>

using namespace std;

#define INF 1e18
#define dbg(x) cout<<#x<<" = "<<x<<endl;

class Solution {
public:
    vector<double> d;
    vector<int> p;

    bool relax(int u,int v,double w){
        if(d[u] == INF) return false;
        if(d[u] + w < d[v]){
            d[v] = d[u] + w;
            p[v] = u;
            return true;
        }
        return false;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start_node, int end_node) {
        d.assign(n,INF);
        p.assign(n,-1);
        d[start_node] = 0;
        p[start_node] = start_node;
        map<pair<int,int>,double> mp;
        for(int j = 0 ; j < (int) edges.size() ; j++){
            int u = edges[j][0] , v = edges[j][1];
            mp[{u,v}] = succ[j];
            mp[{v,u}] = succ[j];
        }
        for(int i = 0 ; i < n - 1; i++){
            bool any = false;
            for(int j = 0 ; j < (int) edges.size() ; j++){
                int u = edges[j][0] , v = edges[j][1];
                double w = -1*log(succ[j]);
                if(relax(u,v,w)) any = true;
                if(relax(v,u,w)) any = true;
            }
            if(!any) break;
        }
        if(d[end_node] == INF) return 0.0;
        int cur = end_node;
        double ans = 1.0;
        while(p[cur] != cur){
            ans *= mp[{p[cur],cur}];
            cur = p[cur];
        }
        return ans;
    }
};

int main(){
	return 0;
}
