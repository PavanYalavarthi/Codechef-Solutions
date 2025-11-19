/*

Problem credits: https://www.codechef.com/COOK36/problems/TACHSTCK


Actually, the two sticks in a pair of chopsticks need not be of the same length. A pair of sticks can be used to eat as long as the difference in their length is at most D. The Chef has N sticks in which the ith stick is L[i] units long. A stick can't be part of more than one pair of chopsticks. Help the Chef in pairing up the sticks to form the maximum number of usable pairs of chopsticks.

Input
The first line contains two space-separated integers N and D. The next N lines contain one integer each, the ith line giving the value of L[i].

Output
Output a single line containing the maximum number of pairs of chopsticks the Chef can form.

Constraints
1 ≤ N ≤ 100,000 (105)
0 ≤ D ≤ 1,000,000,000 (109)
1 ≤ L[i] ≤ 1,000,000,000 (109) for all integers i from 1 to N

#greedy
*/
/*
    Solution: use greedy. Sort the sizes and group adjancent chopsticks when their sizes difference is atmost D
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int>L(N);
    for(int i = 0; i < N; i++) {
        cin >> L[i];
    }
    sort(L.begin(), L.end());
    int ans= 0;
    for(int i = 1; i < N; i++) {
        if (L[i] - L[i-1] <= D) {
            ans++;
            i++;
        }
    }
    cout << ans;
}
