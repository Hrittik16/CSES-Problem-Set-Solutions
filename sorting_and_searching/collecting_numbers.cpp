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
	// Test Cases
	// 6
	// 6 1 3 2 5 4 
	set<int> st;
	st.insert(a[0]);
	rep(i, 1, n) {
		auto it = st.find(a[i]-1);
		if(it != st.end()) {
			st.erase(it);
			st.insert(a[i]);
		}
		else st.insert(a[i]);
	}
	cout << st.size() << "\n";
	return 0;
}
