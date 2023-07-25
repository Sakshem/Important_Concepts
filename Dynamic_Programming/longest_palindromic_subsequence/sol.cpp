#include<bits/stdc++.h>
using namespace std;
int solve(string s) {
    string a = s;
    string b = s;
    reverse(b.begin(), b.end());
    int alength, blength;
    alength = a.length();
    blength = b.length();
    vector<vector<int>> dp(alength + 1, vector<int>(blength + 1));
    for (int i = 0; i < alength; i++) {
        for (int j = 0; j < blength; j++) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = 1 + dp[i][j];
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[alength][blength];
}
int main() {
    string s = "rbaicneacrayr";
    // racecar is the longest palindrome here!
    cout << solve(s) << '\n';
    return 0;
}
