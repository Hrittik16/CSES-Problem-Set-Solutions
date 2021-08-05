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

bool comp(const pii& a, const pii& b) {
	return (a.s < b.s);
}

int32_t main() {
	int n;
	cin >> n;
	vector<pii> a;
	rep(i, 0, n) {
		int x, y;
		cin >> x >> y;
		a.pb(mp(x, y));
	}
	sort(all(a), comp);
	int count = 1, curr = 0;
	rep(i, 0, n) {
		auto it = a[i];
		if(i == 0) {
			curr = it.s;
			continue;
		}
		if(curr <= it.f) {
			count++;
			curr = it.s;
		}
	}
	cout << count << "\n";	
}