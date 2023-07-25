#include<bits/stdc++.h>
using namespace std;
int iterativeKnapsack(vector<int>& weight, vector<int>& profit, int capacity, int size) {
    int dp[size + 1][capacity + 1];
    // base condition
    for (int i = 0; i <= size; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= capacity; j++) {
        dp[0][j] = 0;
    }
    
    //choices condition
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weight[i - 1] <= j) {
                dp[i][j] = max(profit[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= size; i++) {
	for (int j = 0; j <= capacity; j++) {
	    cout << "dp[" << i << "]" << "[" << j << "]: " << dp[i][j] << ' ';
	}
	cout << '\n';
    }
    return dp[size][capacity];
}
int main() {
    /* ios_base::sync_with_stdio(false); */
    /* cin.tie(nullptr); */
    vector<int> weight = {3, 4, 5, 6};
    vector<int> profit = {2, 3, 1, 4};
    int capacity = 8;
    int size = 4; 
    cout << "max profit is: " << iterativeKnapsack(weight, profit, capacity, size);
}
