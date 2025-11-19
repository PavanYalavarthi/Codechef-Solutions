/*
Problem credits: https://www.codechef.com/problems/SRTX16B

large fibonacci

Rajesh is a very brilliant student. He likes sequences a lot specially the fibonacci sequence.
The fibonacci sequence is shown below
1 1 2 3 5 8 ...
Today Rajesh friend Saket gave him a problem on fibonacci sequences.

The problem is to find the N'th fibonacci number given N.
As this number can be very very large, Saket just need the n'th fibonacci number MOD 1000000007.

Since Rajesh is a genious at fibonacci sequences, he considers this as a pretty easy problem and asks you to solve it as he is feeling sleepy.


Can you solve the problem before Rajesh wakes up.

Hint: Recall the matrix form of the fibonacci numbers.


Input
First line of the input contains an integer T, denoting the number of inputs.
T lines follow each containing an integer N


Output
Output the N'th fibonacci number MOD 1000000007 in a newline


Constraints and Subtasks
Should contain all the constraints on the input data that you may have. Format it like:

Subtask 1: 1 points
1 ≤ T ≤ 10
1 ≤ N ≤ 20

Subtask 2: 29 points
1 ≤ T ≤ 1000
1 ≤ N ≤ 100000

Subtask 3: 70 points
1 ≤ T ≤ 100000
1 ≤ N ≤ 1000000000

Example
Input:
3
3
4
5
Output:
2
3
5


Explanation
Example case 1. The fibonacci numbers corresponding to the 2nd, 3rd, 4th term is 1, 2, 3 respectively

#Fibonacci
*/

/*

Solution:

Fast fibonacci, refer function f() for formula

*/
#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

unordered_map<int, long long> F;

long f(long n) {
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}

int main() {
    F[0] = F[1] = 1;
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    cout << f(n-1) << endl;
	}
}
