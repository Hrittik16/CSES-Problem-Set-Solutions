#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {

	// 2 3 5
	// 4 8 9

	ll n, x, y;
	cin >> n;	
	vector<ll> a, b;
	for(ll i = 0; i < n; i++) {
		cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
	} 
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll i = 0, j = 0, p = 0, val = 0;
	while(1) {
		if(a[i] <= b[j]) {
			p++;
			i++;
		}
		else if(b[j] < a[i]) {
			p--;
			j++;
		}
		val = max(val, p);
		if(i == n) break;
	}

	cout << val << "\n";

	return 0;
}