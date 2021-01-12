#include <bits/stdc++.h>
using namespace std;

//#define int 				long long
#define f 					first
#define s 					second
#define pb 					push_back
#define mp 					make_pair
#define vi 					vector<int>
#define pii					pair<int, int>
#define mii					map<int, int>
#define all(a) 				(a).begin(),(a).end()
#define sz(x) 				(x).size()
#define rep(i, a, b) 		for(int i = a; i < b; i++)
#define pqb					priority_queue<int>
#define pqs					priority_queue<int, vi, greater<int>>
#define setbits(x)			__builtin_popcountll(x)
#define zerobits(x)			__builtin_ctzll(x) // counts number of leading 0's before 1st occurnace of 1
#define mod 				1000000007
#define inf					1e18+7
#define ps(x, y)			fixed << setprecision(y) << x
#define string_to_int(x)	stoi(x)
#define int_to_string(x)	to_string(x)

void start() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main() {

	start();

	int n, x;
	cin >> n >> x;
	vi h(n), s(n);
	rep(i, 0, n) {
		cin >> h[i];
	}
	rep(i, 0, n) {
		cin >> s[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

	rep(i, 0, n + 1) {
		rep(j, 0, x + 1) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (h[i - 1] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], s[i - 1] + dp[i - 1][j - h[i - 1]]);
		}
	}

	cout << dp[n][x] << "\n";


	return 0;
}