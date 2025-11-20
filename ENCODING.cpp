/*

Chef is trying to open the oven in his kitchen to cook some cookies. However, the oven is special ― you need a password to open it.

Let's define a function f(x) for a positive integer x as follows:

Consider the decimal representation of x (without leading zeros). Split it into the minimum number of contiguous subsequences of digits such that in each subsequence, all digits are identical.

For each subsequence, look at its position in the original decimal representation of x. Let's say that the most significant digit it contained was the 
e-th digit, where e=0 corresponds to the least significant digit of x. 
For example, 388,822,442 can be split into subsequences "3", "888", "22", "44", "2", where 
e=7 for the sequence "888" and e=4 for the sequence "22".

The value of a subsequence which contains a digit d repeated one or more times is d.10^e.

f(x) is the sum of values of these subsequences. For example, 
f(388,822,442)=3.10^8 +8.10^7+2.10^4+4.10^2+2.10^0.

The oven has a screen which displays two long integers L and R (with NL and NR  digits respectively, without leading zeros). The password is the sum of 
f(x) for each x between L and R inclusive.

Chef does not have a lot of time, so he asks for your help. Please find the password for the oven so that he can start cooking as fast as possible. Since this number could be very large, compute it modulo 10^9+7.

#Digit_DP
*/
/*
Solution:
Basic Digit DP.

if current element != previous element, then element * 10^(n-1) * (No.of elements with given suffix)
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

ll dp[100001][11][2];
ll contrib_dp[100001];
ll pow10[100001];

// returns how many numbers can be formed for the next n digits, respecting tight bound.
ll contribution(int n, bool tight, string& s) {
    if (tight == false) return pow10[n]; // if it is not tight, we are free to pick any digit in n places
    if (n == 0) return 1;
    if (contrib_dp[n] != -1) return contrib_dp[n];
    ll cnt = 0;
    int last_digit = s[s.size() - n] - '0';
    for(int digit = 0; digit <= last_digit; digit++) {
        cnt = (cnt + contribution(n - 1, digit == last_digit, s)) % MOD;
    }
    return contrib_dp[n] = cnt;
}

ll helper(int n, int last_ele, bool tight, string& s) {
    if(n == 0) return 0;
    if (dp[n][last_ele][tight] != -1) return dp[n][last_ele][tight];
    ll ans = 0;
    int last_digit = tight ? s[s.size() - n] - '0' : 9;
    for(int i = 0; i <= last_digit; i++) {
        bool new_tight = tight && (i == last_digit);
        if (i != last_ele) {
            ll contribtn = i * pow10[n-1] * contribution(n -1, new_tight, s);
            ans = (ans + contribtn)  % MOD;
        }
        ans = (ans + helper(n - 1, i, new_tight, s)) % MOD;
       
    }
    return dp[n][last_ele][tight] = ans;
}

int main() {
    pow10[0] = 1;
    for(int i = 1; i < 100001; i++)
        pow10[i] = pow10[i-1] * 10 % MOD;
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
	    int nl, nr;
	    string l, r;
	    cin >> nl >> l >> nr >> r;
	    memset(dp, -1, sizeof(dp));
	    memset(contrib_dp, -1, sizeof(contrib_dp));
	    ll ans = helper(nr, 10, true, r);
	    int i = l.size() - 1;
	    while(l[i] == '0') {
            l[i] = '9';
            i--;
        }
	    l[i]--;
	    memset(dp, -1, sizeof(dp));
	    memset(contrib_dp, -1, sizeof(contrib_dp));
	    cout << (ans - helper(nl, 10, true, l) + MOD) % MOD << endl;
	}
}