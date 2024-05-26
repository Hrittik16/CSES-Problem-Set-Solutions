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
	map<int, int> mp;
	rep(i, 0, n) {cin >> a[i]; mp[a[i]] = i;}
	// Test Cases
	// 6
	// 6 1 3 2 5 4 
	int count = 1, prev = mp[1];
	for(auto x: mp) {
		if(x.s < prev) count++;
		prev = x.s;
	}
	cout << count << "\n";
	return 0;
}
