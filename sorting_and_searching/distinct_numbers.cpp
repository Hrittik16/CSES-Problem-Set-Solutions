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
	set<int> unique;
	rep(i, 0, n) {
		int input;
		cin >> input;
		unique.insert(input);
	}
	cout << unique.size() << "\n";
	return 0;
}
