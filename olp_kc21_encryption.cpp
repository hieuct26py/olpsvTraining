#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;

int l, r, a, k;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>l>>r>>a>>k;
	if (a % k == 0) cout<<r - l + 1;
	else if (__gcd(a, k) == 1) cout<<r / k - (l - 1) / k;
	else cout<<r / (k / __gcd(a, k)) - (l - 1) / (k / __gcd(a, k));
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
