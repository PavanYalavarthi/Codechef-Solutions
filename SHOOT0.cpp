#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, m;
	    cin >> n >> m;
	    vector<pair<int, long long>>aarsi(m+1), krypto(m+1);
	    aarsi[0] = {0, 0};
	    krypto[0] = {0, 0};
	    for(int i = 1, ele; i <= m; i++) {
	        cin >> ele;
	        bool isAarsi = (ele & 1), isKrypto = ((ele >> 1) & 1);
	        aarsi[i] = {aarsi[i-1].first + isAarsi, aarsi[i-1].second + i * isAarsi};
	        krypto[i] = {krypto[i-1].first + isKrypto, krypto[i-1].second + i * isKrypto };
	    }
	    for(int i = 1; i <= m; i++) {
	        long long leftCount = aarsi[i-1].first, rightCount = aarsi[m].first - aarsi[i].first;	  
	        long long aarsiScore = (leftCount - rightCount) * i 
	                        + (aarsi[m].second - aarsi[i].second) 
	                        - aarsi[i-1].second;
	        leftCount = krypto[i-1].first, rightCount = krypto[m].first - krypto[i].first;
	        long long kryptoScore = (leftCount - rightCount) * i 
	                        + (krypto[m].second - krypto[i].second)
	                        - krypto[i-1].second;
	        cout << llabs(aarsiScore - kryptoScore) << " ";
	    }
	    cout << endl;
	}
}
