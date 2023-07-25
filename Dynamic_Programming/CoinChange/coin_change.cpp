#include<iostream>
using namespace std;
// recursive way
long long int count_recursive(int coins[], int n, int sum) {
    if (sum == 0) return 1;
    if (sum < 0 || n <= 0) return 0;

    return count_recursive(coins, n - 1, sum) + count_recursive(coins, n, sum - coins[n - 1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N = 3, sum = 5;
    int coins[] = {1, 2, 3};
    cout << count_recursive(coins, N, sum) << '\n';
    return 0;
}
