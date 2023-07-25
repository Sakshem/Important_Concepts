#include <bits/stdc++.h>
using namespace std;
void min_max (vector<int>& A, int low, int high, int& min, int& max)
{
    if (low == high) {
        if (max < A[low]) {
            max = A[low];
        }
        if (min > A[high]) {
            min = A[high];
        }
        return;
    }
    if (high - low == 1) {
        if (A[low] < A[high]) {
            if (min > A[low]) {
                min = A[low];
            }
            if (max < A[high]) {
                max = A[high];
            }
        }
        else {
            if (min > A[high]) {
                min = A[high];
            }
            if (max < A[low]) {
                max = A[low];
            }
        }
        return;
    }
    int mid = (low + high) / 2;
    min_max (A, low, mid, min, max);
    min_max (A, mid + 1, high, min, max);
}
int main ()
{
    int n;
    cout << "Enter the size of the array!" << '\n';
    cin >> n;
    vector<int> A(n);
    cout << "Enter the elements in the array!" << '\n';
    for (auto& x : A) cin >> x;

    int max = INT_MIN, min = INT_MAX;
    min_max (A, 0, n - 1, min, max);
    cout << "Min: " << min << '\n';
    cout << "Max: " << max << '\n';
    return 0;
}