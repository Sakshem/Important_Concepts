//iterative dp or pull dp
//as it sort of pulls the answer from previos two values.
#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
vector <ll> dp (50); //vector that contains values in fibonacci series. 
auto f (ll n) //function for finding fibonacci series upto n.
{
    dp[0] = 0;
    dp[1] = 1;
    for (ll i = 2; i <= n; i++) {
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
