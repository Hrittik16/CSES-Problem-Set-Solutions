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
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int mx = INT_MIN, total =INT_MIN;
	rep(i, 0, n) {
		if(i == 0) total = a[i];
		else {
			total = max(a[i], a[i]+total);
		}
		mx = max(mx, total);
	}
	cout << mx << "\n";
}