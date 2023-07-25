#include<bits/stdc++.h>
using namespace std;
// https://binarysearch.com/problems/Pascal's-Triangle
vector<int> solve(int n) {
    int prev = 1;
    vector<int> ans;
    ans.push_back(prev);
    for (int r = 1; r <= n; r++) {
        int curr = (prev * (n - r + 1))/r;
        ans.push_back(curr);
        prev = curr;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v = solve(4);
    for (auto i : v) cout << i << ' ';
    cout << '\n';
    return 0;
}