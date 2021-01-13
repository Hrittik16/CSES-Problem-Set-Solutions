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

vector<int> graph[100007];
vector<bool> vis(100007);

void dfs(int i) {
	vis[i] = 1;
	for (auto x : graph[i]) {
		if (!vis[x]) {
			dfs(x);
		}
	}
}

int32_t main() {
	// start();

	int n, m;
	cin >> n >> m;
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	int count = 0, prev = 1;
	vector<pii> pairs;
	rep(i, 1, n + 1) {
		if (!vis[i]) {
			count++;
			if (i != 1) {
				pairs.pb({prev, i});
				prev = i;
			}
			dfs(i);
		}
	}

	cout << count - 1 << "\n";
	for (auto x : pairs) {
		cout << x.f << " " << x.s << "\n";
	}

	return 0;
}
