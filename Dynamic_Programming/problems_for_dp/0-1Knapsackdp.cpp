// https://binarysearch.com/problems/0-1-Knapsack
/* problem statement - 
You are given two lists of integers weights and values which have the same length and an integer capacity. 
weights[i] and values[i] represent the weight and value of the ith item.
Given that you can take at most capacity weights, and that you can only take at most one copy of each item,
return the maximum amount of value you can get. */
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size(); // since weights and values have same size.
    int m = capacity;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j - weights[i - 1] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}
int main() {
    vector<int> weights = {1, 2, 3};
    vector<int> values = {1, 5, 3};
    // Other sample case:
    // weights = {2, 3, 4, 5};
    // values = {1, 2, 5, 6};
    int capacity = 5;
    cout << solve(weights, values, capacity) << '\n';
}
