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
	int n, x;
	cin >> n >> x;
	vi p(n);
	rep(i, 0, n) cin >> p[i];
	sort(all(p));
	int beg = 0, end = n-1, count = 0;
	while(beg <= end) {
		if(p[beg]+p[end] <= x) {
			count++;
			beg++;
			end--;
		}
		else count++, end--;
	}
	cout << count << "\n";
	return 0;
}
