#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, s;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>n>>s;
	cout<<(n *(n + 1) / 2) - s;
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
