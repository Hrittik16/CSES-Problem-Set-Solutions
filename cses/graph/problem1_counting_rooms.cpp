#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define rep(i, a, b) for(int i = a; i < b; i++) 
#define repll(i, a, b) for(ll i = a; i < b; i++) 
#define all(a) (a).begin(),(a).end()
#define pb push_back

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& check, ll i, ll j) {
    if(grid[i][j] == '#' || check[i][j])
        return;
    if(grid[i][j] == '.' && !check[i][j])
        check[i][j] = 1;
    if(i+1 < grid.size())
        dfs(grid, check, i+1, j);
    if(j+1 < grid[0].size())
        dfs(grid, check, i, j+1);
    if(i-1 >= 0)
        dfs(grid, check, i-1, j);
    if(j-1 >= 0)
        dfs(grid, check, i, j-1);
}

int main() {

    ll m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    repll(i, 0, m) {
        repll(j, 0, n) 
            cin >> grid[i][j];
    }

    vector<vector<bool>> check(m, vector<bool>(n, 0));

    ll count = 0;

    repll(i, 0, m) {
        repll(j, 0, n) {
            if(grid[i][j] == '#')
                continue;
            else if(check[i][j] == 1) 
                continue;
            else {
                dfs(grid, check, i, j);
                count++;
            }
        }
    }

    cout << count << "\n";


    return 0;
}