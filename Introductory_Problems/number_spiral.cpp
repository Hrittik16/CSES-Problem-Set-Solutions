#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t, x, y;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		if (x == y) {
			ll ans = (y - 1) * (y - 1) + x;
			cout << ans << "\n";
		}
		else if (y > x) {
			if (y & 1) {
				// starts from left
				ll ans = y * y - (x - 1);
				cout << ans << "\n";
			}
			else {
				// starts from top
				ll ans = (y - 1) * (y - 1) + x;
				cout << ans << "\n";
			}
		}
		else {
			if (x & 1) {
				// starts from left
				ll ans = (x - 1) * (x - 1) + y;
				cout << ans << "\n";
			}
			else {
				// starts from top
				ll ans = x * x - (y - 1);
				cout << ans << "\n";
			}
		}
	}



	return 0;
}