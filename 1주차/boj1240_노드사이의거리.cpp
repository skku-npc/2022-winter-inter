#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> adj[1007];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);
    int n,m; cin>>n>>m;
    
    for(int i = 0; i<n-1;++i)
    {
        int u,v,cost; cin >> u >> v >> cost;
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
    }
    
    while(m--)
    {
        int u,v; cin >> u>>v;
        
        function<int(int,int,int)> dfs=[&](int u,int p,int d)
        {
            if(u==v) return d;
            
            int ret= 0;
            
            for(auto & v : adj[u]) if(v.first!= p) ret= max(ret,dfs(v.first,u,d+v.second));
            
            return ret;
        };
        
        cout << dfs(u,-1,0) <<"\n";
    }
    
}
