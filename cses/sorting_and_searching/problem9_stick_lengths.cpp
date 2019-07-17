#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repll(i, a, b) for(ll i = a; i < b; i++)
#define vi vector<int>
#define vl vector<ll>
#define all(v) v.begin(),v.end()
using namespace std;
int main() {
	
	ll n;
	cin >> n;
	vl p(n);
	repll(i, 0, n) cin >> p[i];
	sort(all(p));
	ll mid, diff = 0;
	if(n%2 == 0) mid = (n/2)-1;
	else mid = n/2;
	repll(i, 0, n) diff += abs(p[i]-p[mid]);
	cout << diff << "\n";

	return 0;
}