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

int main() {

        ll n;
        cin >> n;
        repll(i, 1, n+1) {
                if(i < 3) {
                        ll val = ((i*i)*(i*i-1))/2;   // n^2*(n^2-1)/2
                        cout << val << "\n";
                }
                else {
                        // n^2*(n^2-1)/2 - 2*2*(n-1)(n-2)
                        // 2*(n-1)(n-2) is the number of 2*3 grids(as 2*3 grids
                        // represents the L-shape move that knights make).
                        // Within each 2*3 grid the knights can take 2 different
                        // positions where they can attack each other
                        // So, total number of position such that the knights
                        // can attack each other is 4*(n-1)(n-2)

                        ll val = (((i*i)*(i*i-1))/2)-(4*(i-1)*(i-2));
                        cout << val << "\n";
                }
        }

        return 0;
}