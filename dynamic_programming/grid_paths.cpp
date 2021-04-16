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
const int M = 1000000007;
int dp[1005][1005];
vector<vector<char>> grid(1005, vector<char>(1005));
int n;

int calc(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (i >= n || j >= n) return 0;
	if (grid[i][j] == '*') return 0;
	if (i == n - 1 && j == n - 1) return 1;
	dp[i][j] = calc(i, j + 1) % M;
	dp[i][j] = (dp[i][j] + calc(i + 1, j)) % M;
	return dp[i][j] % M;
}

void solve() {
	cin >> n;
	rep(i, 0, n) {
		rep(j, 0, n) {
			cin >> grid[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	int ans = calc(0, 0);
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