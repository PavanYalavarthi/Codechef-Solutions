/*

Problem credits: https://www.codechef.com/problems/DAGXOR

There are N nodes in a circuit. The first N-1 nodes are connected in the form of a rooted tree with root 1. All the leaf nodes of the rooted tree are then connected with node 
N.For each N nodes, you are allowed to select a value among 1,2,3 and 0. You need to calculate the number of possible ways of assigning values to N nodes such that for all the paths from node 
1 to node N have a xor sum equal to 0. The xor sum of a path is the xor of values of all the nodes present in the path.

Note:

Two ways are different if there exists at least one node having different values.
In the path, an edge cannot be visited more than once.
###Input:

First-line contains an integer T, denoting the number of test cases. For each test case:-
First-line will contain one integer N, the number of nodes in the circuit.
Next N-2 lines, each have two integers 
u and v denoting an edge between u and v. This N-2 edges form the rooted tree with N-1 nodes.
*/

/*
Solution:

For given config, we can take any value for all non-leaf nodes and Nth node, and for leaf nodes we take xor of all the rest of nodes there by making total xor to be 0

So, pow(n - (no.of leaf nodes), 4)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int n;
vector<vector<ll>> dp;

// Below function gives number of leaf nodes
ll dfs(int node, int par, vector<int> gr[]) {
    ll ans = 0;
    for(int child: gr[node]) {
        if (child != par) {
            ans += dfs(child, node, gr);
        }
    }
    return ans == 0 ? 1 : ans;
}

long long pow4(long long exp) {
    long long result = 1, base = 4;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) 
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int>gr[n];
        for(int i = 0; i < n - 2; i++) {
            int u, v;
            cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        // Leaves can take Val_of_N ^ (xor of all the node on the top)
        // So, leaf nodes has 1 option and rest of nodes can have any of 4 options.
        int ans = n - dfs(1, 0, gr);
        cout << pow4(ans) << endl;
    }
}
