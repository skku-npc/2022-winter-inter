#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1007]; // 벡터로 간선 나타냄

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);
    int n; cin >> n;
    string start; cin >> start;
    
    vector<string> arr(n);
    
    for(auto & x : arr) cin >> x;
    
    int startnum = -1;
        
    for(int i=0;i<n;++i) if(arr[i]==start) startnum = i; // 시작 문자열이 몇번인지 찾기
    
    // graph make
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(arr[i].size() +1 == arr[j].size())    
    {
        bool can = true; // 문자열 i 에서 문자열 j로 전이가 가능한가?
        bool add= false; // 이미 한 글자를 추가했는가?
        int sn = 0;
        
        for(int t = 0 ;t<arr[j].size();++t)
        {
            if(arr[i][sn]!= arr[j][t])
            {
                if(add) can = false; // 해당 위치에서 문자가 다를 때 이미 한글자를 추가했다면 전이 불가능
                add = 1; 
            }
            else ++sn;
        }
        
        if(can) adj[i].push_back(j); // make edge
    }
    
    string ans = "";
    
    function<void(int)> dfs=[&](int u) 
    {
        if(ans.size() < arr[u].size()) ans = arr[u]; // 현재 방문한 노드 = 시작 정점부터 간선을 타서 도달한 노드 = 정답 후보 => 가장 긴 문자열을 정답으로
        for(auto &v  : adj[u]) dfs(v); // 간선으로 연결된 인접 정점으로 이동 (이 문제의 경우 항상 문자열 크기가 증가하므로 사이클이 발생하지 않는다!)
    };
    
    dfs(startnum); // 시작 정점 부터 dfs로 그래프 탐색
    
    cout << ans;
}
