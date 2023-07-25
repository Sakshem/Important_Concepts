#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(102, vector<int>(1002, -1));
int knapsack(vector<int>& weight, vector<int>& profit, int capacity, int size) {
    // base condition
    if (size == 0 || capacity == 0) {
        return 0;
    }

    if (weight[size - 1] <= capacity) {
        return max(profit[size - 1] + knapsack(weight, profit, capacity - weight[size - 1], size - 1)
            , knapsack(weight, profit, capacity, size - 1));
    } 
    else {
        return knapsack(weight, profit, capacity, size - 1);
    }
}

int memoizedKnapsack(vector<int>& weight, vector<int>& profit, int capacity, int size) {
    if (size == 0 || capacity == 0) {
        return 0;
    }

    if (dp[size][capacity] != -1) {
        return dp[size][capacity];
    }

    else if (weight[size - 1] <= capacity) {
        dp[size][capacity] = max(profit[size - 1] + memoizedKnapsack(weight, profit, capacity - weight[size - 1], size - 1)
        , memoizedKnapsack(weight, profit, capacity, size - 1));
        return dp[size][capacity];
    }
    else {
        dp[size][capacity] = memoizedKnapsack(weight, profit, capacity, size - 1);
        return dp[size][capacity];
    }
}
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    vector<int> weight = {3, 4, 5, 6};
    vector<int> profit = {2, 3, 1, 4};
    int capacity = 8;
    int size = 4; 
    int maxProfit = knapsack(weight, profit, capacity, size);
    cout << "Max profit is: " << maxProfit << '\n';
    maxProfit = memoizedKnapsack(weight, profit, capacity, size); 
    cout << "Max profit through memoization: " << maxProfit << '\n';
    return 0;
}
