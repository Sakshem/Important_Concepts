//iterative dp or pull dp
//as it sort of pulls the answer from previos two values.
#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
vector <ll> dp (50);
auto f (ll n) //fibonacci series
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main ()
{
    int n;
    cout << "Enter value upto 50 to find it's fibonacci number: " << '\n';
    cin >> n;
    cout << f (n) << '\n';
    return 0;
}