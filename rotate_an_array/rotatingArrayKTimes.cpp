#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();
    auto rev = [&] (int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
    };
    int k = 2; // doing a right rotation k times
    rev(0, n - 1);
    rev(0, k - 1);
    rev(k, n - 1);
    cout << "elements after right rotation K times: " << '\n';
    for (auto& i : nums) {
        cout << i << ' ';
    }
    return 0;
}
