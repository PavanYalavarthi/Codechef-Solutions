/*
You are given an array A of length N containing only the integers 1, 2, and 3.
It is guaranteed that each of 1, 2, and 3 appears at least once in A.

You perform exactly one operation on A:

Step 1: Choose two integers L and R such that 1 <= L <= R <= N.
Step 2: For every index i from L to R:

If A[i] = 1, replace it with 2.

If A[i] = 2, replace it with 3.

If A[i] = 3, replace it with 1.

In other words, you choose a non-empty subarray A[L..R] and add 1 to all its values, with 3 turning into 1.

Example:
If A = [3,1,1,2,3,2]

If you choose L = 3, R = 6, the resulting array becomes:
[3,1,2,3,1,3]

If you choose L = 2, R = 4, the resulting array becomes:
[3,2,2,3,3,2]

Question:
In how many ways can you choose (L, R) such that after the operation, the resulting array still contains at least one 1, at least one 2, and at least one 3?

*/

/*

Solution:

#Good subararys = total - bad subarrays;

total = n * (n+1) / 2

First storing indices of each ele in vector

Now, 

Inorder to covert array such that we shouldnt have 1,

pick first and last occurance of 1, so, inorder to wipe out 1 from array, l and r should be on or outisde that window

So, 3 should not be between them. As that 3 can turn to 1 creating 1 back to array.

And, the l can be between first occurance of 1 and index just after 3, which is present to left of window. (-1, if not present)
and R can be between last occurance of 1 and index just before 3, which is present to right of window. (n, if not present)

Now, no of bad arrays with no 1 is #left_choices * #right_choices.

Apply same for 2 and 3
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int n;
        cin >> n;
        vector<vector<int>> indexList(4);
        for (int i = 0, value; i < n; i++) {
            cin >> value;
            indexList[value].push_back(i);
        }

        long long totalSubarrays = 1LL * n * (n + 1) / 2;

        for (int value = 1; value <= 3; value++) {
            int firstPos = indexList[value][0];
            int lastPos  = indexList[value].back();

            // Adjacentvalue of i is, value when increased by 1 gives i
            int adjacentValue = (value == 1) ? 3 : (value - 1);
            auto &adjPositions = indexList[adjacentValue];

            auto it = upper_bound(adjPositions.begin(), adjPositions.end(), firstPos);

            int nearestAdjLeft  = (it != adjPositions.begin()) ? *(it - 1) : -1;
            int nearestAdjRight = (it != adjPositions.end())  ? *it : n;

            // If adjacent value is between first and last position
            if (nearestAdjRight < lastPos) {
                continue;
            }

            long long leftChoices  = firstPos - nearestAdjLeft;
            long long rightChoices = nearestAdjRight - lastPos;

            totalSubarrays -= (leftChoices * rightChoices);
        }

        cout << totalSubarrays << "\n";
    }
}