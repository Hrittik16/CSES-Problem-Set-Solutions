#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define rep(i, a, b) for(int i = a; i < b; i++)
 
int32_t main() {
	int n;
	cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i]; 
	map<int, int> mp;
	int curr = 0, mx = 0;
	rep(i, 0, n) {
		if(mp.find(a[i]) == mp.end()) {
			mp[a[i]] = i;
		}
		else {
			if(mp[a[i]] < curr) {
				mp[a[i]] = i;
			}
			else {
				curr = mp[a[i]]+1;
				mp[a[i]] = i;
			}
		}
		mx = max(mx, i-curr+1);
	}
	cout << mx << "\n";
	return 0;
}
