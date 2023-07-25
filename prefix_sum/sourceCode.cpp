#include <bits/stdc++.h>
using namespace std;
int main() {
    // prefix sum lambda function
    auto prefSum = [&](vector<int> prefix) -> vector<int> {
        int length = prefix.size();
        if (length < 2) {
            return prefix;
        }
        int temp = prefix[0];
        for (int i = 1; i < length; i++) {
            prefix[i] += temp;
            temp = prefix[i];
        }
        return prefix;
    };
    
    // alternative
    auto pref_sum = [&] (const vector<int>& v) -> vector<int> {
        int length = v.size();
        if (length < 2) {
            return v;
        }
        vector<int> prefix(length);
        prefix[0] = v[0];
        for (int i = 1; i < length; i++) {
            prefix[i] = prefix[i - 1] + v[i];
        }
        return prefix;
   };

    // prefSum 
    vector<int> arr = {7, 8, -1, 2, -4, 9, 10, -14};
    vector<int> prefix = prefSum(arr);
    for (auto i : prefix) { cout << i << ' '; }
    cout << endl;


    // alternative -> pref_sum
    prefix = pref_sum(arr);
    for (auto i : prefix) { cout << i << ' '; }
    cout << endl;
    return 0;
}
