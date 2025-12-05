#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int r, b, g;
	    cin >> r >> b >> g;
	    int mn = min({r, b, g});
	    cout << mn * 10 + 3 * (r + b + g - 3 * mn) << endl;
	}
}