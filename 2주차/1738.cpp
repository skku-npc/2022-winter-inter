#include <bits/stdc++.h>

using namespace std;

const int max_v = 1e2+7;
const long long INF = 0x3f3f3f3f3f3f3f3f;

#define setp tuple<int,int,long long>

long long dist[max_v];
int p[max_v];
bool vist[max_v];
vector<int> adj[max_v];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);    
    
    int n,m; cin>> n>>m;
    
    vector<setp> ve(m);
    
    for(auto &[u,v,cost] : ve) cin>> u>>v>>cost,--u,--v,cost = -cost,adj[u].push_back(v);
    
    memset(p,-1,sizeof(p));
    memset(dist,0x3f,sizeof(dist));
    
    bool flag= false;
    
    dist[0]=0;
    
    for(int i =0;i<n-1;++i)
    {
        for(auto &[u,v,cost] : ve)
        {
            if(dist[u]!=INF && (dist[v] > dist[u] + cost))
            {
                dist[v] = dist[u] + cost;
                p[v] = u;
            }
        }
    }
    
    queue<int> bq;
    
    for(auto &[u,v,cost] : ve)
    {
        if(dist[u]!=INF && (dist[v] > dist[u] + cost))
        {
            bq.push(u); vist[u]=1;
        }
    }
    
    while(bq.size())
    {
        auto u = bq.front(); bq.pop();
        
        for(auto & x : adj[u]) if(!vist[x])
        {
            vist[x]=1; bq.push(x);
        }
    }
        
    flag |= dist[n-1] == INF;
    flag |= vist[n-1];
    
    if(flag) cout << -1;
    else
    {
        vector<int> ans;
        
        int cu = n-1;
        
        while(~cu)
        {            
            ans.push_back(cu);                    
            cu = p[cu];                                         
        }    
        
        reverse(ans.begin(),ans.end());
        
        for(auto & x : ans) cout << x+1 <<" ";
    }
         
}
