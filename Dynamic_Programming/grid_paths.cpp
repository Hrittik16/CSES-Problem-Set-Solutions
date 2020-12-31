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

int dp[1007][1007];
int vis[1007][1007];

int dfs(vector<vector<char>>& grid, int n, int i, int j) {
	if (i == n - 1 && j == n - 1)
		dp[i][j] = 1;
	if (vis[i][j]) return dp[i][j];
	if (j + 1 < n && grid[i][j + 1] != '*')
		dp[i][j] = (dp[i][j] + dfs(grid, n, i, j + 1)) % mod;
	if (i + 1 < n && grid[i + 1][j] != '*')
		dp[i][j] = (dp[i][j] + dfs(grid, n, i + 1, j)) % mod;
	vis[i][j] = 1;
	return dp[i][j];
}

int32_t main() {
	start();
	int n;
	cin >> n;
	vector<vector<char>> grid(n, vector<char>(n));
	rep(i, 0, n) {
		rep(j, 0, n)
		cin >> grid[i][j];
	}

	if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
		cout << "0\n";
		return 0;
	}

	int total = dfs(grid, n, 0, 0);

	cout << total % mod << "\n";

	return 0;
}