#include <bits/stdc++.h>
using namespace std;
int count_unique_substrings(string const& s) {
    int n = s.size();
    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        set<long long> hs;
        for (int i = 0; i <= n - 1; i++) {
            long long cur_h = (h[i + 1] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n - i - 1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "aab";
    cout << count_unique_substrings(s) << '\n';
    return 0;
}
