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

        ll t, y, x;
        cin >> t;
        while(t--) {
                cin >> y >> x;
                if(y == 1 && x == 1) cout << "1\n";
                else {
                        ll mx = max(y, x);
                        ll s = ((mx-1)*(mx-1))+1;
                        if(x > y && mx%2 != 0)
                                cout << s+(2*mx)-2-(y-1) << "\n";
                        else if(x > y && mx%2 == 0)
                                cout << s+(y-1) << "\n";
                        else if(y > x && mx%2 != 0)
                                cout << s+(x-1) << "\n";
                        else
                                cout << s+(2*mx)-2-(x-1) << "\n";
                }

        }


        return 0;
}