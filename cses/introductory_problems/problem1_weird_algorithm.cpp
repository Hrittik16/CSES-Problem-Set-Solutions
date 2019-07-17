#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector< vi >
#define vvl vector< vl >
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repll(i, a, b) for(ll i = a; i < b; i++) 
#define all(a) a.begin(),a.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector< pii >
#define vpll vector< pll >
#define F first
#define S second
#define pb push_back

int main() {

	ll n;
	cin >> n;
	while(1) {
		if(n == 1) {
			cout << n << "\n";
			break;
		}

		cout << n << " ";
		if(n%2 == 0) n = n/2;
		else n = 3*n+1;
	}
	
	
	
	
	return 0;
}
