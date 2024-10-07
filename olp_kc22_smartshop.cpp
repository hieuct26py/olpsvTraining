#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 5e5 + 5;
const int MOD = 1e9 + 7;

int n, q;
int a[MX];
vector<int> v;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>n>>q;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for (int i=1; i<=n; i++) {
		int x = a[i];
		if (x < 1) continue;
		if (x == 1) v.push_back(1);
		if (x % 5 == 0) {
			while (x % 5 == 0) x /= 5;
			if (x == 1) v.push_back(a[i]);
		}
		else if (x % 2 == 0) {
			while (x % 2 == 0) x /= 2;
			if (x == 1) v.push_back(a[i]);	
		}
		else if (x % 3 == 0) {
			while (x % 3 == 0) x /= 3;
			if (x == 1) v.push_back(a[i]);	
		}
	}
	sort(v.begin(), v.end());
	while (q--) {
		int l, r; cin>>l>>r;
		int left = lower_bound(v.begin(), v.end(), l) - v.begin();
		int right = upper_bound(v.begin(), v.end(), r) - v.begin() - 1;
		cout<<right - left + 1<<'\n'; 
	}
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
