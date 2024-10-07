#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 1e6 + 5;
const int MOD = 1e9 + 7;

int m, n, k;
int a[MX], b[MX];
int c[MX];
int st[MX*4];

void update(int id, int l, int r, int i, int val) {
	if (i < l || i > r) return;
	if (l == r) {
		st[id] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(id*2, l, mid, i, val);
	update(id*2+1, mid+1, r, i, val);
	st[id] = min(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int u, int v) {
	if (v < l || u > r) return 1e18;
	if (u <= l && r <= v) return st[id];
	int mid = (l + r) / 2;
	return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v)); 
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>m>>n>>k;
	for (int i=1; i<=m; i++) cin>>a[i];
	for (int i=1; i<=n; i++) cin>>b[i];
	sort(b+1, b+n+1);
	for (int i=1; i<=m; i++) {
		int ok = lower_bound(b+1, b+n+1, a[i]) - b;
		if (ok > n) ok--;
		c[i] = abs(a[i] - b[ok]);
		if (ok + 1 <= n) c[i] = min(c[i], abs(a[i] - b[ok+1]));
		if (ok - 1 >= 1) c[i] = min(c[i], abs(a[i] - b[ok-1]));
		update(1, 1, m, i, c[i]);
	}
	while (k--) {
		int l, r; cin>>l>>r;
		cout<<get(1, 1, m, l, r)<<'\n';
	}
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
