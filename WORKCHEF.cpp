/*
Problem credits: https://www.codechef.com/problems/WORKCHEF/

Chef's team is going to participate in the legendary math battles. This time the main task of the competition is to calculate number of K-special numbers in the range [L, R] (i.e. L, L + 1, L + 2, ..., R).

A number X is said to be K-special if there exist K or more different digits, such that X is divisible by those digits and those digits are present in the decimal representation of the number. For example, number 48 is both 1 and 2 special, as it is divisible by digits 4 and 8. Note that no positive integer is divisible by number 0.

Chef asked you to help him with this task. There will be Q questions of forms L, R, K. For each of these questions, you have to tell How many K-special numbers are the range [L, R] ?".

Input
First line of the input contains an integer Q that denotes number of questions Chef was asked.

In the next Q lines follow the questions, i-th of the line will denote the i-th question represented by three space separated integer L, R, K respectively.

Output
For each question, output an integer in a separate line containing the answer of the question.

#Digit_DP

*/

/*
Solution: As we needed to find number is divisible by digits, using number % 2520 (as it is LCM of digits 1-9)

And rest is standard digit DP template
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 2520
int k;
ll dp[20][2520][1 << 9][2]; //2520 as it is LCM of digits 1-9
ll helper(int pos, int modM, int mask, bool tight, const string & s) {
    if (dp[pos][modM][mask][tight] != -1) return dp[pos][modM][mask][tight];
    if(pos == s.size()) {
        int cnt = 0;
        for(int i = 1; i <= 9; i++) {
            if (mask & (1 << (i-1)) && modM % i == 0) 
                cnt++;
        }
        return dp[pos][modM][mask][tight] = (cnt >= k);
    } else {
        int last_digit = tight ? s[pos] - '0' : 9;
        int res = 0;
        for (int i = 0; i <= last_digit; i++) {
            if (i == 0)  //skipping zeros
                res += helper(pos + 1, (modM * 10) % MOD, mask, tight && (i == last_digit), s);
            else
                res += helper(pos+1, (modM * 10 + i) % MOD, mask | (1 << (i-1)), tight && (i == last_digit), s);
        }
        return dp[pos][modM][mask][tight] = res;
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q;
    cin >> Q;
    while(Q--) {
        ll l, r;
        cin >> l >> r >> k;
        memset(dp, -1, sizeof(dp));
        ll ans = helper(0, 0, 0, true, to_string(r));
        memset(dp, -1, sizeof(dp));
        cout << ans - helper(0, 0, 0, true, to_string(l-1)) << endl;
    }
}
