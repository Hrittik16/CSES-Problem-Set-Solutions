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
        ll n;
        cin >> n;
        vl a(n);
        repll(i, 0, n) a[i] = i+1;

        if(n == 1) cout << "1\n";
        else if(n < 4) cout << "NO SOLUTION\n";
        else if(n == 4) cout << "2 4 1 3\n";
        else {
                for(ll i = 0; i < n; i+=2) {
                        cout << a[i] << " ";
                }
                for(ll i = 1; i < n; i += 2) {
                        cout << a[i] << " ";
                }
                cout << "\n";
        }





        return 0;
}