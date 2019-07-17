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
	// 260443
	ll n;	
	cin >> n;
	ll val = (n*(n+1))/2;
	if(val%2 != 0) cout << "NO\n";
	else if(n == 1) cout << "NO\n";
	else {
		vl a, b, s, index;
		index.insert(index.begin(), 1);
		repll(i, 1, n) {
			s.pb(n-i);
			index.pb(0);
		}
		a.pb(n);
		ll sum = n;
		ll target = ((n*(n+1))/2)/2;
		ll j = 0;
		while(sum != target) {
			ll p = target-sum;
			if(binary_search(s.rbegin(), s.rend(), p) && !index[n-p]) {
				a.pb(p);
				index[n-p] = 1;
				break;
			}	
			sum += s[j];
			a.pb(s[j]);
			index[n-s[j]] = 1;
			j++;
		}
		repll(i, 1, n) if(!index[i]) b.pb(s[i-1]);
		ll a_size = a.size(), b_size = b.size();
		cout << "YES\n";
		cout << a_size << "\n";
		repll(i, 0, a_size) cout << a[i] << " ";
		cout << "\n";
		cout << b_size << "\n";
		repll(i, 0, b_size) cout << b[i] << " ";
		cout << "\n";
	}
	
	return 0;
}


