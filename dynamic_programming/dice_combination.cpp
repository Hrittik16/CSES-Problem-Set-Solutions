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

const int M = 1e9 + 7;
int dp[1000007];

void solve() {
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		rep(dice, 1, 7) {
			if (dice > i) break;
			dp[i] = (dp[i] + dp[i - dice]) % M;
		}
	}
	cout << dp[n] % M << "\n";
}

int32_t main() {
	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}