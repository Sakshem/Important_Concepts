#include<iostream>
#include<vector>
using namespace std;
/* int64_t factorial(int x, vector<int64_t>& cached) { */
/*     if (cached[x] != 1) { */
/* 	return cached[x]; */
/*     } */
/*     for (int i = 2; i <= x; i++) { */
/* 	cached[i] = cached[i - 1] * i; */
/*     } */
/*     return cached[x]; */
/* } */
int nCr(int n, int r) {
    if (r > n) return 0;
    if (n == r || r == 0 || n == 0) return 1;

    if (r > (n - r)) r = n - r;
    int MOD = 1e9 + 7;
    vector<int> dp(r + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--) {
	    dp[j] = (dp[j] + dp[j - 1]) % MOD;
	}
    }
    return dp[r];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r; cin >> n >> r;
    cout << nCr(n, r) << '\n';
    return 0;
}
