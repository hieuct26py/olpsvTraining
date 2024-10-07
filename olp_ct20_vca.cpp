#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;

int k, n;
string s;
int ta[MX], tv[MX], tc[MX];

bool check(int x) {
	int sl = 3 * k + x;
	for (int i=1; i<=n-sl+1; i++) {
		int l = i, r = i + sl - 1;
		int slc = tc[r] - tc[l-1];
		int sla = ta[r] - ta[l-1];
		int slv = tv[r] - tv[l-1];
		if (sla < k || slv < k || slc < k) continue;
		else return true;
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>k>>s;
	n = s.size();
	s = ' ' + s;
	for (int i=1; i<=n; i++) {
		ta[i] = ta[i-1] + (s[i] == 'A');
		tv[i] = tv[i-1] + (s[i] == 'V');
		tc[i] = tc[i-1] + (s[i] == 'C');
	}
	int fn = -1;
	int left = 0, right = n - (3 * k);
	while (left <= right) {
		int mid = (left + right) / 2;
		cerr<<mid<<' '<<check(mid)<<'\n';
		if (check(mid)) {
			fn = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout<<fn;
	// cout<<check(0);
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
