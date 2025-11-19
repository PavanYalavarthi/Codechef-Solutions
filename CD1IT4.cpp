/*
Problem credits: https://www.codechef.com/problems/CD1IT4

A robot is designed to move on a rectangular grid of M rows and N columns. The robot is initially positioned at (1, 1), i.e., the top-left cell. The robot has to reach the (M, N) grid cell. In a single step, robot can move only to the cells to its immediate east and south directions. That means if the robot is currently at (i, j), it can move to either (i + 1, j) or (i, j + 1) cell, provided the robot does not leave the grid.

Now somebody has placed several obstacles in random positions on the grid, through which the robot cannot pass. Given the positions of the blocked cells, your task is to count the number of paths that the robot can take to move from (1, 1) to (M, N).

Since the answer can get very large, output the answer modulo 1000000007.

Input
The first line contains 3 integers M, N and P denoting the number of rows, number of columns and number of blocked cells respectively.
In the next P lines, each line has exactly 2 integers i and j denoting that the cell (i, j) is blocked.

Output
Output should contain a single integer, the number of paths modulo 1000000007.

Constraints
1 <= M, N <= 10^3
0 <= P <= M * N
1 <= i <= M
1 <= j <= N
Example
Input
4 3 2
3 3
3 1
Output
2


Explanation
The only 2 possible paths are
(1, 1) -> (1, 2) -> (2, 2) -> (3, 2) -> (4, 2) -> (4, 3) and
(1, 1) -> (2, 1) -> (2, 2) -> (3, 2) -> (4, 2) -> (4, 3)

#dp
*/

/*
Solution:
dp[i][j] = dp[i-1][j] + dp[i][j-1]
*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int M, N, P;
    cin >> M >> N >> P;
    vector<vector<int>>dp(M + 1, vector<int>(N + 1, 0));
    while(P--) {
        int i, j;
        cin >> i >> j;
        dp[i][j] = -1;
    }
    if(dp[1][1] == -1 || dp[M][N] == -1) {
        dp[M][N] = 0;
    } else {
        dp[1][1] = 1;
        for(int i =1; i <= M; i++) {
            for(int j =1; j<= N;j++) {
                if (i ==1 and j ==1) continue;
                if (dp[i][j] == -1) dp[i][j] = 0;
                else if (j == 1) dp[i][1] = dp[i-1][1];
                else if(i == 1) dp[1][j] = dp[1][j-1];
                else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    cout << dp[M][N];
    return 0;
}
