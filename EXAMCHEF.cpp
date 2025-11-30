#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
	    int X, Y, Z;
	    cin >> X >> Y >> Z;
	    int total_students = X * Y;
	    cout << ((2* Z > total_students) ? "Yes\n" : "No\n");
	}

}
