#include <bits/stdc++.h>

using namespace std;

const int max_v = 1e2+7;
string arr[max_v];
bool vist[max_v][max_v];

pair<int,int> vu[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);
    int cnt; cin >> cnt;
    
    while(cnt--)
    {
        memset(vist,0,sizeof(vist));
        
        int h,w; cin>> h>>w;        
        for(int i =0;i<h;++i) cin >> arr[i];
        
        int ans = 0;
        function<void(int,int)> dfs=[&](int x,int y)
        {                    
            vist[x][y] =1;
            
            for(int dir = 0; dir<4;++dir)
            {
                int nx = x+vu[dir].first;
                int ny= y + vu[dir].second;
                
                if(nx < 0 || ny < 0 || nx >=h || ny >=w || vist[nx][ny] || arr[nx][ny]!='#') continue;
                
                dfs(nx,ny);
            }
            
        };
        
        for(int i=0;i<h;++i) for(int j = 0;j<w;++j) if(!vist[i][j] && arr[i][j]=='#') ++ans,dfs(i,j);
                
        cout << ans <<"\n";
    }
}
