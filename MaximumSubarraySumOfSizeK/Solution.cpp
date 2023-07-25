#include<bits/stdc++.h>
using namespace std;
void test_case() {
    vector<int> stockPrice = {1, 2, 7, 7, 4, 3, 6};
    // vector<int> stockPrice = {100, 200, 300, 400};
    int k = 3;
    int i = 0, j = 0, size = stockPrice.size();
    long sum = 0, ans = INT_MIN;
    while (j < size) {
        sum += stockPrice[j];
        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            ans = max(ans, sum);
            sum -= stockPrice[i];
            i++; j++;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
}