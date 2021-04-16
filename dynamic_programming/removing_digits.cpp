#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define f first
#define s second
#define mp make_pair
const int VEC_1D = 2e8;
const int VEC_2D = 1e4;

int dp[1000007];

int calc(int n) {
	if (n == 0) return 0;
	if (n < 0) return INT_MAX;
	if (dp[n] != -1) return dp[n];
	vi digits;
	int temp = n;
	while (temp > 0) {
		digits.pb(temp % 10);
		temp /= 10;
	}
	sort(digits.rbegin(), digits.rend());
	rep(i, 0, digits.size()) {
		if (digits[i] == 0) continue;
		if (dp[n] == -1)
			dp[n] = 1 + calc(n - digits[i]);
		else
			dp[n] = min(dp[n], 1 + calc(n - digits[i]));
	}
	return dp[n];
}

void solve() {
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	int ans = calc(n);
	cout << ans << "\n";
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}