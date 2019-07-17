#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repll(i, a, b) for(ll i = a; i < b; i++)
#define vi vector<int>
#define vl vector<ll>
using namespace std;
int main() {
	
	ll n;
	cin >> n;
	vector<ll> v(n);
	repll(i, 0, n) cin >> v[i];
	ll mx = INT_MIN;
	vl dp(n+1, 0);
	repll(i, 1, n+1) {
		dp[i] = max(v[i-1], dp[i-1]+v[i-1]);
		mx = max(mx, dp[i]);
		//cout << "dp[i] = " << dp[i] << "\n";
		//cout << "mx = " << mx << "\n";
	}

	cout << mx << "\n";

	return 0;
}