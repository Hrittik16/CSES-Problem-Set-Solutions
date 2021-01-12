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
int dist[1007][1007];
char previous[1007][1007];
map<pii, pii> parent;
int n, m, pp, qq;

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	vis[i][j] = 1;
	q.push({i, j});
	while (!q.empty()) {
		auto curr = q.front();
		q.pop();
		for (auto x : { -1, 1}) {
			if (curr.f + x >= 0 && curr.f < n && !vis[curr.f + x][curr.s] && grid[curr.f + x][curr.s] != '#') {
				vis[curr.f + x][curr.s] = 1;
				dist[curr.f + x][curr.s] = dist[curr.f][curr.s] + 1;
				q.push({curr.f + x, curr.s});
				if (x == -1) previous[curr.f + x][curr.s] = 'U';
				else previous[curr.f + x][curr.s] = 'D';
				parent[ {curr.f + x, curr.s}] = {curr.f, curr.s};
			}
			if (curr.s >= 0 && curr.s < m && !vis[curr.f][curr.s + x] && grid[curr.f][curr.s + x] != '#') {
				vis[curr.f][curr.s + x] = 1;
				dist[curr.f][curr.s + x] = dist[curr.f][curr.s] + 1;
				q.push({curr.f, curr.s + x});
				if (x == -1) previous[curr.f][curr.s + x] = 'L';
				else previous[curr.f][curr.s + x] = 'R';
				parent[ {curr.f, curr.s + x}] = {curr.f, curr.s};
			}
		}
	}
}

int32_t main() {

	//start();
	int x, y;
	cin >> n >> m;
	rep(i, 0, n) {
		rep(j, 0, m) {
			cin >> grid[i][j];
			if (grid[i][j] == 'A') {
				x = i;
				y = j;
			}
			if (grid[i][j] == 'B') {
				pp = i;
				qq = j;
			}
		}
	}

	bfs(x, y);

	if (!vis[pp][qq]) {
		cout << "NO\n";
		return 0;
	}

	stack<char> path;

	cout << "YES\n";
	cout << dist[pp][qq] << "\n";
	while (1) {
		path.push(previous[pp][qq]);
		int xx = parent[ {pp, qq}].first;
		int yy = parent[ {pp, qq}].second;
		pp = xx;
		qq = yy;
		if (pp == x && qq == y) break;
	}
	while (!path.empty()) {
		cout << path.top();
		path.pop();
	}
	cout << "\n";

	return 0;
}