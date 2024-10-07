#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 1e6 + 5;
const int MOD = 1e9 + 7;

int n;
string s1, s2;
int dp[MX][3];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test; cin>>test; while (test--) {
		cin>>s1>>s2;
		for (int i=1; i<=n; i++) {
			dp[i][1] = dp[i][2] = 0;
		}
		n = s1.size();
		s1 = ' ' + s1;
		s2 = ' ' + s2;
		if (s1[1] == 'X') dp[1][1] = 1;
		if (s2[1] == 'X') dp[1][2] = 1;
		for (int i=2; i<=n; i++) {
			if (s1[i] == 'X') dp[i][1] = (dp[i-1][1] + dp[i-1][2]) % MOD;
			if (s2[i] == 'X') dp[i][2] = (dp[i-1][1] + dp[i-1][2]) % MOD;
		}
		cout<<(dp[n][1] + dp[n][2]) % MOD << '\n';
	}		
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
