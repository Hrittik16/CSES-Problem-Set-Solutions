#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int32_t main() {
	int q, k;
	cin >> q;
	while(q--) {
		cin >> k;
		int num = 10;
		
		if(k <= num) {
			cout << k << "\n";
			continue;
		}

		int increment = 10;
		int digits = 2;
		int total = 10;
		
		// 12

		if(k <= total) {
			// range -> [10^(digits-1), 10*increment-1]
			k -= total;
			int x = 10^(digits-1);
			int n = 1, m = 0, new_total = 0;
			n = k/digits;
			m = k%digits;
			int new_number = x*n;
			if(m == 0) {
				string nn = to_string(new_number);
				cout << nn[k-1] << "\n";
			}
			else {
				new_number++;
				string nn = to_string(new_number);
				cout << nn[m-1] << "\n";
			}

		}
		else {
			total += 9*increment*digits;
			increment *= 10;
			digits++;
		}
	}
}
