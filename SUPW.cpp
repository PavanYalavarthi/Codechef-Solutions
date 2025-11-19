/*
Problem Credits: https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO14002

Zonal Computing Olympiad 2014, 30 Nov 2013

In ICO School, all students have to participate regularly in SUPW. There is a different SUPW activity each day, and each activity has its own duration. The SUPW schedule for the next term has been announced, including information about the number of minutes taken by each activity.


Nikhil has been designated SUPW coordinator. His task is to assign SUPW duties to students, including himself. The school's rules say that no student can go three days in a row without any SUPW duty.


Nikhil wants to find an assignment of SUPW duty for himself that minimizes the number of minutes he spends overall on SUPW.


Input format
Line 1: A single integer N, the number of days in the future for which SUPW data is available.

Line 2: N non-negative integers, where the integer in position i represents the number of minutes required for SUPW work on day i.


Output format
The output consists of a single non-negative integer, the minimum number of minutes that Nikhil needs to spend on SUPW duties this term

#dp

*/

/*
Solution:


dp[i] = minimum minutes he must work on wokring ith match to ensure no 3 played matches skipped in a row.

So, as ith activity is done dp[i] is the minutes and it cant be he skipped all three consective activities, we needed to add min(dp[i-1], dp[i-2], dp[i-3])

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>dp(n);
    for(int & i: dp) {
        cin >> i;
    }
    dp.push_back(0);
    for(int i = 3; i <= n ; i++) {
        dp[i] += min(dp[i-1], min(dp[i-2], dp[i-3]));
    }
    cout << dp[n];
    return 0;
}