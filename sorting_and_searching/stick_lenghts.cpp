#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb push_back

int32_t main() {
	int n;
	cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	sort(all(a));
	int mid = a[n/2], dist = 0;
	rep(i, 0, n) dist += abs(a[i] - mid);
	cout << dist << "\n";
}