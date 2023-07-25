#include<bits/stdc++.h>
using namespace std;
void test_case() {
    // string s = "abcabcbb";
    string s = "bcbabbcdaefghijkk";
    int n = s.length();
    unordered_set<char> st;
    int left = 0, result = 0;
    for (int right = 0; right < n; right++) {
        while (st.count(s[right])) {
            st.erase(s[left]);
            left++;
        }
        st.insert(s[right]);
        result = max(result, right - left + 1);
    }
    cout << result << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
