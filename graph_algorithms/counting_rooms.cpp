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

void start() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

char grid[1007][1007];
bool vis[1007][1007];
int n, m;

void dfs(int i, int j) {
	vis[i][j] = 1;
	if (i + 1 < n && !vis[i + 1][j] && grid[i + 1][j] != '#') {
		dfs(i + 1, j);
	}
	if (i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] != '#') {
		dfs(i - 1, j);
	}
	if (j + 1 < m && !vis[i][j + 1] && grid[i][j + 1] != '#') {
		dfs(i, j + 1);
	}
	if (j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] != '#') {
		dfs(i, j - 1);
	}
}

int32_t main() {

	start();

	cin >> n >> m;
	rep(i, 0, n) {
		rep(j, 0, m) {
			cin >> grid[i][j];
		}
	}

	int count = 0;

	rep(i, 0, n) {
		rep(j, 0, m) {
			if (grid[i][j] == '.' && !vis[i][j]) {
				count++;
				dfs(i, j);
			}
		}
	}

	cout << count << "\n";

	return 0;
}
