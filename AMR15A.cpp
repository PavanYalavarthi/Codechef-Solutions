#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	int ans = 0, ele;
	while(n--) {
	    cin >> ele;
	    ans += (ele % 2 == 0) ? 1 : -1;
	}
	cout << (ans > 0 ? "READY FOR BATTLE" : "NOT READY");

}
