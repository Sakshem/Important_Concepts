#include<bits/stdc++.h>
using namespace std;
void test_case() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    unordered_set<char> st;
    for (int i = 0; i < k; i++) {
        char ch; cin >> ch;
        st.insert(ch);
    }
    int possible[n];
    for (int i = 0; i < n; i++) {
        possible[i] = (st.find(s[i]) != st.end()) ? 1 : 0;
    }
    auto calc_substrings = [=] (long long int x) -> long long int{
        return (long long int)(x * (x + 1)) / 2;
    };
    long long int temp = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (possible[i] == 0) {
            ans += calc_substrings((long long int) temp);
            temp = 0;
        }
        else {
            temp++;
        }
    }
    if (temp != 0) {
        ans += calc_substrings(temp);
        temp = 0;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
