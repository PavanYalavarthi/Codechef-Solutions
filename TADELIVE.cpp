/*
Andy and Bob are the only two delivery men of Pizza-chef store. Today, the store received N orders. It's known that the amount of tips may be different when handled by different delivery man. More specifically, if Andy takes the ith order, he would be tipped Ai dollars and if Bob takes this order, the tip would be Bi dollars.

They decided that they would distribute the orders among themselves to maximize the total tip money. One order will be handled by only one person. Also, due to time constraints Andy cannot take more than X orders and Bob cannot take more than Y orders. It is guaranteed that X + Y is greater than or equal to N, which means that all the orders can be handled by either Andy or Bob.

Please find out the maximum possible amount of total tip money after processing all the orders.

SOlution: get greedy on a - b

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<int>a(n), b(n), diff(n);
	int sum = 0;
	for(int i = 0; i < n; i++) {
	    cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
	    cin >> b[i];
	    sum += b[i]; // Adding all bs, such that when add cummulative (a-b), automatically cancelled
	    diff[i] = a[i] - b[i];
	}
	sort(diff.begin(), diff.end(), greater<int>());
	vector<int>prefixSum(n+1);
	prefixSum[0] = 0;
	for(int i =1; i <= n; i++) {
	    prefixSum[i] = prefixSum[i-1] + diff[i-1];
	}
	int ans = 0;
	for(int i = 0; i <= n; i++) {
	    if (i <= x && (n-i)<=y) {
	        ans = max(ans, sum + prefixSum[i]);
	    }
	}
	cout << ans;
}
