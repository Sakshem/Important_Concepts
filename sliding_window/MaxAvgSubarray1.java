package ImpConcepts.sliding_window;
public class MaxAvgSubarray1 {
    public static double findMaxAverage(int[] nums, int k) {
        int maxSum = 0;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        maxSum = sum;
        for (int i = k; i < nums.length; i++) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = Math.max(maxSum, sum);
        }
        return (double) maxSum / k;
    }
    public static void main(String[] args) {
        int[] nums = {1,12,-5,-6,50,3};
        int k = 4;
        findMaxAverage(nums, k);
    }
}