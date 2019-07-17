#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector< vi >
#define vvl vector< vl >
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
const ll mod = 1e9+7;
int main() {
	
	ll n, m, k;
	cin >> n >> m >> k;
	vl a(n), b(m);
	repll(i, 0, n) cin >> a[i];
	repll(i, 0, m) cin >> b[i];
	sort(all(a));
	sort(all(b));
	ll i = 0, j = 0, count = 0;
	while(i < n && j < m) {
		if(b[j] <= a[i]+k && b[j] >= a[i]-k) {
			count++;
			i++;
			j++;
		}
		else if(b[j] < a[i]-k) {
			j++;
		}
		else if(b[j] > a[i]+k) {
			i++;
		}
		
	}

	cout << count << "\n";

	return 0;
}
