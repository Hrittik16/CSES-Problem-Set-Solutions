#include <bits/stdc++.h>
using namespace std;
int main() {
        string s;
        cin >> s;
        int len = 1, mx = 1, s_len;
        s_len = s.length();
        for(int i = 1; i < s_len; i++) {
                if(s[i] == s[i-1]) len++;
                else len = 1;
                mx = max(mx, len);
        }
        cout << mx << "\n";


        return 0;
}