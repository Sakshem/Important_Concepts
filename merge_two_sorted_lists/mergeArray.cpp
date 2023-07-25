#include<bits/stdc++.h>
using namespace std;
int main() {
    auto merge = [&] (vector<int>& a, vector<int>& b) -> vector<int> {
        int i = 0, j = 0;
        vector<int> answer;
        while (i < a.size() || j < b.size()) {
            if (j == b.size() || (i < a.size() && a[i] < b[j])) {
                answer.push_back(a[i++]);
            }
            else {
                answer.push_back(b[j++]);
            }
        }
        return answer;
    };
    auto merge2 = [&] (vector<int>& a, vector<int>& b) -> vector<int> {
        int i = 0, j = 0;
        vector<int> answer;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                answer.push_back(a[i++]);
            } else {
                answer.push_back(b[j++]);
            }
        }
        while (i < a.size()) {
            answer.push_back(a[i++]);
        }
        while (j < b.size()) {
            answer.push_back(b[j++]);
        }
        return answer;
    };

    vector<int> first = {2, 5, 7, 8};
    vector<int> second = {3, 4, 5, 9, 12};
    vector<int> answer = merge2(first, second);
    cout << "after merging array is: " << '\n';
    for (auto i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
