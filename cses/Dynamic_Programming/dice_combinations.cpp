#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll calculate_total_ways(vector<ll>& dp, ll n) {
	if (n == 0 || n == 1) dp[n] = 1;
	if (dp[n]) return dp[n];
	for (ll i = 1; i <= 6; i++) {
		if (i > n) continue;
		dp[n] = (dp[n] % MOD + calculate_total_ways(dp, n - i) % MOD) % MOD;
	}
	return dp[n] % MOD;
}

int main() {

	ll n;
	cin >> n;
	vector<ll> dp(n + 1, 0);
	ll total_ways = calculate_total_ways(dp, n);
	cout << total_ways << "\n";

	// Iterative Solution
	// dp[0] = dp[1] = 1;
	// for (ll i = 2; i <= n; i++) {
	// 	for (ll j = 1; j <= 6; j++) {
	// 		if (j > i) continue;
	// 		dp[i] = (dp[i] % MOD + dp[i - j] % MOD) % MOD;
	// 	}
	// }
	// cout << dp[n] % MOD << "\n";

	return 0;
}