/*
A permutation of length N is an array of length N that contains every integer from 1 to N exactly once.

The beauty of a permutation P is defined to be the number of prefixes of P that are themselves permutations.
That is, it is the number of integers i (1 <= i <= N) such that the array [P1, P2, ..., Pi] is a permutation of length i.

You are given a permutation P of length N.

You can perform the following operation on it at most once:

Choose two integers L and R such that 1 <= L < R <= N, and L and R have different parities. That is, if L is odd then R should be even, and vice versa.

Then, for each i = L, L+2, L+4, ..., R-1, swap P[i] with P[i+1].

In simpler words, you can choose a subarray of P that has even length, break it into blocks of size 2, and swap the two elements inside each block.

Example:
If P = [3, 1, 5, 2, 6, 4] and you choose L = 2 and R = 5, the new permutation becomes
P = [3, 5, 1, 6, 2, 4].

The beauty of a permutation P is the number of prefixes of P that are themselves permutations.
Formally, it is the count of integers i (1 <= i <= N) such that the prefix [P[1], P[2], ..., P[i]] is a permutation of size i.

Your task:
Find the maximum possible beauty of P after performing at most one such operation.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n ;
        cin >> n;
        vector<int>arr(n+1);
        for(int i = 1; i <= n; i++) cin >> arr[i];
        // Stores maximum value when swapped odd or even index. Initially 0
        long long countAfterSwap[] = {0, 0};
        long long cur_sum = 0, max_diff_on_swap = 0, ans = 0;
        for(int i = 1; i <= n ; i++)  {
            cur_sum += arr[i];
            long long sum_till_i = 1LL * i * (i + 1) / 2;
            if (cur_sum == sum_till_i) {
                // A given prefix is valid permutaion when sum of elements = (i * (i+1) / 2)
                ans++;
            }
            
            if (i < n) {
                bool withOutSwap = (cur_sum == sum_till_i);
                bool withSwap = ((cur_sum - arr[i] + arr[i+1]) == sum_till_i); // When swapped i with i+1 element
                /*
                    At given i,
                        1. we can continue the swap, i.e., prev countAfterSwap + withSwap - withOutSwap as when swapping, till i permutation is lost and arr[i+1] is added.
                        2. We can break the loop coming previously i.e., 0
                */
                countAfterSwap[i%2] = max({0LL, countAfterSwap[i%2] + withSwap - withOutSwap}); 
                max_diff_on_swap = max(max_diff_on_swap, countAfterSwap[i%2]); // Storing the maximum diff on swapping
            }
        }
        cout << ans + max_diff_on_swap << endl; 
        
    }
}
