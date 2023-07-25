#include <bits/stdc++.h>
using namespace std;
// to return a hash value for a particular string
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c + 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

// search for duplicate strings in array of strings
vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++) {
        hashes[i] = make_pair(compute_hash(s[i]), i);
    }
    sort(hashes.begin(), hashes.end());
    
    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i - 1].first) {
            groups.emplace_back();
        }
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

int main() 
{

    string str = "hello";
    cout << "hash value for " << str << " is: " << compute_hash(str) << '\n';

    vector<string> s = {"hello", "hi", "how", "are", "you", "doing", "hello", "hi"};
    vector<vector<int>> ans = group_identical_strings(s);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
