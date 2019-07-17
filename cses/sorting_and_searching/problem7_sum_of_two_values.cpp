#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	
	ll n, x, pos1 = 0, pos2 = 0;
	cin >> n >> x;
	vector<ll> a(n), b;
	vector<bool> c(n, 0);
	for(ll i = 0; i < n; i++) cin >> a[i];
	b = a;
	sort(a.begin(), a.end());
	ll beg = 0, end = n-1, flag = 0;
	while(beg < end) {
		if(a[beg]+a[end] == x) {
			flag = 1;
			for(ll j = 0; j < n; j++) {
				if(b[j] == a[beg]) { c[j] = 1; pos1 = j+1; break; }
			}
			for(ll k = 0; k < n; k++) {
				if(b[k] == a[end] && c[k] == 0) { pos2 = k+1; break; }
			}
			break;
		}
		if(a[beg]+a[end] < x) beg++;
		else end--;
	}

	if(!flag) cout << "IMPOSSIBLE\n";
	else cout << min(pos1, pos2) << " " << max(pos1, pos2) << "\n";

	return 0;
}