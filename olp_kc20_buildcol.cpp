#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
int a[MX];
int l[MX], r[MX];
int b[MX];

bool check(int x) {
	for (int i=1; i<=n; i++) {
		if (a[i] > x) b[i] = a[i];
		else b[i] = x;
	}
	int res = 0;
	// cout<<l[1]<<' '<<r[3]<<'\n';
	for (int i=2; i<=n-1; i++) {
		res += max(0LL, min(l[i-1], r[i+1]) - b[i]);
		// cerr<<i<<' '<<min(l[i-1], r[i+1]) - a[i]<<'\n';
	}
	return (res >= m);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	l[0] = -1e18;
	for (int i=1; i<=n; i++) {
		l[i] = max(l[i-1], a[i]);
	}
	r[n+1] = -1e18;
	for (int i=n; i>=1; i--) {
		r[i] = max(r[i+1], a[i]);
	}
	int left = 1, right = 1e12;
	int fn = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			fn = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout<<fn;
	// cout<<check(3);
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
