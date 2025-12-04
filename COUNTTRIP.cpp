/*

Solution:
|ai - ak| = |i - j| + |j - k|

An important observation, As |ai - ak| < 100, as elements range is [1, 100], we pick k within the radius of 100.

Assuming i < k ( and we can multiply by 2 (for i != k) as they can be swapped)

if j is in between i and k => |ai - ak| = k - i, so if i and k satisfies the condition, it can be picked any index [i, k]

if j is on left, condition becomes |ai - ak| = (i + k) - 2j and |ai - ak| = 2j - (i+k) if it is on right

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        long long ans = n; //As every subarray of size 1 satisfies condition
        for(int i = 1; i <= n; i++) {
            for(int k = i+1; k < min(n+1, i + 100); k++) {
                int val_diff = abs(arr[i] - arr[k]), index_diff = k - i;
                if (val_diff == index_diff) {
                    //If |ai - aj| = |i - k|, we can pick any index in between for j i.e., (k - i + 1) and i and k can be swapped. So multiplied by 2
                    ans += 2*(k - i + 1);
                    continue;
                }
                int temp = (i + k) - val_diff;
                if (temp % 2 == 0) {
                    int jIndexToLeft = temp / 2;
                    if (jIndexToLeft > 0 && jIndexToLeft < i) {
                        ans += 2; //We got one j, but i and k can be swapped
                    }
                    int jIndexToRight = (i + k + val_diff)/ 2;;
                    if (jIndexToRight <= n && jIndexToRight > k) {
                        ans += 2; //We got one j, but i and k can be swapped
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
