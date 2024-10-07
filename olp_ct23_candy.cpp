#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, q;
int a[MX];
int st[4*MX][10];

void update(int id, int k, int l, int r, int i, int val) {
	if (i < l || i > r) return;
	if (l == r) {
		st[id][k] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(id*2, k, l, mid, i, val);
	update(id*2+1, k, mid+1, r, i, val);
	st[id][k] = st[id*2][k] + st[id*2+1][k];
}

int get(int id, int k, int l, int r, int u, int v) {
	if (v < l || u > r) return 0;
	if (u <= l && r <= v) return st[id][k];
	int mid = (l + r) / 2;
	return get(id*2, k, l, mid, u, v) + get(id*2+1, k, mid+1, r, u, v);
}

bool chk(int i, int j) {
	string s = to_string(i);
	if (s.find(j + '0') != -1) return true;
	else return false;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>n>>q;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=9; j++) {
			if (i % j == 0 || chk(i, j)) {
				update(1, j, 1, n, i, a[i] * 2);
			}
			else {
				update(1, j, 1, n, i, a[i]);
			}
		}
	}
	// cout<<get(1, 2, 1, n, 1, 5)<<'\n';
	while (q--) {
		int tv; cin>>tv;
		if (tv == 1) {
			int i, c; cin>>i>>c;
			for (int j=1; j<=9; j++) {
				if (i % j == 0 || chk(i, j)) {
					update(1, j, 1, n, i, c * 2);
				}
				else {
					update(1, j, 1, n, i, c);
				}
			}
		}
		else {
			int l, r, k; cin>>l>>r>>k;
			cout<<get(1, k, 1, n, l, r)<<'\n';
		}
	}
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
