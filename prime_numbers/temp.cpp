#include<bits/stdc++.h>
using namespace std;
bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
void sieve(int64_t num) { //O(nlog(logn));
    vector<bool> is_prime(num + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= num; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= num; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 0; i <= num; i++) {
        if (is_prime[i])
            cout << i << ' ';
    }
}
int search(vector<int>& arr, int low, int high, int key) {
    if (low < high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) {
                return mid;
            }
            else if (arr[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}
int sqrtx(int x) {
    int low = 1, high = x;
    int ans = 0, second = 0;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (mid * mid == x) {
            ans = mid;
            second = mid;
            break;
        }
        else if (mid * mid < x) {
            ans = mid;
            low = mid + 1;
        } else {
            second = mid;
            high = mid - 1;
        }
    }
    cout << ans << ' ' << second << '\n';
    return min(ans, second);
}
void solve(vector<int>& arr) {
    int sum = 0, best = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum = max(arr[i], arr[i] + sum);
        best = max(sum, best);
    }
    cout << best << '\n';
}
int main() {
    // cout << isPrime(18) << '\n';
    // sieve(100);
    // vector<int> arr = {1,2,3,4};
    // cout << search(arr, 0, arr.size() - 1, 1) << '\n';
    // cout << sqrtx(5);
    vector<int> arr = {1,2,3,4};
    solve(arr);
    return 0;
}