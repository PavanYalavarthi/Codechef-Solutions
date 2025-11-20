/*
Problem credits: https://www.codechef.com/problems/AOPN

A number is said to be a palindrome if it remains the same when it is read backwards. Eg. 12021 is pallindrome while 21 is not.

A number is called total-palindromic if it contains a palindrome with odd length greater than 1 and an even palindrome as a substring.

For example, the number 22676 is total-palindromic whereas the number 101 is not because it contains the palindrome of odd length 
676 and even length 22. While 101 does not contain an even palindrome as a substring.

You are given two numbers a, b. Output the number of total-palindromic numbers which lie in the range 
(a,b] i.e set {a+1, a+2, ... b }

Input
First line contains number of test cases T. Each test case contains two lines.
First line contains the number a
Second line contains the number b
Output
T lines, each line containing an integer - the answer to the test case.

Constraints
1 <= T <= 100
99<=a<b<=10 ^ 18
 
Sample Input:
2
99
100
110
119
Sample Output:
0
1
Explanation
In second test case the range is between 110 and 119 i.e the numbers 
111, 112, 113, 114, 115, 116, 117, 118, 119. Of these only 111 contains the odd palindromic substring 111 and even palindromic substring 11.

So the answer to this test-case is 1.

#Digit_DP
*/

/*
Solution:

Digit DP template with even flag set, if current element = previous Elememnt and odd flag is set when currentElement == second previous element

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][11][11][2][2][2][2];
ll helper(int pos, int last_ele, int sec_last_ele, bool tight, bool even, bool odd, bool doesStart, string& s) {
    if (pos == s.size()) return odd && even;
    if (dp[pos][last_ele][sec_last_ele][tight][even][odd][doesStart] != -1) return dp[pos][last_ele][sec_last_ele][tight][even][odd][doesStart];
    int last_digit = tight ? s[pos] - '0' : 9;
    ll result = 0;
    for(int i = 0; i <= last_digit; i++) {
        if(!doesStart && i == 0) // skipping the leading zeros
                result += helper(pos + 1, last_ele, sec_last_ele, tight && (i == last_digit), even, odd,false , s);
        else
            result += helper(pos + 1, i, last_ele, tight && (i == last_digit), even || (i == last_ele), odd || (i == sec_last_ele), true, s);
    }
    return dp[pos][last_ele][sec_last_ele][tight][even][odd][doesStart] = result;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        memset(dp, -1, sizeof(dp));
        ll ans = helper(0, 10, 10, true, false, false, false, b);
        memset(dp, -1, sizeof(dp));
        cout << ans - helper(0, 10, 10, true, false, false, false, a) << endl;
    }
    return 0;
}