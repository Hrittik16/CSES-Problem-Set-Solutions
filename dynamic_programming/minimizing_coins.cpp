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

int dp[1000007];

void solve() {
	int n, x;
	cin >> n >> x;
	vi coins(n);
	rep(i, 0, n) cin >> coins[i];
	sort(coins.begin(), coins.end());
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	rep(i, 1, x + 1) {
		rep(j, 0, n) {
			if (coins[j] > i) break;
			if (dp[i - coins[j]] == -1) continue;
			if (dp[i] == -1) dp[i] = 1 + dp[i - coins[j]];
			else dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
		}
	}
	cout << dp[x] << "\n";
}

int32_t main() {
	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}