#include <bits/stdc++.h>
using namespace std;

#define int 				long long int
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

int total;

bool diagonal(int a, int b, int c, int d) {
	bool flag = 0;
	int x = a - 1, y = b - 1;
	while (x >= 0 && y >= 0) {
		if (x == c && y == d) {
			flag = 1;
			break;
		}
		x--;
		y--;
	}
	if (flag) return 1;
	x = a - 1;
	y = b + 1;
	while (x >= 0 && y <= 7) {
		if (x == c && y == d) {
			flag = 1;
			break;
		}
		x--;
		y++;
	}
	return flag;
}

void n_queens(vector<vector<char>>& grid, vector<pii>& index, int i) {
	if (i == 8) {
		total++;
		return;
	}
	rep(j, 0, 8) {
		if (grid[i][j] == '*') {
			continue;
		}
		bool flag = 1;
		for (auto x : index) {
			if (x.second == j || diagonal(i, j, x.first, x.second)) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			index.pb(mp(i, j));
			n_queens(grid, index, i + 1);
			index.pop_back();
		}
	}
	return;
}

int32_t main() {
	start();

	vector<vector<char>> grid(8, vector<char>(8));
	vector<pii> index;
	rep(i, 0, 8) {
		rep(j, 0, 8) {
			cin >> grid[i][j];
		}
	}

	n_queens(grid, index, 0);
	cout << total << "\n";

	return 0;
}
