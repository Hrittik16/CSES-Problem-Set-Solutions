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

int32_t main() {
	int n;
	cin >> n;
	vector<pii> v;
	int total = 0, mx = 0;
	rep(i, 0, n) {
		int a, b;
		cin >> a >> b;
		v.pb(mp(a, 1));
		v.pb(mp(b, -1));
	}
	sort(all(v));
	for(auto &x: v) {
		total += x.s;
		mx = max(mx, total);
	}
	cout << mx << "\n";
}