#include<bits/stdc++.h>
using namespace std;
void solve() {
    int N; cin >> N;
    int count = 0;
    if (N == 1) {
        cout << "Infinity" << '\n';
        return;
    }
    for (int i = 2; i <= N; ++i) {
        int highest_power = (int) (log(N) / log(i));
        int starting_digit = N / (int) pow(i, highest_power);
        if (starting_digit == 1) {
            ++count;
        }
    }
    cout << "count is: " << count << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
