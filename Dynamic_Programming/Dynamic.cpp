#include<bits/stdc++.h>
using namespace std;
vector<long long int> cached(100, -1);
long long int fib(long long int n) {
    if (n < 2) {
	return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
long long int fast_fib(long long int n) {
    long long int a = 1, b = 1;
    for (int i = 2; i <= n; i++) {
	long long int temp = a;
	a = b;
	b = temp + b;
    }
    return b;
}

long long int memoized_fib(long long int n) {
    if (n < 2) {
	return 1;
    }
    if (cached[n] == -1) {
	cached[n] = memoized_fib(n - 1) + memoized_fib(n - 2);
    }
    return cached[n];
}
int main() {
    // fib takes few seconds longer to complete where as fast_fib is instant
    cout << "fast_fib: " << fast_fib(45) << '\n';
    cout << "memoized_fib: " << memoized_fib(45) << '\n';
    cout << "fib: " << fib(45) << '\n';
    return 0;
}

