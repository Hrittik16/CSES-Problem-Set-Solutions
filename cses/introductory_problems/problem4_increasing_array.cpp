#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector< vi >
#define vvl vector< vl >
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repll(i, a, b) for(ll i = a; i < b; i++)
#define all(a) a.begin(),a.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector< pii >
#define vpll vector< pll >
#define F first
#define S second
#define pb push_back

int main() {
        ll n, sum = 0;
        cin >> n;
        vl a(n);
        repll(i, 0, n) cin >> a[i];
        rep(i, 1, n) {
                if(a[i] < a[i-1]) {
                        sum += abs(a[i]-a[i-1]);
                        a[i] = a[i-1];
                }
        }
        cout << sum << "\n";


        return 0;
}