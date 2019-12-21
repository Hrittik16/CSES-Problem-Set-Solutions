#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector< pii >
#define vpll vector< pll >
#define rep(i, a, b) for(int i = a; i < b; i++) 
#define repll(i, a, b) for(ll i = a; i < b; i++) 
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define F first
#define S second
#define string_to_int(s) stoi(s)
#define string_to_ll(s) stoll(s)
#define int_to_string(n) to_string(n)
#define ll_to_string(n) to_string(n)
#define char_to_int(c) c-'0'
#define int_to_char(c) c+'0'
 
int main() {
	ll n;
	cin >> n;
	multiset<ll> v;
	repll(i, 0, n) {
		ll x;
		cin >> x;
		auto it = v.upper_bound(x);
		if(it == v.end()) v.insert(x);
		else {
			v.erase(it);
			v.insert(x);
		}
	}
	
	cout << v.size() << "\n";
	
	
	return 0;
}