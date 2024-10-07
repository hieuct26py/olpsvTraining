#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

#define int long long

const int MX = 1e5 + 5;
const int MOD = 998244353;
const int M = 998244353;

map<int, int> mp;
int n;

int nhan(int a,int b, int mod)
{
    if (b == 0) 
        return 0;
    int t = nhan(a, b / 2, mod);      
    t = (t + t) % mod; 
    if (b % 2 == 1) 
        t = (t + a) % mod;
    return t;
} 

int fibo(int n) {
	if (mp.count(n)) return mp[n];
	int k = n / 2;
	if (n % 2 == 0) {
		return mp[n] = (nhan(fibo(k), fibo(k), M) + nhan(fibo(k - 1), fibo(k - 1), M)) % M;
	}
	else {
		return mp[n] = (nhan(fibo(k), fibo(k + 1), M) + nhan(fibo(k - 1), fibo(k), M)) % M;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int test; cin>>test; while (test--) {}	
	mp[0] = 1;
	mp[1] = 1;
	cin>>n;
	cout<<nhan(fibo(n+1), fibo(n), M);
	return 0;
}
// binhtinhtutinkhongcaycunhungmotkhikhongcontutinnualatuyetvong
