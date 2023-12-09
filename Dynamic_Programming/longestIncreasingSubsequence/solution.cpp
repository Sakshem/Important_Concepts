#include<iostream>
#include<vector>
using namespace std;
int lengthOfLTS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for(int i = 1; i < n; i++) {
	for(int j = 0; j < i; j++) {
	    if(nums[i] > nums[j]) {
		dp[i] = max(dp[i], dp[j] + 1);
	    }
	}
	ans = max(ans, dp[i]);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /* vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18}; */
    /* vector<int> nums = {0, 1, 0, 3, 2, 3}; */
    vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
    cout << lengthOfLTS(nums) << '\n';
    return 0;
}
