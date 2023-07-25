// CPP program to find Fibonacci series numbers
// in a given array.
#include <bits/stdc++.h>
using namespace std;

// Function to check number is a
// perfect square or not
bool isPerfectSquare(int num)
{
	int n = sqrt(num);
	return (n * n == num);
}

// Function to check if the number
// is in Fibonacci or not
int checkFib(int array[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (isPerfectSquare(5 * array[i] * array[i] + 4) || isPerfectSquare(5 * array[i] * array[i] - 4)) {
			//cout << array[i] << " ";
			count++;
		}
	}
	if (count == 0)
		cout << "None present" << endl;

    return count;
}
// my solution!
int checkmyFib(int array[], int n, int max_element) {
    unordered_set<int> st;
    vector<int> dp(max_element + 3);
    dp[0] = 0;
    dp[1] = 1;
    for (long long int i = 1; i < max_element; i++) {
        dp[i + 1] += dp[i];
        dp[i + 2] += dp[i];
    }
    for (int i = 0; i < max_element; i++) {
        st.insert(dp[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (st.find(array[i]) != st.end()) {
            cnt++;
        }
    }
    return cnt;
}
// Driver function
int main()
{
	int array[] = { 4, 2, 8, 5, 20, 1, 40, 13, 23 };
	int n = sizeof(array) / sizeof(array[0]);
	int max_element = INT_MIN;
	for (int i = 0; i < n; i++) {
	    max_element = max(max_element, array[i]);
	}
  	int cnt = checkmyFib(array, n, max_element);
	cout << cnt << '\n';
	cnt = checkFib(array, n);
    cout << cnt << '\n';
	return 0;
}
