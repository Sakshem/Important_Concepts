#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
void test_case() {
    int n, actualSum, start = 0, currentSum = 0; cin >> n >> actualSum;
    vector<int> A(n); for (auto& i : A) cin >> i;
    vector<int> V;
    for (int i = 0; i < n; i++) {
        currentSum += A[i];
        while (currentSum > actualSum && start < i) {
            currentSum -= A[start++];
        }
        if (currentSum == actualSum) {
            V.push_back(start + 1);
            V.push_back(i + 1);
            cout << "start: " << start + 1 << " end: " << i + 1 << '\n';
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}