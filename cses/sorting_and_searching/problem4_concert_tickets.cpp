#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;
int main() {
        ll n, m, i, j, p, x;
        cin >> n >> m;
        // If we use vector then we need to sort it for applying lower_bound, but sorting will give tle. So, we are using
        // multiset where the insertion of each element happens in log(n) time
        multiset<ll, greater<ll>> h;
        for(ll i = 0; i < n; i++) cin >> x, h.insert(x);
        for(i = 0; i < m; i++) {
                cin >> p;
                auto it = h.lower_bound(p); // lower_bound on an non-increasing sequence returns value <= p
                if(it != h.end()) {
                        cout << *it << "\n";
                        h.erase(it);
                }
                else cout << "-1\n";

        }

        return 0;
}