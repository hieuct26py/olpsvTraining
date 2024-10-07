#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, a, b;
struct ok{
	int x, y, r;
};

ok c[MX];

bool check(int k) {
	for (int i=1; i<=n; i++) {
		if ((k + c[i].r) >= sqrt((c[i].x - a) * (c[i].x - a) + (c[i].y - b) * (c[i].y - b))) return false;
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	cin>>n>>a>>b;
	for (int i=1; i<=n; i++) {
		cin>>c[i].x>>c[i].y>>c[i].r;
	}
	int fn = -1, left = 0, right = 1e12;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			fn = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout<<fn;
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
