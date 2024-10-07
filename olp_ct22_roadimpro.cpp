#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m, q;
vector<pair<int, int>> adj[MX];
int L[MX][2];

void dijkstra(int i1) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	for (int i=1; i<=n; i++) {
		L[i][0] = L[i][1] = 1e18;
	}
	L[1][0] = 0;
	q.push({0, {1, 0}});
	while (!q.empty()) {
		int u = q.top().se.fi;
		int du = q.top().fi;
		int now = q.top().se.se;
		q.pop();
		if (du != L[u][now]) continue;
		for (auto it : adj[u]) {
			int v = it.se;
			int uv = it.fi;
			// if (v == 4) cout<<u<<' '<<du<<'\n';
			if (du + uv < L[v][now]) {
				L[v][now] = du + uv;
				q.push({L[v][now], {v, now}});
			}
			if (now == 0) {
				if (du < L[v][1]) {
					L[v][1] = du;
					q.push({L[v][1], {v, 1}});
				}
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>n>>m>>q;
	for (int i=1; i<=m; i++) {
		int u, v, c; cin>>u>>v>>c;
		adj[u].push_back({c, v});
	}	
	dijkstra(1);
	while (q--) {
		int s, t; cin>>s>>t;
		cout<<min(L[s][0], L[s][1] + t)<<'\n';
	}
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
