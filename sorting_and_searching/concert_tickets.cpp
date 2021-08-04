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

int32_t main() {
	int n, m;
	cin >> n >> m;
	vi a(n);
	set<pii> st;
	rep(i, 0, n) {
		cin >> a[i];
		st.insert(mp(a[i], i));
	}
	
	rep(i, 0, m) {
		int x;
		cin >> x;
		auto it = st.lower_bound(mp(x+1, 0));
		if(it == st.begin()) cout << "-1\n";
		else {
			it--;
			cout << it->f << "\n";
			st.erase(it);
		}
	}
}