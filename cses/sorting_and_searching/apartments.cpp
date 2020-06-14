#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vl vector<ll>
#define all(x) x.begin(),x.end()
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repll(i, a, b) for(ll i = a; i < b; i++)

int main() {

	ll n, m, k;
	cin >> n >> m >> k;	
	vl d(n), a(m);
	repll(i, 0, n)
		cin >> d[i];
	repll(i, 0, m)
		cin >> a[i];

	sort(all(d));
	sort(all(a));

	ll j = 0, i = 0, count = 0;
	while(i < n && j < m) {
		if(d[i] >= a[j]-k && d[i] <= a[j]+k) {
			count++;
			i++;
			j++;
		} 
		else if(d[i] > a[j]) {
			j++;
		}
		else {
			i++;
		}
	}

	cout << count << "\n";		

	return 0;
}