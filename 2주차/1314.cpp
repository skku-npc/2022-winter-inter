#include <bits/stdc++.h>

using namespace std;

const int max_v = 1e1+7;
const int INF = 0x3f3f3f3f;

#define setp tuple<int,int,int>

struct cmp
{
    bool operator()(setp &a,setp &b){return get<2>(a) > get<2>(b);};
};


int w[max_v],s[max_v];
bool is[max_v][max_v];
int dist[1<<13][2];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);    
    
    int n; cin>> n;
    
    for(int i=0;i<n;++i) cin>> w[i] >> s[i];
    
    for(int i = 0;i<n;++i)
    {
        string tmp; cin >> tmp;
        for(int j =0;j<n;++j) is[i][j] = tmp[j] == 'Y';
    }
    
    int b; cin >> b;
    
    memset(dist,0x3f,sizeof(dist));
    dist[0][0] = 0;
    
    priority_queue<setp,vector<setp>,cmp> pq;
    
    pq.push({0,0,0});
    
    while(pq.size())
    {
        auto [u,dir,d] = pq.top(); pq.pop();
        
        if(dist[u][dir] != d) continue;
        
        vector<int> tar;
        
        for(int i =0;i<n;++i) 
        {
            if(dir)
            {
                if(u & (1<<i)) tar.push_back(i);       
            }
            else
            {
                if(!(u&(1<<i))) tar.push_back(i);
            }
        }
        
        int sz= tar.size();
        
        for(int i=1;i<(1<<sz);++i)        
        {
            int tb = 0;
            int speed = -INF;
            int nbit = u;
            
            vector<int> ntar;
            
            for(int j = 0;j<sz;++j) if((1<<j) & i)
            {
                tb += w[tar[j]];                
                speed= max(speed,s[tar[j]]);
                nbit ^= 1<<tar[j];
                ntar.push_back(tar[j]);
            }
            
            bool fam = true;
            
            if(ntar.size() >1)
            {
                for(int j = 0;j<ntar.size();++j)
                {
                    int nt= 0;
                    for(int t = 0;t<ntar.size();++t)
                    {
                        nt += is[ntar[j]][ntar[t]];
                    }
                    
                    fam &= nt >1;
                }
            }
            
            if(fam && tb <=b)
            {
                if(dist[nbit][dir^1] > d + speed)
                {
                    dist[nbit][dir^1] = d + speed;
                    pq.push({nbit,dir^1,d+speed});
                }
            }
            
        }
    }
    
    if(dist[(1<<n)-1][1]==INF) cout << -1;
    else cout<< dist[(1<<n)-1][1];
         
}
