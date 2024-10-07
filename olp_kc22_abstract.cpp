#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;

int m, n;
int a[1005][1005];
bool t[1005][1005];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>m>>n;
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	for (int i=1; i<=m; i++) {
		int maxx = a[i][1];
		if (a[i][1] != 0) t[i][1] = true;
		for (int j=2; j<=n; j++) {
			if (a[i][j] > maxx) t[i][j] = true;
			maxx = max(maxx, a[i][j]);
		}
	}
	for (int i=1; i<=m; i++) {
		int maxx = t[i][n];
		if (a[i][n] != 0) t[i][n] = true;
		for (int j=n; j>=1; j--) {
			if (a[i][j] > maxx) t[i][j] = true;
			maxx = max(maxx, a[i][j]);
		}
	}
	for (int j=1; j<=n; j++) {
		int maxx = a[1][j];
		if (a[1][j] != 0) t[1][j] = true;
		for (int i=2; i<=m; i++) {
			if (a[i][j] > maxx) t[i][j] = true;
			maxx = max(maxx, a[i][j]);
		}
	}
	for (int j=1; j<=n; j++) {
		int maxx = a[m][j];
		if (a[m][j] != 0)t[m][j] = true;
		for (int i=m-1; i>=1; i--) {
			if (a[i][j] > maxx) t[i][j] = true;
			maxx = max(maxx, a[i][j]);
		}
	}
	int fn = 0;
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			// cout<<t[i][j]<<' ';
			fn += t[i][j];
		}
		// cout<<'\n';
	}
	cout<<fn;
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
