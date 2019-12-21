#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define rep(i, a, b) for(int i = a; i < b; i++) 
#define repll(i, a, b) for(ll i = a; i < b; i++) 
#define all(a) (a).begin(),(a).end()
#define pb push_back

int main() {
		
	ll n, count = 0, mx = 0, i =0, prev = 0;
	cin >> n;
	map<ll, ll> mp;
	map<ll, ll> index;
	vl v;
	while(n--) {
		ll x;
		cin >> x;
		v.pb(x);
		if(mp[x] == 0) {
			mp[x] = 1;
			count++;
			index[x] = i;
		}
		else {
			count = i - index[x];
			for(ll j = prev; j <= index[x]; j++) {
				mp[v[j]] = 0;
			}
			prev = index[x]+1;
			mp[x] = 1;
			index[x] = i;
		}
		mx = max(mx, count);
		i++;
	}

	cout << mx << "\n";



	return 0;
}