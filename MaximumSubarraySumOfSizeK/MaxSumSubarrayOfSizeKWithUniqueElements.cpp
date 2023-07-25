#include<bits/stdc++.h>
using namespace std;
void test_case() {
    vector<int> stockPrice = {1, 2, 7, 7, 4, 3, 5, 3, 8};
    // vector<int> stockPrice = {100, 200, 300, 400};
    int k = 4;
    int i = 0, j = 0, size = stockPrice.size();
    long sum = 0, ans = -1;
    unordered_set<int> st;
    bool flag = false;
    int repeatedNumber = 0;
    while (j < size) {
        sum += stockPrice[j];
        if (st.find(stockPrice[j]) != st.end()) {
            repeatedNumber = stockPrice[j];
            flag = true;
        } else {
            st.insert(stockPrice[j]);
        }
        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            if (!flag) {
                ans = max(ans, sum);
            }
            sum -= stockPrice[i];
            if (stockPrice[i] == repeatedNumber) {
                flag = false;
            }
            st.erase(stockPrice[i]);
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