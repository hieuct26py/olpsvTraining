#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, f0, d;
pair<int, int> a[MX];
int f1[MX], f2[MX];

bool dis(pair<int, int> a, pair<int, int> b) {
	if (((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se)) < d * d) return true;  
	else return false;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>n>>f0>>d;
	for (int i=1; i<=n; i++) {
		cin>>a[i].fi>>a[i].se;
	}
	for (int i=1; i<=n; i++) {
		if (i != f0 && dis(a[i], a[f0])) f1[i] = true;
	}
	for (int i=1; i<=n; i++) {
		if (f1[i] == true) {
			for (int j=1; j<=n; j++) {
				if (j != f0 && !f1[j] && !f2[j] && dis(a[j], a[i])) f2[j] = true;
			}
		}
	}
	int c1 = 0, c2 = 0;
	for (int i=1; i<=n; i++) {
		c1 += f1[i];
		c2 += f2[i];
	}
	cout<<c1<<' '<<c2;
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
