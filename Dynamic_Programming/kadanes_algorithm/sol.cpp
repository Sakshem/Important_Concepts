#include<bits/stdc++.h>
using namespace std;
int main() {
    /* int n = 5; */
    /* int a[n] = {1, 2, 3, -2, 5}; */
    // another input
    int n = 4;
    int a[n] = {-1, -2, -3, -4};
    long current = a[0];
    long best = a[0];

    for (int i = 1; i < n; i++) {
	current = max((long)a[i], current + a[i]);
	best = max(best, current);
    }
    cout << best << '\n';
    return 0;
}
