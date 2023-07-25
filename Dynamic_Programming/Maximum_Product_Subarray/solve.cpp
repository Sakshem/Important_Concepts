#include<bits/stdc++.h>
using namespace std;
long maxProduct(int arr[], int n) {
    int current = 1;
    int best = INT_MIN;

    for (int i = 0; i < n; i++) {
	current *= arr[i];
	best = max(best, current);
	if (current == 0) {
	    current = 1;
	}
    }

    current = 1;

    for (int i = n - 1; i >= 0; i--) {
	current *= arr[i];
	best = max(best, current);
	if (current == 0) {
	    current = 1;
	}
    }

    return best;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 5;
    int arr[] = {6, -3, -10, 0, 2};
    cout << maxProduct(arr, n) << '\n';
    return 0;
}
