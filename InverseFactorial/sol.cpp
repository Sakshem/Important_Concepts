#include<bits/stdc++.h>
using namespace std;
vector<int> memoise(14, -1);
int solve(int a) {
    auto factorial = [&] (int x) -> int64_t {
        if (memoise[x] != -1) {
            return memoise[x];
        }
        int64_t res = 1;
        for (int i = x; i > 1; i--) {
            if (memoise[i] != -1) {
                res *= memoise[i];
                break;
            }
            res *= i;
        }
        memoise[x] = res;
        return res;
    };
    for (int i = 1; i <= 13; i++) {
        int64_t check = factorial(i);
        if (a == check) {
            return i;
        }
        else if (a < check) {
            return -1;
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num; cin >> num;
    cout << solve(num) << '\n';
    // problem statement:
    // Given a positive integer a, return n such that n! = a. If there is no integer n that is a factorial, then return -1.

    return 0;
}
