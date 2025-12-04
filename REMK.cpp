/*

You are given an array A of size N, and an integer K (K >= 2).

For any array B of size M (M >= 2), define:

f(B) = sum from i = 1 to M-1 of (B[i] + B[i+1]).

You must choose a subsequence C of array A such that the size of C is exactly K.

Your task is to find the maximum possible value of f(C).

*/


/*
Pick first and last occurance, and store freq.

Now, select all combinations with start (1..50) and end(1..50) and pick top k-2 elements in between and multiply them by 2

now ans is max value of start + end+ 2*(sum of top k-2 elements)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int>firstOccurance(51, -1), lastOccurance(51, -1);
        vector<vector<int>> freq(51, vector<int>(n+1, 0));
        for(int i = 1, ele; i <= n; i++) {
            cin >> ele;
            if (firstOccurance[ele] == -1) firstOccurance[ele] = i;
            lastOccurance[ele] = i;
            freq[ele][i] = 1;
        }
        
        for(int ele = 1; ele <= 50; ele++) {
            for(int i = 2; i <= n; i++) {
                freq[ele][i] += freq[ele][i-1];
            }
        }
        int ans = 0;
        for(int start = 1; start <= 50; start++) {
            for(int end = 1; end <= 50; end++) {
                int startIdx = firstOccurance[start], endIdx = lastOccurance[end];
                if(startIdx == -1 || endIdx == -1 || endIdx - startIdx < k - 1)
                    continue;
                int req_element_count = k - 2, sum = start + end;
                for(int mid = 50; mid >= 1; mid--) {
                    int count = freq[mid][endIdx-1] - freq[mid][startIdx];
                    if (count >= req_element_count) {
                        sum += 2*req_element_count* mid;
                        ans = max(ans, sum);
                        break;
                    } else {
                        sum += 2 * count * mid;
                        req_element_count -=count;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
