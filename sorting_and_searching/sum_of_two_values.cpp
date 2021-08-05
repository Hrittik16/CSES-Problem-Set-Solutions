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
	int n, x;
	cin >> n >> x;
	map<int, int> m;
	vi a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	rep(i, 0, n) {
		int s = x-a[i];
		if(m.find(s) != m.end()) {
			cout << i+1 << " " << m[s] << "\n";
			return 0;
		}
		if(m.find(a[i]) == m.end())
			m[a[i]] = i+1;
	}
	cout << "IMPOSSIBLE\n";
}