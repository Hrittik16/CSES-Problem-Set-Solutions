#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	ll curr_mx = a[0], total = 0;

	for (ll i = 1; i < n; i++) {
		if (a[i] < curr_mx) {
			total += curr_mx - a[i];
		}
		curr_mx = max(curr_mx, a[i]);
	}

	cout << total << "\n";


	return 0;
}