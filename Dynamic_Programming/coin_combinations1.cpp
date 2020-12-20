#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main() {
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	vector<ll> dp(x + 1, 0);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}

	dp[0] = 1;

	for (ll i = 1; i <= x; i++) {
		for (ll j = 0; j < n; j++) {
			if (a[j] > i) continue;
			dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
		}
	}

	cout << dp[x] % MOD << "\n";

	return 0;
}