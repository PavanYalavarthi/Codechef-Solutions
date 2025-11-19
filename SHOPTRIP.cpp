/*

Problme description: https://www.codechef.com/problems/SHOPTRIP/

Bear Limak is an assistant in the kitchen. While he doesn't really know how to cook, he can run very fast and thus Chef often sends him to buy new ingredients from shops.

Chef needs K different ingredients, numbered 1 through K.

The kitchen is located at the point (0, 0). There are N shops. The i-th shop is located at the point (Xi, Yi) and its inventory is described by the string si of length K. The i-th character of si is '1' if the i-th ingredient is available in this shop, and '0' otherwise.

All N+1 points are distinct (the kitchen and the N shops).

Limak must start from the kitchen, visit some shops and buy all necessary ingredients (each of K ingredients should be available in at least one visited shop), and go back to the kitchen. What is the minimum total distance Limak will cover? Print -1 if it's impossible to get all the ingredients.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains two integers N and K denoting the number of shops and the number of ingredients.

The i-th of the next N lines contains two integers xi and yi denoting coordinates of the i-th shop. No two shops are at the same point, and no shop is at the point (0, 0).

The i-th of the next N lines contains a string si of length K, consisting of characters '1' and '0'. The j-th character is '1' if and only if the j-th ingredient is available in this shop.

Output
For each test case, output a single line containing the answer: a number -1 if Limak can't get all K ingredients, or one real value otherwise — the minimum total distance. The relative or absolute error shouldn't exceed 10-6.

#bit_masking_dp
*/

/*
Solution:

If ORing all the ingredient masks, doesnt set the bits, there is no solution.

else like TSP problem, check whether picking currrent index adds any ingredient. if yes set the bit and recurse on them.
*/

#include <bits/stdc++.h>
using namespace std;
int final_mask;

double distance(pair<int, int>& p1, pair<int, int>& p2) {
    int dx = p1.first - p2.first, dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

double helper(vector<vector<double>>& dist, vector<int>& ingredients, int mask, int index, vector<vector<double>>& dp) {
    if(mask == final_mask) return dist[index][0];
    if (dp[mask][index] != -1) return dp[mask][index];
    double ans = numeric_limits<double>::max();
    for(int i = 1; i < dist.size(); i++) {
        if ((mask | ingredients[i]) != mask) { // picking currrent index adds some ingredient
            ans = min(ans, dist[index][i] + helper(dist, ingredients, mask | ingredients[i], i, dp));
        }   
    }
    return dp[mask][index] = ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        final_mask =  (1 << k) -1;
        vector<pair<int, int>>v(n + 1);
        vector<int>ingredients(n + 1);
        v[0].first = v[0].second = 0;
        for(int i = 1; i <= n; i++) 
            cin >> v[i].first >> v[i].second;
        int temp = 0;
        ingredients[0] = 0;
        for(int i = 1; i <= n; i++) {
            string tmp;
            cin >> tmp;
            int ans = 0;
            for(int j = 0; j < k; j++) {
                if (tmp[j] == '1')
                    ans |= (1<<(k - j -1));
            }
            temp |= ingredients[i] = ans;
        }
        if (temp != final_mask ){
           cout << -1 << endl; 
        } else {
            vector<vector<double>>dist(n+1, vector<double>(n+1));
            for(int i = 0; i <= n ;i++) {
                for(int j = i; j <= n; j++) {
                    if (i == j) dist[i][j] = 0;
                    else dist[i][j] = dist[j][i] = distance(v[i], v[j]);
                }
            }
            vector<vector<double>> dp (1 << k, vector<double>(n + 1, -1));
            printf("%.10f\n", helper(dist, ingredients, 0, 0, dp));
        }
    }
}
