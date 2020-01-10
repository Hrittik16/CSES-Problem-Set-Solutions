#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define rep(i, a, b) for(int i = a; i < b; i++) 
#define repll(i, a, b) for(ll i = a; i < b; i++) 
#define all(a) (a).begin(),(a).end()
#define pb push_back

void bfs(vector<vector<ll>>& adj, vector<bool>& check, vl& dist, vl& prev, ll beg) {
    queue<ll> q;
    q.push(beg);
    check[beg] = 1;
    dist[beg] = 1;
    prev[beg] = -1;
    while(!q.empty()) {
        ll x = q.front();
        q.pop();
        for(auto t: adj[x]) {
            if(!check[t]) {
                q.push(t);
                check[t] = 1;
                dist[t] = dist[x]+1;
                prev[t] = x;
            }
        }
    }
}

int main() {

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n+1);

    repll(i, 0, m) {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<bool> check(n+1, 0);
    vl dist(n+1, 0);
    vl prev(n+1);

    bfs(adj, check, dist, prev, 1);

    if(check[n]) {
        cout << dist[n] << "\n";
        stack<ll> st;
        ll curr = n;
        while(prev[curr] != -1) {
            st.push(curr);
            curr = prev[curr];
        }
        st.push(curr);
        while(!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }
    else 
        cout << "IMPOSSIBLE\n";

    return 0;
}