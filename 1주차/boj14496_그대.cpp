#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1007];
bool vist[1007];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);
    int a,b; cin>> a>> b;
    int n,m; cin >> n >> m;
    
    for(int i = 0; i< m ;++i)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue <int> bq; bq.push(a); vist[a]  =1;
    
    int lv= 0;
    while(bq.size())
    {
        int sz= bq.size();
        
        while(sz--)
        {
            int u = bq.front(); bq.pop();
            
            if(u==b)
            {
                cout << lv; 
                return 0;
            }
            
            for(auto &v  : adj[u]) if(!vist[v])
            {
                vist[v]  =1;
                bq.push(v);
            }
        }
        
        ++lv;
    }
    
    cout << -1;
}
