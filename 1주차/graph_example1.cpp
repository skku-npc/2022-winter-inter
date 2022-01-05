#include <bits/stdc++.h>

using namespace std;

#define endl '\n' // fast IO

const int sz = 1e2 + 7;
vector<pair<int,int>> adj1[sz]; // 간선을 인접리스트로 나타냄
int adj2[sz][sz]; // 간선을 배열로 나타냄

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); // fast IO
	
	int n,m; cin >> n >> m; // 정점 N, 간선 M
	
	int INF = 0x3f3f3f3f;
	memset(adj2, 0x3f, sizeof(adj2)); 

	for (int i = 0; i < m; ++i)
	{
		int u, v, cost; cin >> u >> v >> cost;
		
		adj1[u].push_back({ v,cost }); // u -> v 비용 cost
		adj2[u][v] = cost;
	}

	// 정점 u에 인접한 정점 중 최단 거리를 가진 정점 t 찾기	
	auto UseVec = [&](int u)
	{
		pair<int, int> ret = { 1e9 + 7 ,-1 };
		for (auto& v : adj1[u]) ret = min(ret, {v.second, v.first});
		return ret.second;
	};

	auto UseArray = [&](int u)
	{
		pair<int, int> ret = { 1e9 + 7 ,-1 };
		for (int i = 1; i <= n; ++i) if (adj2[u][i] != INF) ret = min(ret, { adj2[u][i],i });
		return ret.second;
	};

	cout << UseVec(5) << UseArray(3)<<endl;
}
