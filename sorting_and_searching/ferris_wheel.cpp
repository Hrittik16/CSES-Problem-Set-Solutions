#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()

int32_t main() {
	int n, x;
	cin >> n >> x;
	vi p(n);
	rep(i, 0, n) cin >> p[i];
	sort(all(p));

	int count = 0;

	int i = 0, j = n-1;

	while(i <= j) {
		if(i == j) {
			count++;
			break;
		}
		else if(p[i] + p[j] <= x) {
			count++;
			i++;
			j--;
		}
		else {
			count++;
			j--;
		}
	}

	cout << count << "\n";
}