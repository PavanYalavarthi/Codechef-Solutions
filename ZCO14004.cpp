/*
Problem credits: https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO14004

Zonal Computing Olympiad 2014, 30 Nov 2013

In IPL 2025, the amount that each player is paid varies from match to match. The match fee depends on the quality of opposition, the venue etc.


The match fees for each match in the new season have been announced in advance. Each team has to enforce a mandatory rotation policy so that no player ever plays three matches in a row during the season.


Nikhil is the captain and chooses the team for each match. He wants to allocate a playing schedule for himself to maximize his earnings through match fees during the season.


Input format
Line 1: A single integer N, the number of games in the IPL season.

Line 2: N non-negative integers, where the integer in position i represents the fee for match i.


Output format
The output consists of a single non-negative integer, the maximum amount of money that Nikhil can earn during this IPL season.

#Dp

*/

/*

Solution: 

This is complement to codechef SUPW problem. So, total - (SUPW problem solution)

dp[i] = minimum fee he must skip ith match to ensure no 3 played matches skipped in a row.

So, as ith match is skipped dp[i] is the fee and it cant be he skipped pat three matches, we needed to add min(dp[i-1], dp[i-2], dp[i-3])

Now total - dp[n]
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, sum =0;
    cin >> n;
    vector<int>dp(n+1);
    for(int i = 0; i < n; i++) {
        cin >> dp[i];
        sum += dp[i];
    }
    dp[n] = 0;
    for(int i = 3; i<=n;i++) {
        dp[i] += min({dp[i-1], dp[i-2], dp[i-3]});
    }
    cout << sum - dp[n];
    return 0;

}
