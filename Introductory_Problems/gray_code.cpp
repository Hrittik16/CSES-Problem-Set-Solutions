#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < b; i++)

int hamming_dist(int a, int b) {
	int total = 0;
	int c = a ^ b;
	while (c > 0) {
		total += (c & 1);
		c >>= 1;
	}
	return total;
}

void print(int a, int n) {
	stack<int> digits;
	while (a > 0) {
		digits.push(a & 1);
		a >>= 1;
	}
	for (int i = 0; i < n - digits.size(); i++)
		cout << "0";
	while (!digits.empty()) {
		cout << digits.top();
		digits.pop();
	}
	cout << "\n";
}

int32_t main() {

	int n;
	cin >> n;
	vector<bool> vis(1 << n, 0);
	rep(i, 0, n) cout << "0";
	cout << "\n";
	vector<int> v;
	int prev = 0;
	int j = 1;
	while (j != 1 << n) {
		int x = j;
		if (vis[x]) {
			j++;
			continue;
		}
		while (hamming_dist(prev, x) != 1) {
			x++;
			if (x == 1 << n) break;
		}
		v.push_back(x);
		vis[x] = 1;
		prev = x;
		if (x == j) j++;
	}

	for (auto x : v) {
		print(x, n);
	}

	return 0;
}