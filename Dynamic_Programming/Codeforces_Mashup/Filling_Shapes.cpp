#include<bits/stdc++.h>
using namespace std;
void using_maths() {
    // solution without DP, using just maths
    int n; cin >> n;
    if (n % 2 != 0) cout << 0 << '\n';
    else {
        cout << (long long) pow(2, n/2) << '\n';
    }
}
void using_dp() {
    // solution using DP

    // base case: f(0) = 0, f(1) = 0, f(2) = 2, f(3) = 0, f(4) = f(2) * 2, f(5) = 0, f(6) = f(4) * 2
    // state: f(n) = (n % 2 == 0) ? f(n - 2) * 2 : 0
    int n; cin >> n;
    long long int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (i % 2 == 0 ? dp[i - 2] * 2 : 0);
    }
    cout << dp[n] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // using_maths();
    using_dp();
    return 0;
}
