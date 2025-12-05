/*

You are given an array A consisting of N non-negative integers.
It is guaranteed that A contains at least two distinct elements.
You are also given a non-negative integer X.
For each Y (0 <= Y <= X), we create an array B of size N such that B; = Ai Y, where denotes the bitwise OR operation.
Find the largest integer Y (Y <= X) such that the array B contains at least two distinct elements.
*/

class Solution {
public:
    int maximizeXor(vector<int>& a, int x) {
        int bitOr = 0, bitAnd = ~0;
        for(int ai: a) {
            bitOr |= ai;
            bitAnd &= ai;
        }
        int maskXor = bitOr ^ bitAnd;
        if((maskXor & x) != maskXor) return x;
        int ans = 0;
        for(int i = 30; i >= 0; i--) {
            int bit_mask = (1 << i);
            if((x & bit_mask) && (maskXor & bit_mask)) {
                int higherBits = x & (~((bit_mask << 1) - 1));
                int lowerBits = bit_mask - 1;
                ans = max(ans, higherBits | lowerBits);
            }
        }
        return ans;
    }
};
