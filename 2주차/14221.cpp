#include <bits/stdc++.h>

using namespace std;

const int max_v = 5e3+7;
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;

long long dist[max_v];
bool home[max_v];
vector<pair<int,int>> adj[max_v];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);    
    
    int n,m; cin>>n>>m;
    
    for(int i=0;i<m;++i)
    {
        int u,v,cost; cin >> u >> v >> cost;
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
    }
    
    int p,q; cin >> p>> q;
    
    for(int i = 0;i<p;++i)
    {
        int x; cin>> x; home[x]=1;
    }
    
    memset(dist,0x3f,sizeof(dist));
    
    struct cmp
    {
        bool operator()(pair<int,long long> & a,pair<int,long long> &b){return a.second > b.second;};
    };
    
    
    priority_queue<pair<int,long long>,vector<pair<int,long long>>,cmp> pq;
    
    for(int i = 0;i<q;++i)
    {
        int x; cin>> x; dist[x] = 0;
        pq.push({x,0});
    }
    
    pair<long long,int> ans={LNF,LNF};
    
    while(pq.size())
    {
        auto [u,d] = pq.top(); pq.pop();
        
        if(dist[u] != d) continue;
        
        if(home[u]) ans = min(ans,make_pair(d,u));
        
        for(auto & v : adj[u]) if(dist[v.first] > d+ v.second)
        {
            dist[v.first] = d+ v.second;
            pq.push({v.first,dist[v.first]});            
        }
    }
    
    assert(ans.first !=LNF);
    
    cout << ans.second;
}
