#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb push_back

void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
	visited[i][j] = 1;
	int dir[] = {-1, 1};
	rep(k, 0, 2) {
		if(i+dir[k] >= 0 && i+dir[k] <= grid.size()-1) {
			if(grid[i+dir[k]][j] == '.' && !visited[i+dir[k]][j])
				dfs(grid, i+dir[k], j, visited);
		}
	}
	rep(k, 0, 2) {
		if(j+dir[k] >= 0 && j+dir[k] <= grid[0].size()-1) {
			if(grid[i][j+dir[k]] == '.' && !visited[i][j+dir[k]]) 
				dfs(grid, i, j+dir[k], visited);
		}
	}
}

int32_t main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	rep(i, 0, n) {
		rep(j, 0, m)
			cin >> grid[i][j];
	}
	vector<vector<bool>> visited(n, vector<bool>(m, 0));
	int rooms = 0;
	rep(i, 0, n) {
		rep(j, 0, m) {
			if(grid[i][j] == '.' && !visited[i][j]) {
				rooms++;
				dfs(grid, i, j, visited);
			}
		}
	}
	cout << rooms << "\n";
}
