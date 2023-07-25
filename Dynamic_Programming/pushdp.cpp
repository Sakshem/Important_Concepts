//push dp
#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
vector <ll> dp (50);
auto f (ll n)
{
    dp[0] = 0;
    dp[1] = 1;
    //here we can ignore i = 0 since it's value is 0 anyway
    //that's why we start the loop with 1.
    for (ll i = 1; i < n; i++) {
        dp[i + 1] += dp[i];
        dp[i + 2] += dp[i];
    }
    return dp[n];
}
int main ()
{
    //since we know how fibonacci series works
    //we can say that for f(n) = f(n - 1) + f(n - 2) (for n >= 2)
    //so previously in memoization and pull dp methods 
    //we said that f(n) values relies on f(n - 1) and f(n - 2)
    //but in push dp we say that f(n) value contributes to f(n + 1) and f(n + 2)
    //so in other words it looks like:
    //f(0), f(1), f(2), f(3), f(4), f(5)...
    //we can say that f(1) contributes to the value of f(2) and f(3).
    //as when we find value of f(2) we will find value of f(1) and f(0)
    //like we did in memoization technique.
    //so in push dp we think of that each value will contribute to some other value in future.
    int n;
    cin >> n;
    cout << f (n) << '\n';
    return 0;
}
