#include <bits/stdc++.h>

using namespace std;

const int max_v = 1e4+7;
const int INF = 0x3f3f3f3f;

int dist[max_v];
vector<pair<int,int>> adj[max_v];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);    
    int n,e; cin>>n>>e;
    
    for(int i =0; i <n ;++i)
    {
        int u,v,cost; cin >> u >> v>>cost;
        adj[u].push_back({v,cost});
    }
    
    struct cmp
    {
        bool operator()(pair<int,int> &a,pair<int,int>&b){return a.second > b.second;};
    };
    
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    memset(dist,0x3f,sizeof(dist));
    
    pq.push({0,0}); dist[0]=0;
    
    while(pq.size())
    {
        auto [u,d] = pq.top(); pq.pop();
        
        if(d != dist[u]) continue;
        
        if(u == e)
        {
            cout << d;
            return 0;
        }
        
        for(auto & v : adj[u]) if(dist[v.first] > d + v.second)
        {
            dist[v.first] = d+v.second;
            pq.push({v.first,dist[v.first]});
        }
        
        if(dist[u+1] > d + 1)
        {
            dist[u+1] = d+1;
            pq.push({u+1,dist[u+1]});
        }
    }
    
    
}
