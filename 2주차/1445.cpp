#include <bits/stdc++.h>

using namespace std;

const int max_v = 5e1+7;
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;

#define seti pair<int,int>

seti vu[4] = {{0,1},{1,0},{0,-1},{-1,0}};

bool trash[max_v][max_v];
bool atrash[max_v][max_v];
seti dist[max_v][max_v];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);    
    
    int h,w; cin >> h>> w;
    
    seti sp,ep;
    
    for(int i = 0;i<h;++i)
    {
        string tmp; cin >> tmp;
        
        for(int j =0;j<w;++j)
        {
            if(tmp[j]=='F') ep ={i,j};
            else if(tmp[j]=='S') sp={i,j};
            else if(tmp[j]=='g') trash[i][j]=1;                        
        }
    }
    
    for(int i =0;i<h;++i) for(int j=0;j<w;++j) if(!trash[i][j] && !(ep.first == i && ep.second==j))
    {
        int cnt = 0;
        for(int t=0;t<4;++t)
        {
            int nx = i+ vu[t].first;
            int ny = j + vu[t].second;
            
            if(nx <0 || ny<0 || nx>=h || ny>=w) continue;
            
            cnt += trash[nx][ny];
        }
        
        atrash[i][j] = !!cnt;
    }
    
    struct node
    {
        int x,y;
        seti d;
    };
    
    struct cmp
    {
        bool operator()(node & a,node &b){return a.d > b.d;};
    };
    
    priority_queue<node,vector<node>,cmp> pq;
    
    memset(dist,0x3f,sizeof(dist));
    
    pq.push({sp.first,sp.second,{0,0}});
    dist[sp.first][sp.second]={0,0};
    
    while(pq.size())   
    {
        auto [x,y,d] = pq.top(); pq.pop();
        
        if(d!= dist[x][y]) continue;
        
        if(x== ep.first && y==ep.second)
        {
            cout << d.first <<" "<< d.second;
            return 0;
        }
        
        for(int t=0;t<4;++t)
        {
            int nx = x + vu[t].first;
            int ny = y + vu[t].second;
            
            if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
            
            seti nd = {d.first + trash[nx][ny] , d.second + atrash[nx][ny]};
            
            if(dist[nx][ny] > nd)
            {
                dist[nx][ny] = nd;
                pq.push({nx,ny,nd});
            }
        }
    }
    
}
