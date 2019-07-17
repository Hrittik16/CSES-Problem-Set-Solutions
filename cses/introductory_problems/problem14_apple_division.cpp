/*
	RECURSIVE SOLUTION
	Time Complexity - O(2^n)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector< pii >
#define vpll vector< pll >
#define rep(i, a, b) for(int i = a; i < b; i++) 
#define repll(i, a, b) for(ll i = a; i < b; i++) 
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define F first
#define S second
#define string_to_int(s) stoi(s)
#define string_to_ll(s) stoll(s)
#define int_to_string(n) to_string(n)
#define ll_to_string(n) to_string(n)
#define char_to_int(c) c-'0'
#define int_to_char(c) c+'0'
const ll mod = 1e9+7;

ll check(vl& p, ll n, ll curr_sum, ll sum) { // curr_sum will hold the sum of 1st set
	if(n == 0) return abs((sum-curr_sum)-curr_sum); // (sum-curr_sum) -> is the sum of 2nd set, (sum-curr_sum)-curr_sum -> is the diff of sum of 1st and 2nd set 
	return min(check(p, n-1, curr_sum+p[n-1], sum), check(p, n-1, curr_sum, sum)); 
	// we either include the nth element in the 1st set or we don't
}

int main() {
	// 70 257 324 493 521 573 603 654 659 718
	ll n, sum = 0;
	cin >> n;
	vl p(n);
	repll(i, 0, n) cin >> p[i], sum+=p[i];
	sort(all(p));
	ll val = check(p, n, 0, sum);
	cout << val << "\n";
	return 0;
}
