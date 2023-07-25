#include <bits/stdc++.h>
using namespace std;
struct jobs
{
    char name;
    int profit;
    int time;
};
bool compare (jobs a, jobs b) {
    return (a.profit > b.profit);
}
void test_case() 
{
    vector<jobs> j = { {'a', 20, 10} , {'b', 15, 2} , {'c', 10, 1} , {'d', 5, 3} , {'e', 1, 3} };
    /*for (int i = 0; i < 5; i++) {
        cout << j[i].name << " " << j[i].profit << " " << j[i].time << '\n';
    }*/
    auto possible_jobs = [&] (vector<jobs>& J) -> void {
        int n = (int) J.size();
        cout << "Size: " << n << '\n';
        sort(J.begin(), J.end(), compare);

        vector<jobs> ans(n);
        bool slot[n] = {false};
        for (int i = 0; i < n; i++) {
            for (int j = min (n, J[i].time) - 1; j >= 0; j--) {
                if (slot[j] == false) {
                    ans[j] = J[i];
                    slot[j] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (slot[i] == true) {
                cout << ans[i].name << " " << ans[i].profit << " " << ans[i].time << '\n';
            }
        }
    };
    possible_jobs(j);
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
