/*

For an array A containing non-negative integers, we define f(A) as follows:

First, for each index i such that A[i] = 0, replace A[i] by an arbitrary positive integer of your choice.

Then, calculate the number of pairs (i, j) such that i < j and A[i] = A[j].
That is, the number of pairs of distinct indices that contain the same value.

Let this value be P.

f(A) is the maximum possible value of P if you choose the replacements of the zeros appropriately.

You have an array A of size N, initially filled with 0's.

You have to handle the following N events:

Given X and Y, update A[X] = Y. Then, find f(A).

It is guaranteed that all N events have distinct values of X - that is, each index will be updated exactly once.

Note that when computing f(A), we don't actually replace the zeros in A: we just want to know the maximum possible value of P if we replaced the zeros appropriately.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int max_freq = 0;
        long long noOfZeros = n, total_pairs = 0;
        unordered_map<int, int>freq;
        for(int i=0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            total_pairs += freq[y]; //Given y maps to #existing y
            freq[y]++;
            max_freq = max(max_freq, freq[y]);
            noOfZeros--;
            /*
                Mapping zeros with max freq to get maximum ans.
                which is total pairs + total pairs zeros form + pick one from zero pair and other from max_freq
            */
            long long max_possible_ans = total_pairs + 1LL* noOfZeros * (noOfZeros - 1) / 2 + 1LL * noOfZeros * max_freq;
                                        
            cout << max_possible_ans << " ";
        }
        cout << '\n';
    }
}
