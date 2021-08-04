#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) (x)->begin(), (x)->end()
#define f first
#define s second

int32_t main() {
	int n, m;
	cin >> n >> m;
	vi a(n), b(m);
	map<int, int> mp;
	rep(i, 0, n) {
		cin >> a[i];
		mp[a[i]]++;
	}
	rep(i, 0, m) cin >> b[i];
	rep(j, 0, m) {
		auto it = mp.lower_bound(b[j]);
		if(it->f == b[j]) {
			it->s--;
			cout << it->f << "\n";
			if(it->s == 0) mp.erase(it);
		} 
		else if(it == mp.begin()) {
			if(it->f > b[j]) cout << "-1\n";
			else {
				cout << it->f << "\n";
				it->s--;
				if(it->s == 0) mp.erase(it);
			}
		}
		else {
			it--;
			if(it->f > b[j]) cout << "-1\n";
			else {
				cout << it->f << "\n";
				it->s--;
				if(it->s == 0) mp.erase(it);
			}	
		}

		if(mp.empty()) {
			rep(k, 0, m-j-1) cout << "-1\n";
			break;
		}
	}
}