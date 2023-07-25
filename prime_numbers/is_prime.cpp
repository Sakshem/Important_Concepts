#include <bits/stdc++.h>
using namespace std;
int main()
{
    auto is_prime = [&] (int x) -> bool {
        for (int i = 2; i * i <= x; i++) {
            if (x % i) return false;
        }
        return true;
    };
    return 0;
}
