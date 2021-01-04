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

int32_t main() {
	start();
	int n;
	cin >> n;
	vector<pii> a(n);
	rep(i, 0, n) {
		cin >> a[i].first >> a[i].second;
	}

	multiset<int, greater<int>> dep;

	vi index;

	rep(i, 0, n) {
		auto it = dep.upper_bound(a[i].first);
		if (it == dep.end()) {
			dep.insert(a[i].second);
			index.pb(dep.size());
		}
		else {
			auto dist = distance(dep.begin(), it);
			index.pb(dep.size() - dist);
			dep.erase(it);
			dep.insert(a[i].second);
		}
	}

	cout << dep.size() << "\n";
	for (auto x : index) cout << x << " ";
	cout << "\n";

	return 0;
}