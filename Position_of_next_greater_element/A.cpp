#include <bits/stdc++.h>
using namespace std;

int main() {
/*Given a list of integers denoting stock prices for respective days, 
for each day we want to know when is the next day when the stock value has gone up
E.g., [9, 30, 46, 47, 14, 40, 57, 26]
Considering days indexed from 1
Days  [1,  2,   3,   4,   5,   6,   7,   8]
Ans   [2,  3,   4,   7,   6,   7,  -1,  -1]*/
    vector<int> stocks = {9, 30, 46, 47, 14, 40, 57, 26};
    vector<int> ans(stocks.size());
    stack<pair<int, int>> st;
    for (int i = 0; i < (int)stocks.size(); i++) {
        if (st.empty()) {
            st.push(make_pair(stocks[i], i));
        }
        else if (st.top().first < stocks[i]) {
            ans[st.top().second] = i;
            st.pop();
            i--;
        }
        else if (st.top().first >= stocks[i]) {
            st.push(make_pair(stocks[i], i));
        }
    }
    while (!st.empty()) {
        //cout << st.top().second << '\n';
        ans[st.top().second] = -1;
        st.pop();
    }
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == -1) {
            cout << ans[i] << ' ';
        }
        else 
            cout << ans[i] + 1 << ' ';
    }
    return 0;
}