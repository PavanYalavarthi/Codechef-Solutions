/*

We call a binary array B of size M "winning" if it can be converted to the array [1, 1, ..., 1] by repeating the following operation a finite number of times:

Pick 1 <= L <= R <= M such that the number of 1's in the subarray B[L, R] is strictly greater than the number of 0's in it.
Then, replace B[i] with 1 for all L <= i <= R.

Given an array A of size N, count the number of winning subarrays of A.

*/

/*
Solution:

All subarrays with size 1 and value 1 is good sub array

if we have 11 inside subarray, it will convert the rest into good subarray

or even if subarray have 101 , it can be converted to good subarray.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        long long ans = 0;
        for(int i =0; i<n; i++) {
            cin >> arr[i];
            ans += arr[i]; //counting good arrays of size 1
        }
        
        int prev = -1; //Stores prev occurance of 101 or 11 
        
        for(int i = 0; i < n ; i++) {
            if (arr[i] == 1) {
                if (i < n -1 && arr[i + 1] == 1) {
                    // On 11 as subtring
                    int leftOptions = (i - prev); // Picking L from prev + 1 to i
                    int rightOptions = (n - 1 - i); // Picking R from i + 1 to n-1 keeping 11 inside subarray
                    ans += 1LL * leftOptions * rightOptions;
                    prev = i;
                } else if (i < n - 2 && arr[i+2] == 1) {
                    //On 101 as substring
                    int leftOptions = (i - prev); // Picking L from prev + 1 to i
                    int rightOptions = (n - 1 - (i + 1)); // Picking R from i + 2 to n - i, keeping 101 inside subarray
                    ans += 1LL * leftOptions * rightOptions;
                    prev = i;
                }
            }
        }
        cout << ans << endl;
    }
}
