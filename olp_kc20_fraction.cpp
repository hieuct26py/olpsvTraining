#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

// #define int long long

const int MX = 1e6 + 5;
const int MOD = 1e9 + 7;

int n;
int a[MX], b[MX];
unordered_map<int, int> m1, m2;
int minPrime[MX];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i=2; i*i<=1000000; i++) {
		if (minPrime[i] == 0) {
			for (int j=i*i; j<=1000000; j+=i) {
				if (minPrime[j] == 0) minPrime[j] = i;
			}
		}
	}
	for (int i=2; i<=1000000; i++) {
		if (minPrime[i] == 0) minPrime[i] = i;
	}
	int test; cin>>test; while (test--) {
		m1.clear();
		m2.clear();
		cin>>n;
		for (int i=1; i<=n; i++) cin>>a[i];
		for (int i=1; i<=n; i++) cin>>b[i];
		for (int i=1; i<=n; i++) {
			while (a[i] > 1) {
				m1[minPrime[a[i]]]++;
				a[i] /= minPrime[a[i]];
			}
		}
		for (int i=1; i<=n; i++) {
			while (b[i] > 1) {
				m2[minPrime[b[i]]]++;
				b[i] /= minPrime[b[i]];
			}
		}
		// for (auto)
		for (auto it : m1) {
			if (!m2.count(it.fi)) continue;
			int ok = min(it.se, m2[it.fi]);
			m1[it.fi] -= ok;
			m2[it.fi] -= ok;
		}
		bool check = true;
		for (auto it : m2) {
			if (it.fi != 2 && it.fi != 5 && it.se != 0) {
				check = false;
			}
		}
		if (check) cout<<"finite";
		else cout<<"repeating";
		cout<<'\n';
	}	
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
