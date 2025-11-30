/*
Problem credits: https://www.codechef.com/problems/AVGPROBLEM

SOlution: Self explainatory
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    int A, B, C;
	    cin >>A >> B >> C;
	    cout << 
	    ((((A + B) / 2.0) > C) ? "YES\n" : "NO\n");
	}
	return 0;
}
