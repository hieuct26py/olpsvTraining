#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, k;
int a[MX], b[MX];
int st[4 * MX];

void update(int id, int l, int r, int i, int val) {
	if (i < l || i > r) return;
	if (l == r) {
		st[id] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(id*2, l, mid, i, val);
	update(id*2+1, mid+1, r, i, val);
	st[id] = __gcd(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int u, int v) {
	if (v < l || u > r) return 0;
	if (u <= l && r <= v) return st[id];
	int mid = (l + r) / 2;
	return __gcd(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>n>>k;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for (int i=1; i<=n; i++) {
		cin>>b[i];
		a[i] = abs(a[i] - b[i]);
		update(1, 1, n, i, a[i]);
	}
	// cout<<get(1, 1, n, 1, 1);
	while (k--) {
		int u, v; cin>>u>>v;
		cout<<get(1, 1, n, u, v)<<'\n';
	}
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
