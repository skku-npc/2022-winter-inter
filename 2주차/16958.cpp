#include <bits/stdc++.h>

using namespace std;

const int max_v = 1e3+7;
const int INF = 0x3f3f3f3f;

#define seti pair<int,int>

int dist[max_v];
int tp[max_v],x[max_v],y[max_v];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);    
    int n,T; cin >> n>>T;
    
    for(int i = 0;i<n;++i) cin>> tp[i] >> x[i] >> y[i];
    
    struct cmp
    {
        bool operator()(seti &a,seti &b){return a.second > b.second;};
    };
    
    priority_queue<seti,vector<seti>,cmp> pq;
    
    memset(dist,0x3f,sizeof(dist));
    
    for(int i=0;i<n;++i) if(tp[i])
    {
        dist[i]=0;
        pq.push({i,0});
    }
    
    
    auto pp=[&](int a,int b)
    {
        return abs(x[a]-x[b]) + abs(y[a]-y[b]);
    };
    
    
    while(pq.size())
    {
        auto [u,d] = pq.top(); pq.pop();
        
        if(dist[u] !=d) continue;
        
        for(int i =0;i<n;++i) if(dist[i] > d+ pp(i,u))
        {
            dist[i] = d + pp(i,u);
            pq.push({i,dist[i]});
        }
    }
    
    int m; cin>> m;
    
    while(m--)
    {
        int u,v; cin >> u>> v; --u,--v;
        
        int ans = INF;        
        // using tel
        ans = min(ans,T+ dist[u] + dist[v]);
        // just walk        
        ans = min(ans,pp(u,v));
        
        cout << ans<<"\n";
    }    
}
