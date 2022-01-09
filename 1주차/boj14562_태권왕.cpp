#include <bits/stdc++.h>

using namespace std;

const int max_v = 1.2e2+7;
bool vist[max_v][max_v];
int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);
    int cnt; cin >> cnt;
    
    while(cnt--)
    {
        memset(vist,0,sizeof(vist));
        
        int a,b; cin >> a>>b;
        
        queue<pair<int,int>> bq; bq.push({ a,b });

        int lv = 0; vist[a][b] = 1;
        bool flag = true;

        while (flag)
        {
            int sz = bq.size();

            while (sz--)
            {
                auto [s, t] = bq.front(); bq.pop();

                if (s == t)
                {
                    cout << lv <<"\n";
                    flag = 0;
                    break;
                }

                // op 1
                if (s * 2 <= t + 3 && !vist[s * 2][t + 3]) // s > t 가 되면 어떤 연산으로도 s==t를 만들 수 없다
                {
                    vist[s * 2][t + 3] = 1;
                    bq.push({ s * 2,t + 3 });
                }

                // op 2

                if (!vist[s + 1][t])
                {
                    vist[s + 1][t] = 1;
                    bq.push({ s + 1,t });
                }
            }

            ++lv;
        }
    }
}
