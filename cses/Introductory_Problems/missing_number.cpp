#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ll n, sum = 0;
	cin >> n;
	for (ll i = 0; i < n - 1; i++) {
		ll a;
		cin >> a;
		sum += a;
	}

	cout << (n * (n + 1)) / 2 - sum << "\n";


	return 0;
}