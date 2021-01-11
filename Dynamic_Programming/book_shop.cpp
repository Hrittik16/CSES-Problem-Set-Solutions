#include <bits/stdc++.h>
using namespace std;

#define int 				long long
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
#define test				int T; cin >> T; while(T--)

void start() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e5 + 7;

int dp[1007][N];
vi h(N), s(N);

// This is the recursive solution but it gives time limit exceeded

int calculate(int n, int p, int x) {
	if (n < 0 || x == 0) return 0;

	if (dp[n][x])
		return dp[n][x];
	if (h[n] <= x)
		dp[n][x] = max(s[n] + calculate(n - 1, p + s[n], x - h[n]), calculate(n - 1, p, x));
	else
		dp[n][x] = calculate(n - 1, p, x);
	return dp[n][x];
}

int32_t main() {

	start();

	int n, x;
	cin >> n >> x;
	rep(i, 0, n) {
		cin >> h[i];
	}
	rep(i, 0, n) {
		cin >> s[i];
	}
	int ans = calculate(n - 1, 0, x);

	cout << ans << "\n";

	return 0;
}