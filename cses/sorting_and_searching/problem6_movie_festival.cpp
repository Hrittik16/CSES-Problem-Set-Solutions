#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ll n, i, a, b, last = 0;
	cin >> n;
	set< pair<ll, ll> > st;
	for(i = 0; i < n; i++) {
		cin >> a >> b;
		st.insert({b, a});
	}
	ll count = 0;
	if(st.size() == 1) {
		cout << 1 << "\n";
		return 0;
	}
	for(auto x: st) {
		if(x.second >= last) {
			count++;
			last = x.first;
		}
	}
	cout << count << "\n";
	return 0;
}