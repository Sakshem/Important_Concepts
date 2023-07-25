//https://binarysearch.com/problems/Longest-Distinct-Sublist
#include <bits/stdc++.h>
using namespace std;
int length_of_longest_distinct_sublist(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int i = 0, j = 0;
    unordered_map<int, int> mp;
    mp[nums[i]]++;
    int ans = 1;
    while (j < n - 1) {
        if (mp[nums[j + 1]] == 0) {
            j++;
            mp[nums[j]]++;
            ans = max(ans, j - i + 1);
        }
        else {
            mp[nums[i]]--;
            i++;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {5, 1, 3, 5, 2, 3, 4, 1};
    cout << length_of_longest_distinct_sublist(nums) << '\n';
    return 0;
}