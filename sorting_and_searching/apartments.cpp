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
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n), b(m);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];
	sort(all(a));
	sort(all(b));
	int i = 0, j = 0, count = 0;
	while(i < n && j < m) {
		if(b[j] >= a[i]-k && b[j] <= a[i]+k) {
			count++;
			i++;
			j++;
		}
		else if(a[i] > b[j]) j++;
		else i++;
		
	}
	cout << count << "\n";
	return 0;
}
