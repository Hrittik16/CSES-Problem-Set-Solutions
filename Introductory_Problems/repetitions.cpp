#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	string s;
	cin >> s;
	ll len = 1, mx = 1;
	for (int i  = 1; i < s.length(); i++) {
		if (s[i] == s[i - 1]) len++;
		else len = 1;
		mx = max(mx, len);
	}

	cout << mx << "\n";


	return 0;
}