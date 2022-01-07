#include <bits/stdc++.h>

using namespace std;

bool vist[100007];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &x : arr) cin >> x;
    int s; cin>> s; --s;
    
    int ans = 0;
    
    function<void(int)> dfs=[&](int u)
    {
        if(u < 0 || u >=n) return; // out of bound => 재귀 함수를 호출하지 않는다.
        if(vist[u]) return; // 이미 방문한 정점이여도 재귀 함수를 호출하지 않는다. 즉 다시 탐색하지 않는다.
        vist[u] =1, ++ans; // 방문한 정점에 색을 칠해서 다시 방문하지 않도록하고 정답의 개수를 올려줌.
        dfs(u-arr[u]); dfs(u+arr[u]); // 문제 조건에 맞춰 좌우 노드를 탐색한다.
    };
    
    dfs(s);    
    cout << ans;
}
