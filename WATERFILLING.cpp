#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
	    int count =0;
	    for(int i =0,ele;i<3;i++) {
	        cin >> ele;
	        count+=ele;
	    }
	    cout << (count <= 1 ? "Water filling time\n" : "Not now\n");
    }
}
