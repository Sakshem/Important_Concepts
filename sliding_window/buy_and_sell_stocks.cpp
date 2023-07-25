#include<bits/stdc++.h>
using namespace std;
void test_case() {
    vector<int> stocks = {7, 1, 5, 3, 6, 4};
    int n = stocks.size();
    int buy_day = 0, sell_day = 1, maxProfit = 0;
    while (sell_day < n) {
        if (stocks[buy_day] < stocks[sell_day]) {
            int profit = stocks[sell_day] - stocks[buy_day];
            maxProfit = max(maxProfit, profit);
        } else {
            buy_day = sell_day; 
        }
        sell_day++;
    }
    cout << maxProfit << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
