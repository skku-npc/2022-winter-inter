#include <bits/stdc++.h>

using namespace std;

const int max_v = 5e1+7;
const int INF = 0x3f3f3f3f;

int dist[max_v][max_v];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);    
    
    memset(dist,0x3f,sizeof(dist));
    int n; cin>>n;
    
    int u,v; 
    
    while((cin >> u >> v) && ~u)
    {
        --u,--v;
        dist[u][v] = dist[v][u]=1;
    }
    
    for(int k=0;k<n;++k) for(int i=0;i<n;++i) for(int j=0;j<n;++j) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
    
    int cv = INF;
    vector<int> ans;
    
    for(int i =0;i<n;++i)
    {
        int pv= -1;
        for(int j = 0;j<n;++j) if(i!=j && dist[i][j]!=INF)
        {
            pv= max(pv,dist[i][j]);
        }
        
        if(pv==-1) continue;
        
        if(cv > pv) 
        {
            cv= pv;
            ans.clear(); ans.push_back(i+1);
        }
        else if(cv == pv) ans.push_back(i+1);
    }
    
    cout << cv <<" "<< ans.size()<<"\n";
    for(auto & x : ans) cout << x<<" ";
}
