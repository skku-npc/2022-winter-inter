#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vu={{0,1},{0,-1},{1,0},{-1,0}};

const int max_v = 1e2+7;
const int INF = 0x3f3f3f3f;
int a[max_v][max_v];
int dist[max_v][max_v][max_v];
bool vist[max_v][max_v][max_v];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);
    int n; cin>> n;
    
    for(int i=0;i<n;++i) for(int j=0;j<n;++j)
    {
        cin>>a[i][j];
        if(!a[i][j]) a[i][j]=INF;
    }   
    
    memset(dist,0x3f,sizeof(dist));
    
    queue<tuple<int,int,int>> bq;
    
    bq.push({0,0,1}); vist[0][0][1] = 1;
    bq.push({0,0,21}); vist[0][0][21] = 1;
    bq.push({0,0,41}); vist[0][0][41] = 1;
    bq.push({0,0,61}); vist[0][0][61] = 1;
    
    int lv= 0;
    
    while(bq.size())
    {
        int sz = bq.size();
        
        while(sz--)
        {
            auto [x,y,d] = bq.front(); bq.pop();
            
            if(x==n-1 && y==n-1)
            {
                cout << lv;
                return 0;
            }
            
            int dir = (d-1)/20;
            int speed = d%20;
            
            assert(speed<16);
            
            for(int t=0;t<4;++t)
            {
                int nd = t*20 + (t == dir ? speed +1 : 2);
                int nx = vu[t].first*(t==dir ? speed : 1) + x;
                int ny = vu[t].second*(t==dir? speed : 1) + y;
                                
                if(nx <0 || ny< 0 || nx>=n || ny>=n || vist[nx][ny][nd]) continue;
                
                auto f=[&](int cx,int cy)
                {
                    bool flag= true;
                    
                    while(cx != nx || cy !=ny)
                    {
                        flag &= a[cx][cy] > lv;
                        cx += vu[t].first;
                        cy += vu[t].second;    
                    }
                    
                    return flag;
                };
                
                if(f(x,y)) bq.push({nx,ny,nd}),vist[nx][ny][nd]=1;
            }
        }
        ++lv;
    }
    
    cout << "Fired\n";
    
}
