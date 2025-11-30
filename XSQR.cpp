/*

Problem credits: https://www.codechef.com/problems/XSQR

Solution: Since every element is unique, we can directly count a[i] ^ a[j]
and get nc2 of it. As those 2 pairs can be shuffled and pairs inside each can be shuffled, we needed to multiply by 8
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++) cin >> v[i];
        
        int ans = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += mp[v[i] ^ v[j]]++;
            }
        }

        cout << ans * 8LL << endl;
    }
}
