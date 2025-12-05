#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, k;
	    cin >> n >> k;
	    string s;
	    cin >> s;
	    int count1 = 0, count0 = 0;
	    vector<int>freq(k, 0);
	    for(int i = 0; i < n; i++) {
	        char c = s[i];
	        if (c == '0') count0++;
	        else count1++;
	        freq[i%k]++;
	    }
	    int needed = 0;
	    for(int i: freq) {
	        needed += (i+1) / 2;
	    }
	    if (count1 <= needed && count0 <= needed) {
	        cout << "YES\n";
	    } else {
	        cout << "NO\n";
	    }
	}
}