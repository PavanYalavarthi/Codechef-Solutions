#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll>a(n), b(n);
        for(int i =0; i< n; i++) cin >> a[i];
        for(int j =0; j< n; j++) cin >> b[j];
        
        vector<ll> leftMaxA(n), leftMaxB(n);
        leftMaxA[0] = a[0];
        leftMaxB[0] = b[0];
        for(int i = 1; i< n; i++) {
            leftMaxA[i] = max(a[i], leftMaxA[i-1] + a[i]);
            leftMaxB[i] = max(b[i], leftMaxB[i-1] + b[i]);
        }
        
        vector<ll> rightMaxA(n), rightMaxB(n);
        rightMaxA[n-1] = a[n-1];
        rightMaxB[n-1] = b[n-1];
        for(int i = n-2; i >= 0; i--) {
            rightMaxA[i] = max(a[i], rightMaxA[i+1] + a[i]);
            rightMaxB[i] = max(b[i], rightMaxB[i+1] + b[i]);
        }
        
        ll ans = LLONG_MIN;
        
        int l1 = -1, l2 = -1, r1 =-1, r2 = -1;
        for(int i = 0; i < n; i++) {
            ll sum = leftMaxA[i] + rightMaxA[i] -a[i] + leftMaxB[i] + rightMaxB[i] - b[i];
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
}