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

	ll n, x;
	cin >> n >> x;
	vl p(n);	
	repll(i, 0, n)
		cin >> p[i];

	sort(all(p));

	ll number = 0;

	ll i = 0, j = n-1;

	while(i <= j) {
		if(p[i]+p[j] > x) {
			number++;
			j--;
		}
		else {
			number++;
			i++;
			j--;
		}
	}

	cout << number << "\n";

	return 0;
}