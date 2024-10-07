#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;

int l, r;

int ok(int x) {
	int ok = 0;
	int now = 1;
	for (int i=2; i<=x; i*=2) {
		// now++;
		ok += x / i;
		// ok += (now-1) * ((x - now) / (1LL<<now) + 1);
	}
	return ok;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>l>>r;
	cout<<ok(r) - ok(l-1);
	// cout<<ok(r);
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
