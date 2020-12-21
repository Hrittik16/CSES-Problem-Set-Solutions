#include <bits/stdc++.h>
using namespace std;

#define int 				long long
#define f 					first
#define s 					second
#define pb 					push_back
#define mp 					make_pair
#define vi 					vector<int>
#define pii					pair<int, int>
#define mii					map<int, int>
#define all(a) 				(a).begin(),(a).end()
#define sz(x) 				(x).size()
#define rep(i, a, b) 		for(int i = a; i < b; i++)
#define pqb					priority_queue<int>
#define pqs					priority_queue<int, vi, greater<int>>
#define setbits(x)			__builtin_popcountll(x)
#define zerobits(x)			__builtin_ctzll(x) // counts number of leading 0's before 1st occurnace of 1
#define mod 				1000000007
#define inf					1e18+7
#define ps(x, y)			fixed << setprecision(y) << x
#define string_to_int(x)	stoi(x)
#define int_to_string(x)	to_string(x)
#define test				int T; cin >> T; while(T--)

void start() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main() {
	start();
	int n;
	cin >> n;
	if ((n * (n + 1) / 2) % 2 != 0) cout << "NO\n";
	else {
		stack<int> s1, s2;
		int flag = 1;
		s1.push(n);
		for (int i = n - 1; i >= 1; i -= 2) {
			if (flag) {
				s2.push(i);
				if (i - 1 >= 1)
					s2.push(i - 1);
				flag = 0;
			}
			else {
				s1.push(i);
				if (i - 1 >= 1)
					s1.push(i - 1);
				flag = 1;
			}
		}
		cout << "YES\n";
		cout << sz(s1) << "\n";
		while (!s1.empty()) {
			cout << s1.top() << " ";
			s1.pop();
		}
		cout << "\n";
		cout << sz(s2) << "\n";
		while (!s2.empty()) {
			cout << s2.top() << " ";
			s2.pop();
		}
		cout << "\n";
	}


	return 0;
}
