/*

For an array A containing non-negative integers, we define f(A) as follows:

First, for each index i such that A[i] = 0, replace A[i] by an arbitrary positive integer of your choice.

Then, calculate the number of pairs (i, j) such that i < j and A[i] = A[j].
That is, the number of pairs of distinct indices that contain the same value.

Let this value be P.

f(A) is the maximum possible value of P if you choose the replacements of the zeros appropriately.

*/

/*

Solution:

We need to replace 0 with maximum freq element. So maintain freq map and keep adding #pairs possible with other elements.

Add freq of 0 to max freq to make result maximum

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        unordered_map<int, int>mp;
        for(int i = 0, ele; i < n; i++) {
            cin >> ele;
            mp[ele]++;
        }
        int max_freq = 0, ans = 0;
        for(auto& [ele, freq]: mp) {
            if (ele == 0) continue;
            if (freq > max_freq) {
                ans += max_freq * (max_freq - 1) / 2; // Addinh prev max freq
                max_freq = freq;
            } else {
                ans += freq * (freq - 1) / 2;
            }
        }
        // make 0 to maximum frequent ele so that the ans can be maximized
        max_freq += mp[0]; // Adding freq of zero as zeros will be changes to max freq ele
        cout << ans + max_freq * (max_freq - 1) / 2 << endl;
    }
}