/*
For encoding an even-length binary string into a sequence of A, T, C, and G, we iterate from left to right and replace the characters as follows:
00 is replaced with A
. 01 is replaced with T
. 10 is replaced with C
. 11 is replaced with G
Given a binary string S of length N (N is even), find the encoded sequence.
Function Description:
You are given a function named decodeDNA that you must complete.
The function receives the following parameters:
. n - an integer representing the length of the binary string (always even)
. s - a binary string of length n, containing only '0' and '1'
The function must return the resulting encoded string after converting all binary pairs using the above rules.
The input and output formats given below are only if you want to test using custom inputs.
Constraints:
. 1 <= T <= 100
. 2 <= N<= 10^3
. N is even.
. Sum of N over all test cases is at most 10^3

*/

class Solution {
    
public:
    string decodeDNA(int n, const string &s) {
        string ans;
        for(int i = 0; i < n; i+=2) {
            int val = (s[i] - '0')* 10 + (s[i+1] - '0');
            if(val == 0) {
                ans += "A";
            } else if (val == 1) {
                ans += "T";
            } else if(val == 10) {
                ans += "C";
            } else {
                ans += "G";
            }
        }
        return ans;
    }
};
