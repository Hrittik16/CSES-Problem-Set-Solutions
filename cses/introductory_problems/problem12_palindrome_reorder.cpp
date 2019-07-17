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
int main() {
	
	string s;
	cin >> s;
	map<char, ll> mp;
	for(auto x: s) mp[x]++;
	ll count = 0;
	for(auto x: mp) {
		if(x.second%2 != 0) count++;
	}

	if(count > 1) cout << "NO SOLUTION\n";
	else if(s.length() == 1) cout << s << "\n";
	else {
		ll fre = 0;
		char ch = ' ';
		string str;
		for(auto x: mp) {
			if(x.second%2 == 0) {
				repll(i, 0, x.second/2) str += x.first;
			}
			else {
				ch = x.first;
				fre = x.second;
			}
		}
		if(ch != ' ') {
			repll(i, 0, fre)
				str += ch;
		}
		string sstr;
		if(ch != ' ')
			for(ll i = str.length()-1-fre; i >= 0; i--) sstr += str[i];
		else
			for(ll i = str.length()-1; i >= 0; i--) sstr += str[i];
		str += sstr;
		cout << str;
		cout << "\n";
	}


	return 0;
}
