#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		if (i == 1) {
			cout << "0\n";
			continue;
		}
		if (i == 2) {
			cout << "6\n";
			continue;
		}
		ll total_positions = (i * i * (i * i - 1)) / 2;
		ll ans = total_positions - 2 * (i - 2) * (i - 1) * 2;
		cout << ans << "\n";
	}

	return 0;
}