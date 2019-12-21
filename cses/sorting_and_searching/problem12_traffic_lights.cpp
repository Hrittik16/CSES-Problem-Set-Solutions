#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repll(i, a, b) for(ll i = a; i < b; i++)
#define all(x) x.begin(),x.end()
 
int main() {
    ll n, x, p;
    cin >> x >> n;
    set<ll> a;
    a.insert(0);
    a.insert(x);
    map< ll, ll, greater<ll> > mp2;
    mp2[x] = 1;
    repll(i, 0, n) {
        cin >> p;
        auto it1 = a.lower_bound(p);
        it1--;
        auto it2 = a.upper_bound(p);
	        mp2[*it2 - *it1]--;
        if(mp2[*it2 - *it1] == 0)
            mp2.erase(*it2 - *it1);
        mp2[p - *it1]++;
        mp2[*it2 - p]++;
        auto d = mp2.begin();
        cout << d->first << " ";
        a.insert(p);
        
    }
    cout << "\n";
    
    
    return 0;
}
