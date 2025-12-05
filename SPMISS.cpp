#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n, c;
	    cin >> n >> c;
	    vector<int>prize(n);
	    for(int i =0; i < n; i++) {
	        cin >> prize[i];
	    }
	    string s;
	    cin >> s;
	    int ans = 0, extra_ans = 0;
	    bool isPaid = false;
	    for(int i =0; i < n; i++) {
	        if (s[i] == '0') {
	            ans += prize[i];
	        } else {
	            extra_ans += prize[i];
	        }
	    }
	    if (ans >= c) {
	        ans += max(0, extra_ans - c);
	    }
	    cout << ans << endl;
	}
}