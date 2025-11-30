/*
Problem credits: https://www.codechef.com/problems/SUBSCRIBE_
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int N, X;
	    cin >> N >> X;
	    cout  << ((N/6) + (N%6 != 0)) * X << endl;
	}
}
