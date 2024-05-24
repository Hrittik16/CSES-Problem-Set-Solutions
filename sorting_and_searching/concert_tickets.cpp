#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define rep(i, a, b) for(int i = a; i < b; i++)
 
int32_t main() {
	int n, m;
	cin >> n >> m;
	vi h(n), t(m);
	map<int, int> mp;
	rep(i, 0, n) cin >> h[i], mp[h[i]]++;
	rep(i, 0, m) cin >> t[i];
	rep(i, 0, m) {
		auto it = mp.upper_bound(t[i]);
		if(it == mp.begin()) { cout << "-1\n"; continue;}
		it--;
		if(it->f <= t[i]) {
			cout << it->f << "\n";
			mp[it->f]--;
			if(mp[it->f] == 0) mp.erase(it);
		}
		else cout << "-1\n";
	}
	return 0;
}
