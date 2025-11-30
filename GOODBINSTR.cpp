/*
    If s[0] == s.back(), then its always good string else its 1 less.

    if you flip internal nodes, it stays good string only

    when you flip extremes, it will result in -1 differnce.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    cin >> s;
	    if (s[0] == s.back())
	        cout << "2\n";
	    else
	        cout << (s.size() - 2) << endl;
	}
}
