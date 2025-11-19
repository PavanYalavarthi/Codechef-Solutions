/*

N integers A1,A2,…,AN are placed in a circle in such a way that for each valid i
Ai and Ai+1 are adjacent, and A1 and AN are also adjacent.

We want to repeat the following operation exactly N−1(until only one number remains):

Select two adjacent numbers. Let's denote them by a and b. Score a+b penalty points. Erase both a and b from the circle and insert a+b in the space between them.
What is the minimum number of penalty points we can score?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers a1,a2,…,aN.

Output
For each test case, print a single line containing one integer — the minimum number of penalty points.

Constraints
1≤T≤10
2≤N≤400
1≤ai≤10^9 for each valid i

Subtasks
Subtask #1 (10 points):
2≤N≤10
ai≤10 for each valid i

Subtask #2 (10 points):
2≤N≤25a1,a2,…,aN.  are distinct powers of 2 (including 1)


Subtask #3 (10 points): 
2≤N≤100

Subtask #4 (70 points): original constraints

Sample 1:
Input
1
3
10 10 1
Output
32
Explanation:
[10,10,1]→[10,11], penalty: 11
[10,11]→[21], penalty: 21
Total penalty: 11+21=32

#dp
*/

/*

Solution:
Its a common pattern of circular array, make prefixArray of 2*N and for every N window process it.

for every window, dp[i][j] = dp[i][k] + dp[k+1][j] + (sum of (a[i] .. a[j]))
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int helper(vector<int> & prefixSum, int i, int j, vector<vector<int>>& dp) {
    if (i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int  ans = 1e18, cost = prefixSum[j] - prefixSum[i-1];
    for(int k = i; k < j; k++) {
        ans = min(ans, helper(prefixSum, i, k, dp) + helper(prefixSum, k +1, j, dp) + cost);
    }
    return dp[i][j] = ans;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<int>v(N);
        vector<int>prefixSum(2*N + 1);
        prefixSum[0] = 0;
        for(int i = 0; i< N; i++) {
            cin >> v[i];
            prefixSum[i + 1] = prefixSum[i] + v[i]; 
        }
        for(int i = N; i < 2 * N; i++) {
            prefixSum[i + 1] = prefixSum[i] + v[i - N];
        }
        int ans = 1e18;
        vector<vector<int>>dp(prefixSum.size(), vector<int>(prefixSum.size(), -1));
        for(int i =1 ;i <= N; i++) {
            ans = min(ans, helper(prefixSum, i, i + N - 1, dp));
        }
        cout << ans << endl;
    }
    return 0;
}
