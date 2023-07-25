// refer gfg: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1?page=1&category[]=Dynamic%20Programming&sortBy=submissions
#include<iostream>
using namespace std;
long long trapping_water(int arr[], int n) {
    int leftMax[n], rightMax[n];
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++) {
	leftMax[i] = max(leftMax[i - 1], arr[i]);
    }
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
	rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    long long water = 0;
    for (int i = 0; i < n; i++) {
	int water_level = min(leftMax[i], rightMax[i]);
	water += water_level - arr[i];
    }
    return water;
}
int main() {
    // input 1:
    int n = 6;
    int arr[] = {3, 0, 0, 2, 0, 4};

    // input 2: 
    // int n = 4;
    // int arr[] = {7, 4, 0, 9};

    // input 3:
    // int n = 3;
    // int arr[] = {6, 9, 9};
    cout << trapping_water(arr, n) << '\n';
    return 0;
}
