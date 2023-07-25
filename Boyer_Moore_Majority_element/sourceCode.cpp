#include <bits/stdc++.h>
using namespace std;
int solve(const vector<int>& nums) {
    int n = nums.size();
    if (n <= 0) return -1;
    if (n == 1) return nums[0];
    int count = 1, majority_element = nums[0];
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            majority_element = nums[i];
            count++;
        }
        else if (nums[i] == majority_element) {
            count++;
        }
        else {
            count--;
        }
    }
    count = 0;
    //To check if the current majority_element is actually the majority element.
    for (int i = 0; i < n; i++) {
        if (nums[i] == majority_element) {
            count++;
        }
    }
    if (count > (n / 2)) return majority_element;
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {5, 5, 1, 1, 2, 2, 2, 2, 2};
    // https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/
    cout << solve(nums) << '\n';
    return 0;
}