#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define rep(i, a, b) for(int i = a; i < b; i++) 
#define repll(i, a, b) for(ll i = a; i < b; i++) 
#define all(a) (a).begin(),(a).end()
#define pb push_back

void bfs(vector<vector<char>>& grid, vector<vector<ll>>& dist, vector<vector<bool>>& check, vector<vector<pair<pair<ll, ll>, char>>>& prev, ll x_a, ll y_a) {
	queue<pair<ll, ll>> q;
	q.push({x_a, y_a});
	check[x_a][y_a] = 1;
	dist[x_a][y_a] = 0;
	prev[x_a][y_a] = {{x_a, y_a}, 'O'};
	while(!q.empty()) {
		auto x = q.front();
		q.pop();
		if(x.first+1 < grid.size() && !check[x.first+1][x.second]) {
			if(grid[x.first+1][x.second] != '#') {
				q.push({x.first+1, x.second});
				check[x.first+1][x.second] = 1;
				dist[x.first+1][x.second] = dist[x.first][x.second]+1;
				prev[x.first+1][x.second] = {{x.first, x.second}, 'D'};
			}
			else
				check[x.first+1][x.second] = 1;
		}
		if(x.first-1 >= 0 && !check[x.first-1][x.second]) {
			if(grid[x.first-1][x.second] != '#') {
				q.push({x.first-1, x.second});
				check[x.first-1][x.second] = 1;
				dist[x.first-1][x.second] = dist[x.first][x.second]+1;
				prev[x.first-1][x.second] = {{x.first, x.second}, 'U'};
			}
			else 
				check[x.first-1][x.second] = 1;
		}
		if(x.second+1 < grid[0].size() && !check[x.first][x.second+1]) {
			if(grid[x.first][x.second+1] != '#') {
				q.push({x.first, x.second+1});
				check[x.first][x.second+1] = 1;
				dist[x.first][x.second+1] = dist[x.first][x.second]+1;
				prev[x.first][x.second+1] = {{x.first, x.second}, 'R'};
			}
			else
				check[x.first][x.second+1] = 1;
		}
		if(x.second-1 >= 0 && !check[x.first][x.second-1]) {
			if(grid[x.first][x.second-1] != '#') {
				q.push({x.first, x.second-1});
				check[x.first][x.second-1] = 1;
				dist[x.first][x.second-1] = dist[x.first][x.second]+1;
				prev[x.first][x.second-1] = {{x.first, x.second}, 'L'};
			}
			else 
				check[x.first][x.second-1] = 1;
		}
	}
}

int main() {

	ll n, m, x_a, y_a, x_b, y_b;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	repll(i, 0, n) {
		repll(j, 0, m) {
			cin >> grid[i][j];
			if(grid[i][j] == 'A') {
				x_a = i;
				y_a = j;
			}
			else if(grid[i][j] == 'B') {
				x_b = i;
				y_b = j;
			}
		}
	}

	vector<vector<ll>> dist(n, vector<ll>(m, 0));
	vector<vector<pair<pair<ll, ll>, char>>> prev(n, vector<pair<pair<ll, ll>, char>>(m));
	vector<vector<bool>> check(n, vector<bool>(m, 0));

	bfs(grid, dist, check, prev, x_a, y_a);

	if(check[x_b][y_b]) {
		stack<char> direction;
		auto it = prev[x_b][y_b];
		while(it.second != 'O') {
			direction.push(it.second);
			it = prev[it.first.first][it.first.second];
		}
		cout << "YES\n";
		cout << dist[x_b][y_b] << "\n";
		while(!direction.empty()) {
			cout << direction.top();
			direction.pop();
		}
		cout << "\n";
	}
	else {
		cout << "NO\n";
	}
	
	return 0;
}