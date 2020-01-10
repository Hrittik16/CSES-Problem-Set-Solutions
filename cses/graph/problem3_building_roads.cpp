#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define rep(i, a, b) for(int i = a; i < b; i++) 
#define repll(i, a, b) for(ll i = a; i < b; i++) 
#define all(a) (a).begin(),(a).end()
#define pb push_back

void dfs(vector<vector<ll>>& adj, vector<bool>& check, ll beg) {
    check[beg] = 1;
    for(auto x: adj[beg]) {
        if(!check[x])
            dfs(adj, check, x);
    }
}

int main() {

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    repll(i, 0, m) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll count = 0, prev = -1;
    vector<bool> check(n+1, 0);
    vector<pair<ll, ll>> roads;
    repll(i, 1, n+1) {
        if(!check[i]) {
            dfs(adj, check, i);
            count++;
            if(prev == -1) {
                prev = i;
                continue;
            }
            roads.pb({prev, i});
            prev = i;
        }
        prev = i;
    }

    cout << count-1 << "\n";
    for(auto x: roads) cout << x.first << " " << x.second << "\n";

    return 0;
}