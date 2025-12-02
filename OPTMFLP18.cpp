/*
You are given an array A of length N.
You are allowed to perform the following operation on it at most once:

Choose an element Ai and change it to Ai +1
Find the maximum count of subarrays having at least one even element after performing the operation at most once.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long ans = 1LL* n * (n + 1) / 2;
        int max_odd_sz = 0, odd_sz = 0;
        for(int i = 0, ele; i < n; i++) {
            cin >> ele;
            if (ele & 1) {
                odd_sz++;
                max_odd_sz = max(max_odd_sz, odd_sz);
                ans -= odd_sz; //Subtarcting subarray with only odds
            } else {
                odd_sz = 0;
            }
        }
        long long left, right;
        //Placing odd at middle of biggest sequence and adding #subarrays containing even
        if (max_odd_sz % 2 == 1) {
            right = left = max_odd_sz / 2 + 1;
        } else {
            left = max_odd_sz / 2, right = left + 1;
        }
        ans += left * right;
        cout << ans << endl;
    }
    
}
