#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()

int32_t main() {
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n), b(m);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];

	sort(all(a));
	sort(all(b));

	int count = 0, j = 0;

	rep(i, 0, n) {
		int p = a[i];
		while(j < m) {
			if(b[j] >= p-k && b[j] <= p+k) {
				count++;
				j++;
				break;
			}
			else if(b[j] > p+k) break;
			j++;
		}
	}

	cout << count << "\n";	
}