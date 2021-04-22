#include <bits/stdc++.h>
using namespace std;
//#define int long long int
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

int n, x;
int dp[1005][100005];

void solve() {
	cin >> n >> x;
	vi h(n), s(n);
	// h[i] -> Price, s[i] -> Pages
	rep(i, 0, n) cin >> h[i];
	rep(i, 0, n) cin >> s[i];
	rep(i, 1, n + 1) {
		int curr = i - 1;
		rep(j, 1, h[curr]) dp[i][j] = dp[i - 1][j];
		dp[i][h[curr]] = max(dp[i - 1][h[curr]], s[curr]);
		rep(j, h[curr] + 1, x + 1) dp[i][j] = max(dp[i - 1][j], s[curr] + dp[i - 1][j - h[curr]]);
	}

	cout << dp[n][x] << "\n";
}

int main() {
	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}