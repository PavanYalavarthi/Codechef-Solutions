/*
Problem credits: https://www.codechef.com/problems/INCXOR/ 

You are given a sequence of n integers a1, ..., an. Count the number of sequences b = b1, ..., bn such that: 0 ≤ b1 ≤ ... ≤ bn < 2^31 and (a1 XOR b1) ≤ … ≤ (an XOR bn). Return this count, modulo 10^9+7.

Here XOR denotes the bitwise XOR.

Input
The first line of input will contain an integer T, the number of test cases.

Each test case will be in two lines.

The first line of the case will contain an integer n.

The next line of the case will contain n space separated integers a1,...,an.

Output
Output a single number, the number of sequences, modulo 10^9+7.

#Bit_mask_dp

*/

/*

Solution:
Each bi is a 31-bit number, so instead of choosing bi entirely, we build them bit-by-bit from the most significant bit (bit 30) down to least significant bit (bit 0).

At EACH bit position, for EACH bi: bBit[i] = the value of the current bit (0 or 1) that you assign to bi. So, xorBit[i] = ((arr[i] >> bit) & 1) ^ bBit[i];

Because numbers are compared bit-by-bit starting from the most significant bit.

Meaning:

If at the CURRENT bit, bBit[i] < bBit[i+1] then we know
bi < bi+1 forever — order is FIXED.

If at the CURRENT bit, bBit[i] > bBit[i+1],
bi > bi+1 → ordering is violated → invalid assignment.

If they are equal,
bBit[i] == bBit[i+1],
the ordering of bi and bi+1 is NOT yet known. We must wait for lower bits.

bMask[i] = 1 means: The ordering between bi and bi+1 is ALREADY decided in a previous bit.

bMask[i] = 0 means: Order between bi and bi+1 is STILL UNKNOWN — depends on lower bits.

Same meaning for xorMask.


*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int n;
vector<int> arr;
ll dp[31][1 << 4][1 << 4];
ll helper(int bit, int bMask, int xorMask) {
    if (bit < 0) return 1;
    ll& ans = dp[bit][bMask][xorMask];
    if (ans != -1) return ans;
    ans = 0;
    // Try all combinations at bit
    for(int assign = 0; assign < (1 << n); assign++) {
        vector<int>bBit(n), xorBit(n);
        for(int i = 0; i<n; i++) {
            bBit[i] = (assign >> i) & 1;
            xorBit[i] = ((arr[i] >> bit) & 1) ^ bBit[i];
        }
        bool ok = true;
        int newBMask = bMask, newXorMask = xorMask;
        for(int i = 0; i < n -1; i++) {
            // If the order is not set in previous iteartion
            if ((bMask & (1 << i)) == 0) {
                if(bBit[i] > bBit[i +1]) {
                    // If i is bigger than i + 1, then its not proper order
                    ok = false;
                    break;
                }
                if (bBit[i] < bBit[ i + 1]) newBMask |= (1 << i); // if order is set, then setting respective bit
            }
            if ((xorMask & (1 << i)) == 0) {
                if(xorBit[i] > xorBit[i +1]) {
                    ok = false;
                    break;
                }
                if (xorBit[i] < xorBit[ i + 1]) newXorMask |= (1 << i);
            }
        }
        if(ok) {
            ans += helper(bit - 1, newBMask, newXorMask);
            if (ans >= MOD) ans -= MOD;
        }
    }
    return ans;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        memset(dp, -1, sizeof(dp));
        cout << helper(30, 0, 0) << '\n';
    }
    return 0;
}